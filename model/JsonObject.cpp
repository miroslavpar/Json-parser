//
// Created by Miroslav Parapanov on 2020-04-13.
//
#include "JsonObject.h"

JsonObject::JsonObject(unordered_map<string,JsonValue*>& _properties): properties(_properties){}

void JsonObject::printJustValue() {
    std::cout << '{' <<std::endl;
    for(auto& it : properties) {
        std::cout <<' '<<'"'<<it.first<<'"'<<' '<< ':'<< ' ';
        it.second->printJustValue();
        cout << ',' << endl;
    }
    cout << '}';
}


static stack<char> openBrackets;

void JsonObject::print() {
    std::cout << '{' <<std::endl;
    openBrackets.push('{');
    int counter = 1;
    for(auto& it : properties) {
        std::cout <<' '<<'"'<<it.first<<'"'<<' '<< ':'<< ' ';
        it.second->print();
        cout << endl;
    }
    openBrackets.pop();
    if(!openBrackets.empty()){
        cout<<'\t'<< '}' << ',';
    }
    else{
        cout << '}';
    }
}

void JsonObject::searchFromKey(string& key) {
    auto result = properties.find(key);
    if(result != properties.end()){
        result->second->printJustValue();
    }
    else {
        throw runtime_error(" Not such value found with this key ");
    }
}

