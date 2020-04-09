#include <iostream>
#include "dbmanager/JsonManager.h"

int main() {
    JsonManager p;
    std::string alabala = "{\n"
                          "    \"id\": \"fdsfsdf\",\n"
                          "    \"name\": \"Foo\",\n"
                         // "    \"price\": 123,\n"
                          "    \"tags\": [ \"Bar\", \"Eek\" ],\n"
                          "    \"stock\": {\n"
                          "        \"warehouse\": \"300\",\n"
                          "        \"retail\": \"20\"\n"
                          "    }\n"
                          "}";
    std::stringstream jsonstream;
    jsonstream << alabala;
    try {
     p.readJson(jsonstream)->print();
    }
    catch (const char* e){
        cout << e<<endl;
    }
//    string number = "e22, ";
//    stringstream parse;
//    parse <<number;
//    char symbol = parse.get();
//    try {
//        cout << p.geteNumber(symbol,parse) << endl;
//    }
//    catch (const char* e){
//        cout << e<<endl;
//    }
    return 0;
}