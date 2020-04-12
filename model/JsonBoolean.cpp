//
// Created by Miroslav Parapanov on 2020-04-13.
//
#include "JsonBoolean.h"
using namespace std;

JsonBoolean::JsonBoolean(bool _value):value(_value){}
void JsonBoolean::searchFromKey(string & key) {
    printJustValue();
}
void JsonBoolean::printJustValue(){
    if(value){
        cout << "true";
    }
    else {
        cout << "false";
    }
}
void JsonBoolean::print(){
    std::cout << value <<','<<endl;
}




