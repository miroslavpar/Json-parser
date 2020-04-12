//
// Created by Miroslav Parapanov on 2020-03-30.
//

#ifndef JSON_PARSER_JSONMANAGER_H
#define JSON_PARSER_JSONMANAGER_H

#include <fstream>
#include <sstream>
#include "../model/JsonValue.h"
#include "../model/JsonArray.h"
#include "../model/JsonObject.h"

using namespace std;
class JsonManager {
private:
    const string dbFile;

    //The main functionality :
    JsonArray* readArray (stringstream&);
    JsonValue* readValue (stringstream&);
    JsonObject* readObject(stringstream&);
    string readString(stringstream&);
    JsonValue* readNumber(stringstream&);
    JsonValue* readJson(stringstream&);


    // Helping functions:
    void readWhitespace(stringstream&);
    bool isWhiteSpace(char);
    bool isOperation(char);
    bool isDigit(char);
    bool readLiteral(stringstream&,const string&);
    stringstream openFile();
    double geteNumber(char, stringstream&);
    double getNumber(char,stringstream&);
public:
    JsonManager(const string&);
    bool validateJsonFile();
    void print();
    void search(string&);
};


#endif //JSON_PARSER_JSONMANAGER_H
