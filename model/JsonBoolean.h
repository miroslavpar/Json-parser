//
// Created by Miroslav Parapanov on 2020-03-31.
//

#ifndef JSON_PARSER_JSONBOOLEAN_H
#define JSON_PARSER_JSONBOOLEAN_H

#include "JsonValue.h"
class JsonBoolean : public JsonValue {
private:
    bool value;
public:
    JsonBoolean();
    JsonBoolean(bool);
    void print()const;
    Type getType()const;
    void set(bool);
    bool getValueFromJsonBoolean()const;
    void write(ofstream&)const;

};
#endif //JSON_PARSER_JSONBOOLEAN_H
