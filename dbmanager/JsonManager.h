//
// Created by Miroslav Parapanov on 2020-03-30.
//

#ifndef JSON_PARSER_JSONMANAGER_H
#define JSON_PARSER_JSONMANAGER_H

#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "../model/JsonValue.h"
#include "../model/JsonArray.h"
#include "../model/JsonObject.h"

using namespace std;
class JsonManager {
private:
    const string dbFile;


    JsonArray* readArray (stringstream&);
    JsonValue* readValue (stringstream&);
    JsonObject* readObject(stringstream&);
    string readString(stringstream&);
    JsonValue* readNumber(stringstream&);

// Helping functions:
    void readWhitespace(stringstream&);
    bool isWhiteSpace(char);
    bool isOperation(char);
    bool isDigit(char);
    bool readLiteral(stringstream&,const string&);


public:double geteNumber(char, stringstream&);
    double getNumber(char,stringstream&);


public:
    void validateJsonFile();
    JsonValue* readJson(stringstream&);

};


#endif //JSON_PARSER_JSONMANAGER_H
