//
// Created by Miroslav Parapanov on 2020-05-22.
//

#include "Accessor.h"
Accessor::Accessor(string& _field, int _value):field(_field),value(_value){}
string Accessor::getField()const{
    return field;
}
int Accessor::getValue()const{
    return value;
}
void Accessor::setField(const string& _field){
    field = _field;
}
void Accessor::setValue(const int _value) {
    value = _value;
}