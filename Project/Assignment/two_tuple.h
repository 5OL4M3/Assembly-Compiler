#ifndef TUPLE_H_
#define TUPLE_H_
#include <iostream>

class TwoTuple {
public:
    TwoTuple(int _name);
    void add_value(int _value);
    void displayTuple( );
    int name;
    int value;
    bool value_empty;
};



#endif