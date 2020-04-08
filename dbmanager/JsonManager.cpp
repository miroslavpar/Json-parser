//
// Created by Miroslav Parapanov on 2020-03-30.
//

#include "JsonManager.h"
#include "../model/JsonString.h"
#include "../model/JsonObject.h"
#include "../model/JsonBoolean.h"
#include "../model/JsonNumber.h"
#include <iostream>
#include <set>
#include <vector>
using namespace std;
bool JsonManager::isWhiteSpace(char symbol) {
    string whitespaces = " \n\r\t";
    return whitespaces.find(symbol) != string::npos;
}
char JsonManager::readWhitespace(stringstream &jsonStream){
    string whitespaceChars = " \n\r\t";
    char symbol = jsonStream.get();
    while (whitespaceChars.find(symbol) != string::npos) {
        symbol = jsonStream.get();
    }
    return symbol;
}

string JsonManager::readString(stringstream& jsonStream) {
    char symbol = jsonStream.get();
    vector<char> key;
    while (symbol != '"') {
        key.push_back(symbol);
        symbol = jsonStream.get();
    }
    return string(key.begin(),key.end());
}
bool JsonManager::isDigit(char symbol) {
    if(symbol > '0' && symbol < '9')
        return symbol;
}
JsonArray* JsonManager::readArray(stringstream& jsonStream) {
    char symbol = jsonStream.get();
    if (symbol == ']'){
        return new JsonArray();
    }
    vector<JsonValue*> arrayValue;
    if(symbol == ' ')symbol = readWhitespace(jsonStream);
    do {
        if (symbol == ','){
            symbol = readWhitespace(jsonStream);
        }
        arrayValue.push_back(readValue(jsonStream,symbol));
        symbol = jsonStream.get();
    }
    while(symbol == ',');
    if(isWhiteSpace(symbol)){
        symbol = readWhitespace(jsonStream);
    }
    if(symbol != ']'){
        throw "Expected : ']'";
    }
    return new JsonArray(arrayValue);
}
JsonValue* JsonManager::readValue(stringstream& jsonStream, char symbol) {
    switch (symbol) {
        case '{' :
            return readObject(jsonStream);
        case '[' :
            return readArray(jsonStream);
        case '"' : {
            string keyValue = readString(jsonStream);
            return new JsonString(keyValue);
        }
        case 'n':{
            if (jsonStream.get() != 'u' || jsonStream.get() != 'l' || jsonStream.get() != 'l')
                throw "Expected to be : null ";
            return nullptr;
        }
        case 't':{
            if (jsonStream.get() != 'r' || jsonStream.get() != 'u' || jsonStream.get() != 'e'){
                throw"Expected to be : true ";
            }
            return new JsonBoolean(true);
        }
        case 'f': {
            if (jsonStream.get() != 'a' || jsonStream.get() != 'l' || jsonStream.get() != 's' || jsonStream.get() != 'e') {
                throw "Expected to be : false ";
            }
            return new JsonBoolean(false);
        }
        default: {
            if (isDigit(symbol)){
                return new JsonNumber((double)symbol - '0');
            }
            else {
                throw "Unexpected Value" ;
            }
        }
    }
}

JsonObject* JsonManager::readObject(stringstream& jsonStream) {
    char symbol = readWhitespace(jsonStream);
    unordered_map<string, JsonValue*> map;
    string key,keyValue;
    if(symbol == '"') {
        do {
            if(symbol == ',') {
                symbol = readWhitespace(jsonStream);
                if(symbol != '"'){
                    throw "Unexpected character";
                }
            }
            key = readString(jsonStream);

            symbol = readWhitespace(jsonStream);

            if (symbol != ':') {
                throw "Expected ':' ";
            }

            symbol = readWhitespace(jsonStream);

            map[key] = readValue(jsonStream, symbol);
            symbol = jsonStream.get();

        }
        while(symbol == ',');
        if(isWhiteSpace(symbol)) {
            symbol = readWhitespace(jsonStream);
        }
    }
    if(symbol != '}'){
        throw " Expected '}' ";
    }
    return new JsonObject(map);
}

JsonValue* JsonManager::readJson(stringstream& jsonStream) {
    char symbol = readWhitespace(jsonStream);
    switch (symbol) {
        case '{' :
            return readObject(jsonStream);
        case '[':
            return readArray(jsonStream);
        default: throw " Unexpected character occured !";
    }
}
void JsonManager::validateJsonFile(){

}