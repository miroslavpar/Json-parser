//
// Created by Miroslav Parapanov on 2020-04-13.
//

#include "JsonString.h"

JsonString::JsonString(std::string& _value) : value(_value){};

void JsonString::print() {
    std::cout  << '"'<<value<<'"'<< ',';
}
void JsonString::printJustValue() {
    std::cout  << '"'<< value <<'"';
}
void JsonString::searchFromKey(string &) {
    printJustValue();
}

