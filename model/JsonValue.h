//
// Created by Miroslav Parapanov on 2020-03-31.
//

#ifndef JSON_PARSER_JSONVALUE_H
#define JSON_PARSER_JSONVALUE_H
#include <iostream>
#include <string>;
using namespace std;
class JsonValue{
public:
    virtual void print() = 0;
    virtual void searchFromKey(string&) = 0;
    virtual void printJustValue() = 0;
};
#endif //JSON_PARSER_JSONVALUE_H
