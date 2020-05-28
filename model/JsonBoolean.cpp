//
// Created by Miroslav Parapanov on 2020-04-13.
//
#include "JsonBoolean.h"
using namespace std;
JsonBoolean::JsonBoolean(){
    type = JSONBOOLEAN;
}
JsonBoolean::JsonBoolean(bool _value):value(_value){
    type = JSONBOOLEAN;
}
void JsonBoolean::print()const{
    if(value)
        cout  << "true";
    else {
        cout  << "false";
    }
}
Type JsonBoolean::getType()const {
    return type;
}
void JsonBoolean::set(bool param){
    value = param;
}
bool JsonBoolean::getValueFromJsonBoolean() const {
    return value;
}
void JsonBoolean::write(ofstream & os)const {
    if (value)
        os << "true";
   else {
        os << "false";
    }
}
