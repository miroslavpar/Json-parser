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
    explicit JsonNumber(double);
    JsonNumber();
    void print()const;
    Type getType()const;
    void set(double);
    double getValueFromJsonNumber()const;
    void write(ofstream&)const;
};
#endif //JSON_PARSER_JSONNUMBER_H
