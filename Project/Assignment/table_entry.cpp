#include "table_entry.h"

Table_Entry::Table_Entry(std::string _name, int _index, int _size, int _scope) : name(_name), index(_index), size(_size), scope(_scope){ }

std::string Table_Entry::get_name( ) {
   return name;
}

int Table_Entry::get_index( ) {
   return index;
}

int Table_Entry::get_size( ) {
   return size;
}

int Table_Entry::get_scope( ) {
   return scope;
}