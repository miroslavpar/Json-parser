//
// Created by Miroslav Parapanov on 2020-04-13.
//
#include "JsonNumber.h"
JsonNumber::JsonNumber(){
    type = JSONNUMBER;
    num = 0;
}
JsonNumber::JsonNumber(double _num) : num(_num){
    type = JSONNUMBER;
}
void JsonNumber::print()const{
    cout << num;
}
Type JsonNumber::getType()const {
    return type;
}
void JsonNumber::set(double _num) {
    num = _num;
}
double JsonNumber::getValueFromJsonNumber()const{
    return num;
}
void JsonNumber::write(ofstream & os)const {
    os << num;
}



