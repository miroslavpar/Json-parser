//
// Created by Miroslav Parapanov on 2020-04-13.
//
#include "JsonNumber.h"
JsonNumber::JsonNumber(double _num) : num(_num){}

void JsonNumber::searchFromKey(string& key){
    printJustValue();
}
void JsonNumber::print(){
    cout << num <<',';
}
void JsonNumber ::printJustValue() {
    cout << num;
}


