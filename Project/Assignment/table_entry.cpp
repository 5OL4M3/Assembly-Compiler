#include "table_entry.h"

Table_Entry::Table_Entry(std::string _name, int _index, int _size) : name(_name), index(_index), size(_size) { }

std::string Table_Entry::get_name( ) {
   return name;
}

int Table_Entry::get_index( ) {
   return index;
}

int Table_Entry::get_size( ) {
   return size;
}