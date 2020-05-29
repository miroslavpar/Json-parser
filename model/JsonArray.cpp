//
// Created by Miroslav Parapanov on 2020-04-13.
//
#include "JsonArray.h"
stack<char> openArrayBrackets;
JsonArray::JsonArray() {
    type = JSONARRAY;
}
void JsonArray::print()const {
    int counter = 0;
    cout << " [ ";
    openArrayBrackets.push(('['));
    for(auto& it : value) {
        it->print();
        counter++;
        if(counter != value.size())
            cout << ", ";
    }
    openArrayBrackets.pop();
    if(!openArrayBrackets.empty()){
        cout << " ],\n";
    }
    else {
        cout << " ]";
    }
}
JsonArray::JsonArray(std::vector<JsonValue*>& _value):value(_value){
    type = JSONARRAY;
}
Type JsonArray::getType()const{
    return type;
}

void JsonArray::set(int whichValue, JsonValue* new_value){
    int counter = value.size();
    for(int i = 0 ; i < counter ; i++){
        if(i == whichValue){
            value[i] = new_value;
        }
    }
}
void JsonArray::write(ofstream& os) const{
    int counter = 0;
    os << " [ ";
    openArrayBrackets.push(('['));
    for(auto& it : value) {
        it->write(os);
        counter++;
        if(counter != value.size())
            os << ", ";

    }
    openArrayBrackets.pop();
    if(!openArrayBrackets.empty()){
        os << " ],\n";
    }
    else {
        os << " ]";
    }
}