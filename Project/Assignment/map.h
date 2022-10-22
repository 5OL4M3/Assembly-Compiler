#ifndef MAP_H_
#define MAP_H_

#include <iostream>
#include <fstream>
#include <vector>
#include "statement_buffer.h"
#include "symbol_table.h"
#include "command.h"
#include "functions.h"
#include <map>

class Map {
private:
    std::map<std::string, Command *> command_val;
public:
    virtual void insert(std::string key, Command* _data);
    virtual Command* lookUp(std::string key);
};

#endif