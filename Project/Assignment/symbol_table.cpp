#include "symbol_table.h"
#include <string>
#include <iostream>


//Symbol Table
int Symbol_Table::num_var_scope1 = 0;
int Symbol_Table::num_var_scope2 = 0;
int Symbol_Table::scope1_index = -1;
//int Symbol_Table::scope2_index = -1;

Symbol_Table*  Symbol_Table::instance = nullptr;

std::vector<Table_Entry *> Symbol_Table::symbol_vector;

Symbol_Table::Symbol_Table(){}

Symbol_Table * Symbol_Table::create_symbol_table() {
    if (instance == nullptr){
        instance = new Symbol_Table();
    }
    return instance;
}

void Symbol_Table::add_symbol(Command * item, int type){
    //Check size of the item
    int this_size;
    if (item->expected == 2){
        this_size = stoi(item->var2);
    }
    else{
        this_size = item->data_size;
    }

    if (type == 0){//is label
        Table_Entry * dummy = new Table_Entry(item->var1, Statement_Buffer::index + 1, this_size, item->scope);
        symbol_vector.push_back(dummy); 
    }
    else if (type == 1){//is var
        //if scope is 2
        /* if (item->scope == 2){
            scope2_index += 1;
            Table_Entry * dummy = new Table_Entry(item->var1, scope2_index, this_size, item->scope);
            symbol_vector.push_back(dummy); 
        }
        else {
            scope1_index += 1;
            Table_Entry * dummy = new Table_Entry(item->var1, scope1_index, this_size, item->scope);
            symbol_vector.push_back(dummy);
        } */
        scope1_index += 1;
        Table_Entry * dummy = new Table_Entry(item->var1, scope1_index, this_size, item->scope);
        symbol_vector.push_back(dummy);
    }
    else if (type == 2){// is array
        /* if (item->scope == 2){
            for (int i = 0; i < stoi(item->var2); i++){
                scope2_index += 1;
                Table_Entry * dummy = new Table_Entry(item->var1, scope2_index, this_size, item->scope);
                symbol_vector.push_back(dummy); 
            }
        }
        else {
            for (int i = 0; i < stoi(item->var2); i++){
                scope1_index += 1;
                Table_Entry * dummy = new Table_Entry(item->var1, scope1_index, this_size, item->scope);
                symbol_vector.push_back(dummy); 
            }
        } */
        
        for (int i = 0; i < stoi(item->var2); i++){
            if (item->scope == 1){
                Symbol_Table::num_var_scope1 +=1;
            }
            else if (item->scope == 2){
                Symbol_Table::num_var_scope2 +=1;
            }
            scope1_index += 1;
            Table_Entry * dummy = new Table_Entry(item->var1, scope1_index, this_size, item->scope);
            symbol_vector.push_back(dummy); 
        }
    }
    else if (type == 3){//is gosublabel
        Table_Entry * dummy = new Table_Entry(item->var1, Statement_Buffer::index, this_size, item->scope);
        symbol_vector.push_back(dummy); 
    }
}

int Symbol_Table::find_location(std::string key, int scope, int is_arr){
    int prev, index;
    if (is_arr == 1){
        for (int i = 0; i < symbol_vector.size(); i++){
            if(symbol_vector.at(i)->get_name() == key && symbol_vector.at(i)->get_scope() == scope){
                //std::cout << symbol_vector.at(i)->get_index();
                return symbol_vector.at(i)->get_index();
            }
        }
    }
    else{
        for (int i = symbol_vector.size() - 1; i >= 0; i--){
            if (prev != symbol_vector.at(i)->get_scope()){
                if (is_arr == 10){
                    if (symbol_vector.at(i)->get_name() == key){
                        return symbol_vector.at(i)->get_index();
                    }
                }
            }
            if(symbol_vector.at(i)->get_name() == key && symbol_vector.at(i)->get_scope() == scope){
                return symbol_vector.at(i)->get_index();
            }
            prev = symbol_vector.at(i)->get_scope();
        }
    }   
    
    for (int i = symbol_vector.size() - 1; i >= 0; i--){
        if(symbol_vector.at(i)->get_name() == key){
            return symbol_vector.at(i)->get_index();
        }
    }

    std::cout << "FAILED\n";
    return -1;
}

int Symbol_Table::find_repetitive(std::string key, int scope, int is_arr){
    int prev, index;
    if (is_arr == 1){
        for (int i = 0; i < symbol_vector.size(); i++){
            if(symbol_vector.at(i)->get_name() == key && symbol_vector.at(i)->get_scope() == scope){
                return symbol_vector.at(i)->get_index();
            }
        }
    }
    else{
        for (int i = symbol_vector.size() - 1; i >= 0; i--){
            if(symbol_vector.at(i)->get_name() == key && symbol_vector.at(i)->get_scope() == scope){
                return symbol_vector.at(i)->get_index();
            }
        }
    }   
    
    return -1;
}

void Symbol_Table::printContent(){
    std::cout << "\nSymbol_Table: \n";
    for (int i = 0; i < symbol_vector.size(); i++)
    {
        std::cout << "  " << symbol_vector.at(i)->get_name() << ", " << "<" << symbol_vector.at(i)->get_index() << "," << symbol_vector.at(i)->get_size() << ">\n";
    }
}