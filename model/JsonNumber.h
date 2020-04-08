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
    JsonNumber(double _num) : num(_num){};
    double getNum()const {return num;};
    void print(){
        std::cout << num<<',' <<endl;
    }
};
#endif //JSON_PARSER_JSONNUMBER_H
