//
// Created by Miroslav Parapanov on 2020-03-31.
//

#ifndef JSON_PARSER_JSONOBJECT_H
#define JSON_PARSER_JSONOBJECT_H

#include "JsonValue.h"
#include <unordered_map>
#include <stack>


class JsonObject : public JsonValue {
private:
    unordered_map<string,JsonValue*> properties;
public:
    JsonObject(unordered_map<string,JsonValue*>&);
    void searchFromKey(string& );
    void printJustValue();
    void print();
};
#endif //JSON_PARSER_JSONOBJECT_H
