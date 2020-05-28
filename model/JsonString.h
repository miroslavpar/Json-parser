//
// Created by Miroslav Parapanov on 2020-03-30.
//

#ifndef JSON_PARSER_JSONSTRING_H
#define JSON_PARSER_JSONSTRING_H

#include "JsonValue.h"

class JsonString : public JsonValue{
private:
    string value;
public:
    JsonString();
    explicit JsonString(string&);
    void print()const;
    Type getType()const;
    void set(string&);
    string getValueFromJsonString()const;
    void write(ofstream&)const;
};

#endif //JSON_PARSER_JSONSTRING_H
