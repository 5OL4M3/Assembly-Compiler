#include "symbol_table.h"
#include <string>
#include <map>
#include <iostream>


//Symbol Table
Symbol_Table* Symbol_Table::instance = nullptr;

Symbol_Table::Symbol_Table(){}

Symbol_Table * Symbol_Table::create_symbol_table() {
    if (instance == nullptr){
        instance = new Symbol_Table();
    }
    return instance;
}
