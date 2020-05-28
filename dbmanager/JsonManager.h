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
    JsonObject* workingJson;
private:
    //The main functionality :
    JsonArray* readArray (stringstream&)const;
    JsonValue* readValue (stringstream&)const;
    JsonObject* readObject(stringstream&)const;
    string readString(stringstream&)const;
    JsonValue* readNumber(stringstream&)const;
    JsonValue* readJson(stringstream&)const;

private:
    // Helping functions:
    void readWhitespace(stringstream&)const;
    bool isWhiteSpace(char)const;
    bool isOperation(char)const;
    bool isDigit(char)const;
    bool readLiteral(stringstream&,const string&)const;
    double geteNumber(char, stringstream&)const;
    double getNumber(char,stringstream&)const;
public:
    JsonManager();
    void openFile(string&);
    bool validateJsonFile();
    void print();
    void search(const string&);
    void help() const;
    void closeFile();
    void save();
    void saveAs(const string&);
    void exitFromFunction()const;
    void set(const string&, stringstream&);
    void deleteByPath(const string&);
};


#endif //JSON_PARSER_JSONMANAGER_H
