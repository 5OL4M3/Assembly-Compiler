#include "map.h"
#include <string>
#include <map>
#include <iostream>

//Map

void Map::insert(std::string key, Command* _data) {
   // fill this in. Insert a std::pair that contains an int and a TwoTuple* as its members.
   command_val.insert(std::pair<std::string, Command*>(key, _data));
}

Command * Map::lookUp(std::string key){
    std::map<std::string,Command*>::iterator it; 
	
	it = command_val.find(key.substr(0, key.find(" ")));
    if (it == command_val.end())
    {
        std::cout << "Invalid Syntax" << std::endl;
        exit(0);
    }
    else
    {
        return it->second;
   }
}
