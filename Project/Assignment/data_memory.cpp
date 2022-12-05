#include <string>
#include <iostream>
#include "data_memory.h"

Data_Memory* Data_Memory::instance = nullptr;

Data_Memory::Data_Memory(){}

std::vector<TwoTuple *> Data_Memory::data_memory;

std::vector<int> Data_Memory::index_stack;

int Data_Memory::global_size;
int Data_Memory::scope2_size;
int Data_Memory::subroutine_size;

Data_Memory * Data_Memory::create_data_memory() {
    if (instance == NULL){
        instance = new Data_Memory();
    }
    return instance;
}

void Data_Memory::add_data(int item){
    TwoTuple * new_item = new TwoTuple(item);
    data_memory.push_back(new_item);
}

void Data_Memory::printContent(){
    std::cout << "Data Memory: \n";
    for (int i = 0; i < data_memory.size(); i++)
    {
        int name = data_memory.at(i)->get_name();
        int value = data_memory.at(i)->get_value();
        std::cout << "(" << name << ", " << (data_memory.at(i)->value_empty ? -1 : value) << ") ";
    }
}

void Data_Memory::add_value(int index, int val) {
    data_memory.at(index)->add_value(val);
}

int Data_Memory::get_val(int index) {
    if(data_memory.size() > index) {
        //make sure we are not accessing past the end of the values
        return (data_memory.at(index) -> get_value());
    }
    else {
        //we have a problem
        return -1;
    }
}

void Data_Memory::pop() {
    data_memory.pop_back();
}

int Data_Memory::get_size(){
    return data_memory.size();
}
