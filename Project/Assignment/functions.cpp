#include <string>
#include <map>
#include <iostream>
#include "functions.h"
#include <algorithm>

std::string cleanString(std::string str){
    //std::cout << "Before: " << str << std::endl;
    //Replace multiple white spaces with one white space
    int start, len = 0;
    for (int i = 0; i < str.length(); i++){
        if (str[i] == 32){
            start = i;
            i++;
            while (str[i] == 32){
                len++;
                i++;
            }
            str.erase(start, len);
            i -= len;
            len = 0;
        }
    }
    //Replace trailing white space in the end
    if(str[str.length() - 1] == 32){
        str.erase((str.length() - 1), 1);
    }
    //std::cout << "After: " << str << "|" <<std::endl;
    return str;
}

int lookString(std::string key, std::string* array) {
    key = key.substr(0, key.find(" "));
    for(int i = 0; i < 26; i++) {
        if (key == array[i]){
            return i;
        }
    }
    std::cout << "Error! Invalid Syntax" << std::endl;
    exit(0);
}
