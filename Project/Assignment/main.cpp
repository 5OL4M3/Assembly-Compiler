#include <iostream>
#include <fstream>
#include "statement_buffer.h"
#include "map.h"
#include "symbol_table.h"
#include "command.h"
#define COMMAND_AMOUNT 25


int main(int argc, char** argv){
    //Array for the lists of Command 
    std::string command_list[COMMAND_AMOUNT] = {"declscal", "declarr", "label", 
    "gosublabel", "end", "exit", "jump", "jumpzero", "jumpnzero", "gosub", "return",
    "pushscal", "pusharr", "pushi", "pop", "popscal", "poparr", "dup", "swap", "add", "negate", "mul",
    "div", "printtos", "prints"};
    //Array for the Command Objects
    Command * object_list[COMMAND_AMOUNT] = {new Declscal( ), new Declarr( ), new Label( ), new Gosublabel( ), new End( ), new Exit( ), new Jump( ),
    new Jumpzero( ), new Jumpnzero( ), new Gosub( ), new Return( ), new Pushscal( ),
    new Pusharr( ), new Pushi( ), new Pop( ), new Popscal( ), new Poparr( ), 
    new Dup( ), new Swap( ), new Add( ), new Negate( ), new Mul( ), 
    new Div( ), new Printtos( ), new Prints( )};

    //Create Map for the commands
    Map * command_map = new Map();
    for (int i = 0; i < COMMAND_AMOUNT; i++){
        command_map->insert(command_list[i], object_list[i]);
    }

    //Create Symbol Table:
    Symbol_Table * symbol_table = Symbol_Table::create_symbol_table();

    //Create Statement/Instruction Buffer:
    Statement_Buffer * statement_buffer = Statement_Buffer::create_statement_buffer();

    //Opening the file
    std::ifstream myfile;
    myfile.open(argv[1]);
    std::string myline;
    if (myfile.is_open()){
        //ISSUE: Fix 0 problem!!!
        
        //Check for start in the beginning of the file
        std::getline(myfile, myline);
        if (myline != "start"){
            std::cout << "No start\n";
            exit(0);
        }
        //Check rest of the file
        while (myfile){
            std::getline(myfile, myline);
            Command* curr_command = command_map->lookUp(myline.substr(0, myline.find(" ")));
            curr_command->display();

            //end condition
        }
    }
    else {
        std::cout << "Error opening the File\n";
        exit(0);
    }
}