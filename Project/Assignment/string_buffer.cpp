#include "string_buffer.h"
#include <string>
#include <map>
#include <iostream>

//String Buffer
String_Buffer* String_Buffer::instance = nullptr;

std::vector<std::string> String_Buffer::string_vector;

String_Buffer::String_Buffer(){}

String_Buffer *String_Buffer::create_string_buffer() {
    if (instance == NULL){
        instance = new String_Buffer();
    }
    return instance;
}
void String_Buffer::add_statement(Command * item) {
    string_vector.push_back(item -> var1);
}

void String_Buffer::printContent() {
    std::cout << "\nString buffer: \n";
    for(int i = 0; i < string_vector.size(); i++)   {
        std::cout << string_vector.at(i) << "\n";
    }
}

int String_Buffer::find_location(std::string key){
    //std::cout << "Finding " << key << "\n";
    for (int i = string_vector.size() - 1; i >= 0; i--){
        if(string_vector.at(i) == key){
            return i;
        }
    }
}
/*
void Statement_Buffer::add_statement(Command * item){
    item->instruction = item->get_instruction();
    item->count = item->get_count(); 
    statement_vector.push_back(item);
}
void Statement_Buffer::printContent(){
    std::cout << "Buffer Statement: \n";
    for (int i = 0; i < statement_vector.size(); i++)
    {
        std::cout << statement_vector.at(i)->instruction << ", " << statement_vector.at(i)->count << "\n";
    }
}
*/