#include <iostream>
#include <fstream>
#include <vector>
#include "statement_buffer.h"
#include "map.h"
#include "symbol_table.h"
#include "command.h"
#include "functions.h"
#include "string_buffer.h"
#define COMMAND_AMOUNT 26


int main(int argc, char** argv){
    //Array for the lists of Command 
    bool big_boolean = false;       //tells us whether we ended with end
    std::string command_list[COMMAND_AMOUNT] = {"declscal", "declarr", "label", 
    "gosublabel", "start", "end", "exit", "jump", "jumpzero", "jumpnzero", "gosub", "return",
    "pushscal", "pusharr", "pushi", "pop", "popscal", "poparr", "dup", "swap", "add", "negate", "mul",
    "div", "printtos", "prints"};
    //Array for the Command Objects
    Command * object_list[COMMAND_AMOUNT] = {new Declscal( ), new Declarr( ), new Label( ), new Gosublabel( ), new Start( ),
    new End( ), new Exit( ), new Jump( ), new Jumpzero( ), new Jumpnzero( ), new Gosub( ), new Return( ), new Pushscal( ),
    new Pusharr( ), new Pushi( ), new Pop( ), new Popscal( ), new Poparr( ), new Dup( ), new Swap( ), new Add( ), new Negate( ), 
    new Mul( ), new Div( ), new Printtos( ), new Prints( )};
    
    //Create Map for the commands
    Map * command_map = new Map();
    for (int i = 0; i < COMMAND_AMOUNT; i++){
        command_map->insert(command_list[i], object_list[i]);
    }
    //Declare the Scope:
    int scope = 1; 

    //Create Symbol Table:
    Symbol_Table * symbol_table = Symbol_Table::create_symbol_table();

    //Create Statement/Instruction Buffer:
    Statement_Buffer * statement_buffer = Statement_Buffer::create_statement_buffer();

    //Create String Buffer:
    String_Buffer * string_buffer = String_Buffer::create_string_buffer();
    //Opening the file
    std::ifstream myfile;
    myfile.open(argv[1]);
    std::string myline;
    if (myfile.is_open()){
       	//REPEATING END CONDITION FIXED - Joseph 
		
        //Check for start in the beginning of the file
        std::getline(myfile, myline);
        myline = cleanString(myline);
        if (myline != "start"){
            std::cout << "No start or start has an argument\n";
            exit(0);
        }
        Command* curr_command = getCommand(lookString(myline, command_list));
        curr_command->scope = scope;
        curr_command->display();
        curr_command->add();
        std::cout << "Index: " << Statement_Buffer::index << "\n";
        //Check rest of the file
        while (myfile.good()){
            std::getline(myfile, myline);
            myline = cleanString(myline);
			//shift the substr(0, myline.find(" "))) into the class
			Command* curr_command = getCommand(lookString(myline, command_list));
            std::cout << "\n--Scope: " << scope <<"\n";	
            curr_command->scope = scope;
			curr_command->display();
            curr_command -> assign_args(myline);
            curr_command->add();
            scope = scope + curr_command->change_scope;
            /* std::cout << "Index: " << Statement_Buffer::index << "\n";
            std::cout << "1: " << Symbol_Table::num_var_scope1 << " 2: " << Symbol_Table::num_var_scope2 << "\n"; */
            if (myline == "end")
            {
                big_boolean = true;
                break;
            }
        }
        //Checks if there are any commands after end
        while (myfile.good()){
            std::getline(myfile, myline);
            myline = cleanString(myline);
            if (myline.length() !=0){
                std::cout << "ERROR:\n  There is non-space characters after end\n";
                exit(0);
            }
        }
    }
    else {
        std::cout << "ERROR:\n  Error opening the File\n";
        exit(0);
    }
    if (big_boolean == false) {
        std::cout << "error: no end statement in program";
        exit(0);
    }
    symbol_table->printContent();
    string_buffer -> printContent();
    statement_buffer->printContent();
    
}
