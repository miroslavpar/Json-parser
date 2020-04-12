//
// Created by Miroslav Parapanov on 2020-03-31.
//

#ifndef JSON_PARSER_JSONARRAY_H
#define JSON_PARSER_JSONARRAY_H

#include "JsonValue.h"
#include <vector>
class JsonArray : public JsonValue {
private:
    std::vector<JsonValue*> value;
public:
    JsonArray();
    JsonArray(std::vector<JsonValue*>&);
    void searchFromKey(string&);
    void printJustValue();
    void print ();
};
#endif //JSON_PARSER_JSONARRAY_H
