#ifndef TUPLE_H_
#define TUPLE_H_
#include <iostream>

class TwoTuple {
public:
    TwoTuple(std::string _name);
    void add_value(int _value);
    void displayTuple( );
    std::string name;
    int value;
    bool value_empty;
};



#endif