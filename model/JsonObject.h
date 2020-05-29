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
    JsonObject();
    explicit JsonObject(unordered_map<string,JsonValue*>&);
    void searchFromKey(const string&)const;
    void print()const;
    bool checkKeyByString(const string&)const;
    void set(const string&, JsonValue*);
    Type getType()const;
    JsonValue* getSecondPropertyByKey(const string&)const;
    void write(ofstream&)const;
    void deleteByKey(const string&);
    void insertValue(pair<string,JsonValue*>);
};
#endif //JSON_PARSER_JSONOBJECT_H
