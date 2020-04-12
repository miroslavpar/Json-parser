//
// Created by Miroslav Parapanov on 2020-04-13.
//
#include "JsonArray.h"
void JsonArray::printJustValue() {
    std::cout <<'[';
    int counter = 0;
    for(auto& it : value) {
        it->printJustValue();
        counter++;
        if(counter != value.size()){
            cout << ','<<' ';
        }
    }
    std::cout << ']';
}
void JsonArray::print() {
    std::cout <<'['<<std::endl;
    int counter = 0;
    for(auto& it : value) {
        cout << "    ";
        it->printJustValue();
        counter++;
        if(counter != value.size()){
            cout << ','<<' ';
            cout << endl;
        }
    }
    std::cout<< "  " << ']';
}
void JsonArray::searchFromKey(string &) {};
JsonArray::JsonArray(){};
JsonArray::JsonArray(std::vector<JsonValue*>& _value):value(_value){};
