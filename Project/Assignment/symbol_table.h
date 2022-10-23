#ifndef SYMBOL_TABLE_H_
#define SYMBOL_TABLE_H_

#include <iostream>
#include <fstream>
#include <vector>
#include "statement_buffer.h"
#include "map.h"
#include "command.h"
#include "functions.h"
#include "table_entry.h"

class Symbol_Table{
private:
    static Symbol_Table * instance;
    static std::vector<Table_Entry *> symbol_vector;
    Symbol_Table();
public:
    static int find_location(std::string);
    static int num_var_scope1;
    static int num_var_scope2;
    static Symbol_Table * create_symbol_table();
    static void add_symbol(Command *);
    static void printContent();
};

#endif
