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
bool JsonManager::isOperation(char symbol){
    return symbol =='+' || symbol =='-';
}
bool JsonManager::isDigit(char symbol) {
    return symbol >='1' && symbol <= '9';
}
char JsonManager::whichOperation(char symbol){
    if(symbol =='+') {
        symbol = '+';
        return symbol;
    }
    symbol = '-';
    return symbol;
}
double JsonManager::getNumber(char symbol,stringstream& jsonStream){
    stringstream parsingStream;
    if(!isDigit(symbol)){
        if(isOperation(symbol)){
            symbol = jsonStream.get();
        }
        else
        throw "After '-' is not a digit";
    }
    if(isOperation(symbol) || !isDigit(symbol)){
        throw "Double operations scanned";
    }
    do{
        if(symbol =='.') {
            parsingStream << symbol;
            symbol = jsonStream.get();
            if(!isDigit(symbol)){
                throw "After '.' is not a number";
            }
            parsingStream << symbol;
            symbol = jsonStream.get();
            continue;
        }
        parsingStream << symbol;
        symbol = jsonStream.get();
    }
    while (isDigit(symbol) || symbol == '.');
    if(symbol != ','){
        throw "After the number there must be ',' ";
    }
    symbol = jsonStream.get();
    if (!isWhiteSpace(symbol)) {
        throw "After ',' there must be whitespace or \" ";
    }
    readWhitespace(jsonStream);
    symbol = jsonStream.get();
    double returnedNum = 0;
    parsingStream >> returnedNum;
    return returnedNum;
}
double JsonManager::geteNumber(char symbol, stringstream& jsonStream){
    double eNum = 2.72;
    if (symbol != 'e'){
        throw " Expected to be 'e' ";
    }
    symbol = jsonStream.get();
    if(!isOperation(symbol)){
        if(isDigit(symbol)){
            double directlyAfterE = getNumber(symbol,jsonStream);
            return eNum * directlyAfterE;
        }
        throw "After 'e' there must be a operation";
    }
    char operation = whichOperation(symbol);
    double temp = getNumber(symbol,jsonStream);
    if(operation == '+'){
        return eNum + temp;
    }
    else {
        return eNum - temp;
    }

}
JsonValue* JsonManager::readDigit(char symbol,stringstream& jsonStream) {
    if(isDigit(symbol)){
        double numValue = getNumber(symbol,jsonStream);
        return new JsonNumber(numValue);
        }
//    else if(isDigitSomethingElse(symbol)){
//        return new JsonNumber(//from a function);
//    }

}
bool JsonManager::isWhiteSpace(char symbol) {
    string whitespaces = " \n\r\t";
    return whitespaces.find(symbol) != string::npos;
}
void JsonManager::readWhitespace(stringstream &jsonStream){
    while (isWhiteSpace(jsonStream.peek())) {
        jsonStream.get();
    }
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
JsonArray* JsonManager::readArray(stringstream& jsonStream) {
    char symbol = jsonStream.get();
    if (symbol == ']'){
        return new JsonArray();
    }
    vector<JsonValue*> arrayValue;
    if(symbol == ' '){
        readWhitespace(jsonStream);
        symbol = jsonStream.get();
    }
    do {
        if (symbol == ','){
            readWhitespace(jsonStream);
            symbol = jsonStream.get();

        }
        arrayValue.push_back(readValue(jsonStream,symbol));
        symbol = jsonStream.get();
    }
    while(symbol == ',');
    if(isWhiteSpace(symbol)){
        readWhitespace(jsonStream);
        symbol = jsonStream.get();
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
        case '-':{
            symbol = jsonStream.get();
            return readDigit(symbol,jsonStream);
        }
        case 'e':{
            break;
        }
        case 'E':{
            break;
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
    readWhitespace(jsonStream);
    char symbol = jsonStream.get();
    unordered_map<string, JsonValue*> map;
    string key,keyValue;
    if(symbol == '"') {
        do {
            if(symbol == ',') {
                readWhitespace(jsonStream);
                symbol = jsonStream.get();
                if(symbol != '"'){
                    throw "Unexpected character";
                }
            }
            key = readString(jsonStream);

            readWhitespace(jsonStream);
            symbol = jsonStream.get();

            if (symbol != ':') {
                throw "Expected ':' ";
            }

            readWhitespace(jsonStream);
            symbol = jsonStream.get();

            map[key] = readValue(jsonStream, symbol);
            symbol = jsonStream.get();

        }
        while(symbol == ',');
        if(isWhiteSpace(symbol)) {
            readWhitespace(jsonStream);
            symbol = jsonStream.get();
        }
    }
    if(symbol != '}'){
        throw " Expected '}' ";
    }
    return new JsonObject(map);
}

JsonValue* JsonManager::readJson(stringstream& jsonStream) {
    readWhitespace(jsonStream);
    char symbol = jsonStream.get();
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