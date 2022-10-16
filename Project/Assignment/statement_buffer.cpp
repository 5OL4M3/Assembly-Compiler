#include "statement_buffer.h"
#include <string>
#include <map>
#include <iostream>

//Statement Buffer
Statement_Buffer* Statement_Buffer::instance = nullptr;

Statement_Buffer::Statement_Buffer(){}

Statement_Buffer *Statement_Buffer::create_statement_buffer() {
    if (instance == NULL){
        instance = new Statement_Buffer();
    }
    return instance;
}
