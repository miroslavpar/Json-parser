//
// Created by Miroslav Parapanov on 2020-03-30.
//

#ifndef JSON_PARSER_JSONSTRING_H
#define JSON_PARSER_JSONSTRING_H

#include "JsonValue.h"

class JsonString : public JsonValue{
private:
    std::string value;
public:
    JsonString(std::string&);
    void searchFromKey(string&);
    void printJustValue();
    void print();
};

#endif //JSON_PARSER_JSONSTRING_H
