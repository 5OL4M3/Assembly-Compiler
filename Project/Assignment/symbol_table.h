#ifndef SYMBOL_TABLE_H_
#define SYMBOL_TABLE_H_

#include <iostream>
#include <fstream>
#include <vector>
#include "statement_buffer.h"
#include "command.h"
#include "functions.h"
#include "table_entry.h"

class Symbol_Table{
private:
    static Symbol_Table * instance;
    static std::vector<Table_Entry *> symbol_vector;
    Symbol_Table();
public:
    static int find_location(std::string, int, int);
    static int num_var_scope1;
    static int num_var_scope2;
    static int scope1_index; //for variable in scope 1
    //static int scope2_index; //for variable in scope 2
    static Symbol_Table * create_symbol_table();
    static void add_symbol(Command *, int type); //0 is label, 1 is declare var, 2 is declare array
    static void printContent();
};

#endif
