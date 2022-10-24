#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <fstream>
#include <vector>
#include "statement_buffer.h"
#include "map.h"
#include "symbol_table.h"
#include "command.h"

/*This function 1) remove all end spaces
                2) reduces spaces between words to one
*/
std::string cleanString(std::string);
int lookString(std::string, std::string* array);


#endif