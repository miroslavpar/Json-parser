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
    JsonValue* readValue (stringstream&,char);
    bool isDigit(char);
    JsonObject* readObject(stringstream&);
    string readString(stringstream&);
    char readWhitespace(stringstream&);
    bool isWhiteSpace(char);
public:
    void validateJsonFile();
    JsonValue* readJson(stringstream&);

};


#endif //JSON_PARSER_JSONMANAGER_H
