//
// Created by Miroslav Parapanov on 2020-03-31.
//

#ifndef JSON_PARSER_JSONOBJECT_H
#define JSON_PARSER_JSONOBJECT_H

#include "JsonValue.h"
#include <unordered_map>
#include <iostream>

class JsonObject : public JsonValue {
private:
    unordered_map<string,JsonValue*> properties;
public:
    JsonObject(unordered_map<string,JsonValue*>& _properties): properties(_properties){};
    unordered_map<string,JsonValue*> getProperties()const {return properties;};
    void print(){
        std::cout << '{' <<std::endl;
        int counter = 0;
        for(auto& it : properties) {
            std::cout << '"'<<it.first<<'"'<<' '<< ':';
            it.second->print();
            counter++;
//            if(counter != properties.size() ){
//                std::cout << ',';
//            }
        }
        std::cout <<'}'<<std::endl;
    }
};
#endif //JSON_PARSER_JSONOBJECT_H
