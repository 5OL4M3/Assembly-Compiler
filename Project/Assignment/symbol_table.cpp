#include "symbol_table.h"
#include <string>
#include <map>
#include <iostream>


//Symbol Table
int Symbol_Table::num_var_scope1 = 0;
int Symbol_Table::num_var_scope2 = 0;

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
    int this_size;
    if (item->expected == 2){
        this_size = stoi(item->var2);
    }
    else{
        this_size = item->data_size;
    }
    
    Table_Entry * dummy = new Table_Entry(item->var1, Statement_Buffer::index + item->add_index, this_size);
    symbol_vector.push_back(dummy); 
}

int Symbol_Table::find_location(std::string key){
    for (int i = symbol_vector.size() - 1; i >= 0; i--){
        if(symbol_vector.at(i)->get_name() == key){
            return symbol_vector.at(i)->get_index();
        }
    }
}

void Symbol_Table::printContent(){
    std::cout << "\nSymbol_Table: \n";
    for (int i = 0; i < symbol_vector.size(); i++)
    {
        std::cout << symbol_vector.at(i)->get_name() << ", " << "<" << symbol_vector.at(i)->get_index() << "," << symbol_vector.at(i)->get_size() << ">\n";
    }
}