#ifndef SYMBOL_TABLE_H_
#define SYMBOL_TABLE_H_

#include <string>
#include <iostream>
#include "statement_buffer.h"
#include "map.h"
#include "command.h"

class Symbol_Table{
private:
    static Symbol_Table * instance;
    std::map<std::string, int *> symbol_table;
    Symbol_Table();
public:
    static Symbol_Table * create_symbol_table();
};

#endif
