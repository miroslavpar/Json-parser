//
// Created by Miroslav Parapanov on 2020-03-30.
//

#ifndef JSON_PARSER_JSONSTRING_H
#define JSON_PARSER_JSONSTRING_H
#include <string>
#include "JsonValue.h"

class JsonString : public JsonValue{
private:
    std::string value;
public:
    JsonString(std::string& _value) : value(_value){};
    std::string getValue()const{return value;}
    void print(){
        std::cout <<' ' << '"'<<value<<'"'<<','<<endl;
    }
};
#endif //JSON_PARSER_JSONSTRING_H
