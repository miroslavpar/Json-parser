//
// Created by Miroslav Parapanov on 2020-03-31.
//

#ifndef JSON_PARSER_JSONNUMBER_H
#define JSON_PARSER_JSONNUMBER_H

#include "JsonValue.h"
class JsonNumber : public JsonValue {
private:
    double num;
public:
    JsonNumber(double);
    void searchFromKey(string& );
    void printJustValue();
    void print();
};
#endif //JSON_PARSER_JSONNUMBER_H
