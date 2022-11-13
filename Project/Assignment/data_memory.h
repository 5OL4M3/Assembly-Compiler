#ifndef DATA_MEMORY_H_
#define DATA_MEMORY_H_
#include <iostream>
#include <vector>
#include "two_tuple.h"

class Data_Memory{
private:
    static Data_Memory * instance;
    static std::vector<TwoTuple*> data_memory;
    Data_Memory();
public: 
    static Data_Memory * create_data_memory();
    static void add_data(std::string);
    static void printContent();
};



#endif
