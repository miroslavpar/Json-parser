//
// Created by Miroslav Parapanov on 2020-03-31.
//

#ifndef JSON_PARSER_JSONBOOLEAN_H
#define JSON_PARSER_JSONBOOLEAN_H

#include "JsonValue.h"

class JsonBoolean : public JsonValue {
private:
    bool value;
public:
    JsonBoolean(bool _value):value(_value){};
    bool getValue()const{return value;};
    void print(){
       std::cout << value <<',' <<endl;
    }
};
#endif //JSON_PARSER_JSONBOOLEAN_H
