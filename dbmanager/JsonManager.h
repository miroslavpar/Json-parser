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
    string dbFile;
    stringstream jsonInfo;
    bool isFileOpened;
private:
    //The main functionality :
    JsonArray* readArray (stringstream&);
    JsonValue* readValue (stringstream&);
    JsonObject* readObject(stringstream&);
    string readString(stringstream&);
    JsonValue* readNumber(stringstream&);
    JsonValue* readJson(stringstream&);

private:
    // Helping functions:
    void readWhitespace(stringstream&);
    bool isWhiteSpace(char);
    bool isOperation(char);
    bool isDigit(char);
    bool readLiteral(stringstream&,const string&);
    double geteNumber(char, stringstream&);
    double getNumber(char,stringstream&);
    bool getIsFileOpened();
public:
    JsonManager();
    void openFile(string&);
    bool validateJsonFile();
    void print();
    void search(string&);
    void help();
    void closeFile();
};


#endif //JSON_PARSER_JSONMANAGER_H
