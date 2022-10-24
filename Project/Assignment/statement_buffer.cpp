#include "statement_buffer.h"
#include <string>
#include <iostream>

//Statement Buffer
Statement_Buffer* Statement_Buffer::instance = nullptr;

int Statement_Buffer::index = -1;

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
    item->count = item->count; 
    statement_vector.push_back(item);
    index += 1;
}

void Statement_Buffer::printContent(){
    std::cout << "\nBuffer Statement: \n";
    for (int i = 0; i < statement_vector.size(); i++)
    {
        std::cout << "  " << statement_vector.at(i)->instruction << ", " << statement_vector.at(i)->count << "\n";
    }
}

void Statement_Buffer::update_count(int scope){
    //std::cout << "updating count[" << scope <<"]:\n";
    //If in subroutine 
    if (scope == 2){
        int i = statement_vector.size() - 1;
        while (statement_vector.at(i)->scope == scope){
           // std::cout << "Looking at " << statement_vector.at(i)->instruction << "\n";
            if (statement_vector.at(i)->need_update){
                statement_vector.at(i)->perform_update();
                //std::cout <<" TESTING: " << statement_vector.at(i)->scope << "\n";
            }
            i -= 1;
        }
        //std::cout << "Looking at " << statement_vector.at(i)->instruction << "\n";
        if (statement_vector.at(i)->need_update){
            statement_vector.at(i)->perform_update();
        }
    }
    if (scope == 1) {
        for (int i = statement_vector.size() - 1; i >= 0; i--){
            if (statement_vector.at(i)->scope == scope){
                //std::cout << i << "Looking at " << statement_vector.at(i)->instruction << "\n";
                if (statement_vector.at(i)->need_update){
                    statement_vector.at(i)->perform_update();
                    //std::cout <<" TESTING: " << statement_vector.at(i)->scope << "\n";
                }
            }
        }
    }
}