#include "statement_buffer.h"
#include <string>
#include <map>
#include <iostream>

//Statement Buffer
Statement_Buffer* Statement_Buffer::instance = nullptr;

int Statement_Buffer::index = 0;

std::vector<Command *> Statement_Buffer::statement_vector;

Statement_Buffer::Statement_Buffer(){}

Statement_Buffer *Statement_Buffer::create_statement_buffer() {
    if (instance == NULL){
        instance = new Statement_Buffer();
    }
    return instance;
}

void Statement_Buffer::add_statement(Command * item){
    item->instruction = item->get_instruction();
    item->count = item->get_count(); 
    statement_vector.push_back(item);
    index += 1;
}

void Statement_Buffer::printContent(){
    std::cout << "\nBuffer Statement: \n";
    for (int i = 0; i < statement_vector.size(); i++)
    {
        std::cout << statement_vector.at(i)->instruction << ", " << statement_vector.at(i)->count << "\n";
    }
}