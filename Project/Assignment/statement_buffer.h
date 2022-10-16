#ifndef STATEMENT_BUFFER_H_
#define STATEMENT_BUFFER_H_

#include <string>
#include <map>
#include <iostream>
#include "map.h"
#include "symbol_table.h"
#include "command.h"

class Statement_Buffer{
private:
    static Statement_Buffer * instance;
    //static Command * statement_buffer;
    Statement_Buffer();
public:
    static Statement_Buffer * create_statement_buffer();
};
//Determines what command is being declared 

#endif