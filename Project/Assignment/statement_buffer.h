#ifndef STATEMENT_BUFFER_H_
#define STATEMENT_BUFFER_H_
#include <iostream>
#include <fstream>
#include <vector>
#include "symbol_table.h"
#include "command.h"
#include "functions.h"

class Statement_Buffer{
private:
    static Statement_Buffer * instance;
    static std::vector<Command *> statement_vector;
    Statement_Buffer();
public:
    static Statement_Buffer * create_statement_buffer();
    static int index; 
    static void add_statement(Command *);
    static void printContent();
    static void update_count(int);
};
//Determines what command is being declared 

#endif