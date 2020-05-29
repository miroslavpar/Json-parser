//
// Created by Miroslav Parapanov on 2020-03-31.
//

#ifndef JSON_PARSER_JSONVALUE_H
#define JSON_PARSER_JSONVALUE_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
enum Type{
    JSONOBJECT,
    JSONARRAY,
    JSONSTRING,
    JSONBOOLEAN,
    JSONNUMBER
};
class JsonValue{
protected:
    Type type;
public:
    virtual void print()const = 0;
    virtual void searchFromKey(const string&)const {};
    virtual Type getType()const = 0;
    virtual string getValueFromJsonString()const {};
    virtual bool getValueFromJsonBoolean()const {};
    virtual double getValueFromJsonNumber()const {};
    virtual void write(ofstream&)const = 0;
    virtual void deleteByKey(const string&){};
};
#endif //JSON_PARSER_JSONVALUE_H
