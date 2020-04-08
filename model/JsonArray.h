//
// Created by Miroslav Parapanov on 2020-03-31.
//

#ifndef JSON_PARSER_JSONARRAY_H
#define JSON_PARSER_JSONARRAY_H

#include "JsonValue.h"
#include <vector>
#include <iostream>
class JsonArray : public JsonValue {
private:
    std::vector<JsonValue*> value;
public:
    JsonArray(){};
    JsonArray(std::vector<JsonValue*>& _value):value(_value){};
    std::vector<JsonValue*> getValue()const {return value;};
    void print (){
        std::cout <<'['<<std::endl;
        int counter = 0;
        for(auto& it : value) {
            it->print();
            counter++;
//            if(counter != value.size()){
//                std::cout<<',';
//            }
        }
        std::cout << ']'<<endl;
    }
};
#endif //JSON_PARSER_JSONARRAY_H
