//
// Created by Miroslav Parapanov on 2020-03-31.
//

#ifndef JSON_PARSER_JSONARRAY_H
#define JSON_PARSER_JSONARRAY_H

#include "JsonValue.h"
#include <vector>
class JsonArray : public JsonValue {
private:
    vector<JsonValue*> value;
public:
    JsonArray();
    explicit JsonArray(vector<JsonValue*>&);
    void print()const;
    void setValue(const string&);
    Type getType()const;
    void set(int, JsonValue*);
    void write(ofstream&)const;
};
#endif //JSON_PARSER_JSONARRAY_H
