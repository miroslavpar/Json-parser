#include <iostream>
#include "dbmanager/JsonManager.h"

int main() {
    JsonManager p;
    std::string alabala = "{\n"
                        //  "    \"id\": 1,\n"
                          "    \"name\": \"Foo\",\n"
                        //  "    \"price\": 2,\n"
                          "    \"tags\": [ \"Bar\", \"Eek\" ],\n"
                          "    \"stock\": {\n"
                        //  "        \"warehouse\": 300,\n"
                       //   "        \"retail\": 20\n"
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
    return 0;
}