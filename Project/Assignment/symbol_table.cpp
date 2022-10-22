#include "symbol_table.h"
#include <string>
#include <map>
#include <iostream>


//Symbol Table
Symbol_Table*  Symbol_Table::instance = nullptr;

std::vector<Table_Entry *> Symbol_Table::symbol_vector;

Symbol_Table::Symbol_Table(){}

Symbol_Table * Symbol_Table::create_symbol_table() {
    if (instance == nullptr){
        instance = new Symbol_Table();
    }
    return instance;
}

void Symbol_Table::add_symbol(Command * item){
    //Table_Entry * dummy(item->var1, );
}

void Symbol_Table::printContent(){
    std::cout << "\nSymbol_Table: \n";
    for (int i = 0; i < symbol_vector.size(); i++)
    {
        std::cout << symbol_vector.at(i)->get_name() << ", " << "<" << symbol_vector.at(i)->get_index() << "," << symbol_vector.at(i)->get_size() << ">\n";
    }
}