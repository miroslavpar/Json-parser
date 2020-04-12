#include <iostream>
#include "dbmanager/JsonManager.h"

int main() {
    std::string alabala = "{\n"
                          "    \"id\": \"fdsfsdf\",\n"
                          "    \"name\": \"Foo\",\n"
                          "    \"price\": e+3,\n"
                          "    \"tags\": [ \"Bar\", \"Eek\" ]\n"
                          "    \"stock\": {\n"
                          "        \"warehouse\": 300,\n"
                          "        \"retail\": 20\n"
                          "    }\n"
                          "}";
//    std::stringstream jsonstream;
//    jsonstream << alabala;
//    try {
//     p.readJson(jsonstream)->print();
//    }
//    catch (const char* e){
//        cout << e<<endl;
//    }
//    string number = "300, ";
//    stringstream parse;
//    parse <<number;
//    char symbol = parse.get();
//    try {
//        cout << p.readJson(parse) << endl;
//    }
//    catch (const char* e){
//        cout << e<<endl;
//    }
//
    string file = "jsonFile.txt";
    string key = "tags";
    JsonManager jsonManager(file);
    jsonManager.print();
    jsonManager.search(key);
    return 0;
}