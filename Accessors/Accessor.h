//
// Created by Miroslav Parapanov on 2020-05-22.
//

#ifndef JSON_PARSER_ACCESSOR_H
#define JSON_PARSER_ACCESSOR_H

#include <string>
using namespace std;

class Accessor {
private:
    string field;
    int value;
public:
    Accessor() = default;
    Accessor(string&,int);
    string getField()const;
    int getValue()const;
    void setField(const string&);
    void setValue(const int);
};


#endif //JSON_PARSER_ACCESSOR_H
