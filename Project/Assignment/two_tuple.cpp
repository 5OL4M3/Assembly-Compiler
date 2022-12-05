#include "two_tuple.h"
#include <string>
#include <iostream>

TwoTuple::TwoTuple(int _name) : name(_name) { 
    value_empty = true;
}

void TwoTuple::add_value(int _value){ 
    value = _value;
    value_empty = false;
}

void TwoTuple::displayTuple( ) {
   std::cout << "(" << name << ", " << value << ")";
}

int TwoTuple::get_name() {
    return name;
}

int TwoTuple::get_value() {
    return value;
}
