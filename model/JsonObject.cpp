//
// Created by Miroslav Parapanov on 2020-04-13.
//
#include <vector>
#include "JsonObject.h"
JsonObject::JsonObject(){
    type = JSONOBJECT;
}
JsonObject::JsonObject(unordered_map<string,JsonValue*>& _properties): properties(_properties){
    type = JSONOBJECT;
}
static stack<char> openBrackets;
void setSpaces(int n){
    for(int i = 0 ; i< n ; i++){
        cout << ' ';
    }
}
void JsonObject::print() const{
    int counter = 0;
    cout << "{\n";
    openBrackets.push('{');
    for(auto& it : properties) {
        setSpaces(openBrackets.size() * 3);
        cout <<' '<<'"'<<it.first<<'"'<<' '<< ':'<< ' ';
        it.second->print();
        counter++;
        if(counter != properties.size()) {
            cout << ", \n";
        }

    }
    openBrackets.pop();
    if(!openBrackets.empty()){
        cout << '\n';
        setSpaces(openBrackets.size() * 3);
        cout << "},\n";
    }
    else{
        cout << "}\n";
    }
}

void JsonObject::searchFromKey(const string& key)const{
    for (auto& it : properties){
        if(it.first == key) {
            it.second->print();
            return;
        }
        else if(it.second->getType() == JSONOBJECT){
            it.second->searchFromKey(key);
            break;
        }
    }
}
bool JsonObject::checkKeyByString(const string& neededString)const{
    for(auto& it : properties){
        if(neededString == it.first){
            return true;
        }
    }
    return false;
}
void JsonObject::set(const string& key, JsonValue* _value) {
    auto it = properties.find(key);
    if(it != properties.end())
        it->second = _value;
}
Type JsonObject::getType()const {
    return type;
}
JsonValue* JsonObject::getSecondPropertyByKey(const string& key) const {
    auto it = properties.find(key);
    if(it != properties.end())
        return it->second;
}
void JsonObject::write(ofstream& os)const{
    int counter = 0;
    os << "{\n";
    openBrackets.push('{');
    for(auto& it : properties) {
        setSpaces(openBrackets.size() * 3);
        os <<' '<<'"'<<it.first<<'"'<<' '<< ':'<< ' ';
        it.second->print();
        counter++;
        if(counter != properties.size())
            os << ", \n";

    }
    openBrackets.pop();
    if(!openBrackets.empty()){
        os << '\n';
        setSpaces(openBrackets.size() * 3);
        os << "},\n";
    }
    else{
        os << "}\n";
    }
}
