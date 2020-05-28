//
// Created by Miroslav Parapanov on 2020-04-13.
//

#include "JsonString.h"
#include <fstream>
JsonString::JsonString(){
    type = JSONSTRING;
}
JsonString::JsonString(string& _value) : value(_value){
    type = JSONSTRING;
}

void JsonString::print() const{
    cout  << '"'<<value<<'"';
}
Type JsonString::getType()const {
    return type;
}
void JsonString::set(string& _value) {
    value = _value;
}
string JsonString::getValueFromJsonString()const{
    return value;
}
void JsonString::write(ofstream& os)const{
    os << '"'<< value << '"';
}