#include "statement_buffer.h"
#include <string>
#include <iostream>
#include <vector>
#include "data_memory.h"
#define BIG_TEMP 69

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

int Statement_Buffer::statement_action(int pc, std::vector<int>& vec, std::vector<int>& vec2, Data_Memory* data){
    //vec is runtime stack
    //vec2 is return stack
    std::cout << "PC is at: "<< pc << "\n";
    std::cout << statement_vector.at(pc)->instruction << "\n";

    int new_pc = statement_vector.at(pc)->vm_action(vec);

    if(statement_vector.at(pc)->instruction == "OP_ENTER_SUBROUTINE") {
        //Add a stack frame of size opnd to the data memory to hold the variables used by the subroutine. 
        //Increment the pc to cause the next statement in instruction memory to be executed next.
        for(int i = 0; i < statement_vector.at(pc)->count; i++) {
            data->add_data(BIG_TEMP);
        }
    }

    if(statement_vector.at(pc) -> instruction == "OP_START_PROGRAM") {
        //Set up storage in the data memory to hold the outer scope variables. 
        //The size of the stack frame is given by opnd. This is basically setting up the stack frame for the main procedure.
        for(int i = 0; i < statement_vector.at(pc)->count; i++) {
            data->add_data(BIG_TEMP);
        }
    }

    if(statement_vector.at(pc)->instruction == "OP_GOSUB") {
        //Make a subroutine call. 
        //The address of the next statement (pc+1) is stored into a runtime stack of return addresses. 
        //The pc is set to the value of opnd, which is the address of the subroutine.
        vec2.push_back(pc + 1);
    }

    if(statement_vector.at(pc)->instruction == "OP_JUMP") {
        //Set the pc to the address specified by opnd. 
        //This instruction was created by the parser from the jump label statement.
        new_pc = statement_vector.at(pc) -> count;
    }

    if(statement_vector.at(pc)->instruction == "OP_RETURN") {
        //return from a subroutine call. Set the pc to the last return address saved by an OP_GOSUB instruction. 
        //Pop the current subroutine stack frame from the data memory.
        if(vec2.size() > 0) {
            new_pc = vec2[vec2.size() - 1];     //set new pc address
            //pop return address and data memory
            vec2.pop_back();
            data->remove_data();
        }
    }
    std::cout<<"printcontent";
    data->printContent();

    if (new_pc == -2) {
        return pc + 1;
    }
    else {
        return new_pc;
    }
}