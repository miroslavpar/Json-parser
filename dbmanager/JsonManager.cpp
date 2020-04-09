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
#include <string>
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
JsonValue* JsonManager::readNumber(stringstream& jsonStream) {
    char symbol = jsonStream.get();
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
    if(jsonStream.get() != '"'){
        throw "It's not starting with \" ";
    }
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
    if(symbol != '['){
        throw " It's not starting with '[' ";
    }
    readWhitespace(jsonStream);
    symbol = jsonStream.peek();
    if (symbol == ']'){
        jsonStream.get();
        return new JsonArray();
    }
    vector<JsonValue*> arrayValue;

    do {
        arrayValue.push_back(readValue(jsonStream));
        symbol = jsonStream.get();
    }
    while(symbol == ',');

    if(symbol != ']'){
        throw "Expected : ']'";
    }
    return new JsonArray(arrayValue);
}
bool JsonManager::readLiteral(stringstream& jsonStream, const string& exp){
    char buffer[exp.size()];
    jsonStream.read(buffer, exp.size());
    return exp == buffer;
}
JsonValue* JsonManager::readValue(stringstream& jsonStream) {
    readWhitespace(jsonStream);
    JsonValue* value;
    switch (jsonStream.peek()) {
        case '{' :
            value = readObject(jsonStream);
            break;
        case '[' :
            value = readArray(jsonStream);
            break;
        case '"' : {
            string keyValue = readString(jsonStream);
            value = new JsonString(keyValue);
            break;
        }
        case 'n':{
            if (!readLiteral(jsonStream, "null"))
                throw "Expected to be : null ";
            value = nullptr;
            break;
        }
        case 't':{
            if (!readLiteral(jsonStream, "true")){
                throw"Expected to be : true ";
            }
            value = new JsonBoolean(true);
            break;
        }
        case 'f': {
            if (!readLiteral(jsonStream, "false")) {
                throw "Expected to be : false ";
            }
            value = new JsonBoolean(false);
            break;
        }
        case '-':{
            value = readNumber(jsonStream);
            break;
        }
        case '0':{
            value =  readNumber(jsonStream);
            break;
        }
        default: throw "Unexpected Value" ;
    }
    readWhitespace(jsonStream);
    return value;
}

JsonObject* JsonManager::readObject(stringstream& jsonStream) {
    readWhitespace(jsonStream);
    char symbol = jsonStream.get();
    if(symbol != '{'){
        throw "It's not '{' ";
    }
    readWhitespace(jsonStream);
    symbol = jsonStream.peek();
    unordered_map<string, JsonValue*> map;
    string key,keyValue;
    if(symbol == '"') {
        do {
            readWhitespace(jsonStream);

            key = readString(jsonStream);

            readWhitespace(jsonStream);
            symbol = jsonStream.get();

            if (symbol != ':') {
                throw "Expected ':' ";
            }

            map[key] = readValue(jsonStream);
            symbol = jsonStream.get();
        }
        while(symbol == ',');
    }
    if(symbol != '}'){
        throw " Expected '}' ";
    }
    return new JsonObject(map);
}

JsonValue* JsonManager::readJson(stringstream& jsonStream) {
    readWhitespace(jsonStream);
    char symbol = jsonStream.peek();
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