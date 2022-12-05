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
    static void add_data(int);
    static void printContent();
    static int get_size();
    static void pop();
    static void add_value(int, int);
    static int get_val(int);
    static std::vector<int> index_stack;
    static int global_size;
    static int scope2_size;
    static int subroutine_size;
};



#endif
