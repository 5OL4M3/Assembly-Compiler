#include <string>
#include <map>
#include <iostream>
#include "statement_buffer.h"
#include "string_buffer.h"
#include "map.h"
#include "symbol_table.h"
#include "command.h"
#include "functions.h"

//Command

Command::Command(){}
Command::Command(const Command& orig){
}

Command::~Command(){}
//check the number of arguments and argument values in this function
//enter the values into the symbol table
void Command::assign_args(std::string _myline) {
	//find number of args
	int num_args = 0;
	for(int i = 0; i < _myline.length(); i++) {

		if(_myline[i] == 32) {
			num_args++;
		}
	}

	if(num_args != expected) {
		std::cout << "ERROR:\n  Invalid input arguments!";
		exit(0);
	}
	//assign corresponding arguments
	std::string temp_string = "";
	for(int i = 0; i < _myline.length(); i++) {
		temp_string += _myline[i];
		if(_myline[i] == 32) {
			if (expected == 2) {
				var1 = cleanString(temp_string);
			}
			temp_string = "";
		}
		if(i == _myline.length() - 1) {
			//last iteration of the loop
			if (expected == 1) {
				var1 = cleanString(temp_string);
			}
			else {
				var2 = cleanString(temp_string);
			}
		}
	}
	//check if data type is consistent
	//Check type of var1
	if (expected == 0 || data_type1 == "b") {
		return;
	}

	std::string var1_type;
	if (isalpha(var1[0])){
		var1_type = "s";
	}
	else{
		for(int i = 0; i < var1.length(); i++){
			if (isalpha(var1[i])){
				std::cout << "Error! Variables can't start with an int and int can't start with an char\n";
				exit(0);
			}
		}
		var1_type = "i";
	}
	if (var1_type != data_type1){
		std::cout << "Error! First argument is of incorrect type\n";
		exit(0);
	}

	if (expected == 2){
		std::string var2_type;
		if (isalpha(var2[0])){
			var2_type = "s";
		}
		else{
			for(int i = 0; i < var2.length(); i++){
				if (isalpha(var2[i])){
					std::cout << "Error! Variables can't start with an int and int can't start with an char\n";
					exit(0);
				}
			}
			var2_type = "i";
		}
		if (var2_type != data_type2){
			std::cout << "Error! Second argument is of incorrect type\n";
			exit(0);
		}
	}
}

void Command::display(){}
void Command::add(){}
std::string Command::get_instruction(){}
void Command::perform_update(){} //updates the count 
int Command::get_count(){}


Command* getCommand(int ind) {
    Command* curr_command;
    if(ind == 0){
        curr_command =new Declscal();
        return curr_command;
    }
    else if(ind == 1) {
        curr_command =new Declarr();
        return curr_command;
    }
    else if(ind == 2) {
        curr_command =new Label();
        return curr_command;
    }
    else if(ind == 3) {
        curr_command =new Gosublabel();
        return curr_command;
    }
    else if(ind == 4) {
        curr_command =new Start();
        return curr_command;
    }
    else if(ind == 5) {
        curr_command =new End();
        return curr_command;
    }
    else if(ind == 6) {
        curr_command =new Exit();
        return curr_command;
    }
    else if(ind == 7) {
        curr_command =new Jump();
        return curr_command;
    }
    else if(ind == 8) {
        curr_command =new Jumpzero();
        return curr_command;
    }
    else if(ind == 9) {
        curr_command =new Jumpnzero();
        return curr_command;
    }
    else if(ind == 10) {
        curr_command =new Gosub();
        return curr_command;
    }
    else if(ind == 11) {
        curr_command =new Return();
        return curr_command;
    }
    else if(ind == 12) {
        curr_command =new Pushscal();
        return curr_command;
    }
    else if(ind == 13) {
        curr_command =new Pusharr();
        return curr_command;
    }
    else if(ind == 14) {
        curr_command =new Pushi();
        return curr_command;
    }
    else if(ind == 15) {
        curr_command =new Pop();
        return curr_command;
    }
    else if(ind == 16) {
        curr_command =new Popscal();
        return curr_command;
    }
    else if(ind == 17) {
        curr_command =new Poparr();
        return curr_command;
    }
    else if(ind == 18) {
        curr_command =new Dup();
        return curr_command;
    }
    else if(ind == 19) {
        curr_command =new Swap();
        return curr_command;
    }
    else if(ind == 20) {
        curr_command =new Add();
        return curr_command;
    }
    else if(ind == 21) {
        curr_command =new Negate();
        return curr_command;
    }
    else if(ind == 22) {
        curr_command =new Mul();
        return curr_command;
    }
    else if(ind == 23) {
        curr_command =new Div();
        return curr_command;
    }
    else if(ind == 24) {
        curr_command =new Printtos();
        return curr_command;
    }
    else if(ind == 25) {
        curr_command =new Prints();
        return curr_command;
    }
}

//Declscal 
Declscal::Declscal( ) {
	expected = 1;
	data_type1 = "s";
	data_size = 1;
}

void Declscal::display( ) {
	//std::cout << "Declscal called" << std::endl;
}

void Declscal::add( ){
	if(Symbol_Table::find_location(var1, scope, 0) != -1) {
		std::cout << "error: attempting to add variable with name " << var1 << " twice\n";
		exit(0);
	}
	Symbol_Table* symbol_table = Symbol_Table::create_symbol_table();
	if (scope == 1){
        Symbol_Table::num_var_scope1 +=1;
    }
    else if (scope == 2){
        Symbol_Table::num_var_scope2 +=1;
    }
	Symbol_Table::add_symbol(this, 1);
}

std::string Declscal::get_instruction( ){
}

int Declscal::get_count( ){
}

void Declscal::perform_update(){
}

//Declarr
Declarr::Declarr( ) {
	expected = 2;
	data_type1 = "s";
	data_type2 = "i";
}

void Declarr::display( ) {}

void Declarr::add( ){
	if(Symbol_Table::find_location(var1, scope, 1) != -1) {
		std::cout << "error: attempting to add variable with name " << var1 << " twice\n";
		exit(0);
	}
	Symbol_Table* symbol_table = Symbol_Table::create_symbol_table();
	Symbol_Table::add_symbol(this, 2); 
}

std::string Declarr::get_instruction( ){
	//std::cout << "Retrieving Instruction" << std::endl;
}

int Declarr::get_count( ){
	//std::cout << "Retrieving Count" << std::endl;
}

void Declarr::perform_update(){
}

//Label
Label::Label( ) {
	expected = 1;
	data_type1 = "s";
	data_size = 0;
}

void Label::display( ) {
}

void Label::add( ){
	if(Symbol_Table::find_location(var1, scope, 0) != -1) {
		std::cout << "error: attempting to add variable with name " << var1 << " twice\n";
		exit(0);
	}
	Symbol_Table* symbol_table = Symbol_Table::create_symbol_table();
	Symbol_Table::add_symbol(this, 0); 
}

std::string Label::get_instruction( ){
	//std::cout << "Retrieving Instruction" << std::endl;
}

int Label::get_count( ){
	//std::cout << "Retrieving Count" << std::endl;
}

void Label::perform_update(){
}

//Gosublabel
Gosublabel::Gosublabel( ) {
	expected = 1;
	data_type1 = "s";
	data_size = 0;
	need_update = 1;
	change_scope = 1;
	count = -1;
}

void Gosublabel::display( ) {
}

void Gosublabel::add( ){
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	Statement_Buffer::add_statement(this);
	Symbol_Table* symbol_table = Symbol_Table::create_symbol_table();
	Symbol_Table::add_symbol(this, 3);
}

std::string Gosublabel::get_instruction( ){
	//std::cout << "Retrieving Instruction" << std::endl;
	return instruction;
}

int Gosublabel::get_count( ){
	//std::cout << "Retrieving Count" << std::endl;
	return count;
}

void Gosublabel::perform_update(){
	//this could be an issue later on; we are assuming that there are no nested subroutines
	count = Symbol_Table::num_var_scope2;

}

//Start
Start::Start ( ){
	expected = 0;		
	need_update = 1;
	count = -1;
}
void Start::display( ){
}
void Start::add( ){
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	Statement_Buffer::add_statement(this);
}

std::string Start::get_instruction( ){
	return instruction;
}

int Start::get_count( ){
	return count;
}

void Start::perform_update(){
	count = Symbol_Table::num_var_scope1;
}

//End
End::End( ) {
	expected = 0;		
}

void End::display( ) {
}

void End::add( ){
	Statement_Buffer::update_count(scope);
}

std::string End::get_instruction( ){
}

int End::get_count( ){
}

void End::perform_update(){
}

//Exit
Exit::Exit( ) {
	int expected = 0;		//JM
	count = -1;
}

void Exit::display( ) {
}

void Exit::add( ){
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	Statement_Buffer::add_statement(this);
}

std::string Exit::get_instruction( ){
	//std::cout << "Retrieving Instruction" << std::endl;
	return instruction;
}

int Exit::get_count( ){
	//std::cout << "Retrieving Count" << std::endl;
	return count;
}

void Exit::perform_update(){
}

//Jump
Jump::Jump( ) {
	expected = 1;
	data_type1 = "s";
	need_update = 1;
	count = -1;
}

void Jump::display( ) {
}

void Jump::add( ){
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	Statement_Buffer::add_statement(this);
}

std::string Jump::get_instruction( ){
	//std::cout << "Retrieving Instruction" << std::endl;
	return instruction;
}

int Jump::get_count( ){
	//std::cout << "Retrieving Count" << std::endl;
	return count;
}

void Jump::perform_update(){
	Symbol_Table * symbol_table = Symbol_Table::create_symbol_table();
	count = Symbol_Table::find_location(var1, scope, 0);
}

//Jumpzero
Jumpzero::Jumpzero( ) {
	expected = 1;
	data_type1 = "s";
	need_update = 1;
	count = -1;
}

void Jumpzero::display( ) {
}

void Jumpzero::add( ){
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	Statement_Buffer::add_statement(this);
}

std::string Jumpzero::get_instruction( ){
	//std::cout << "Retrieving Instruction" << std::endl;
	return instruction;
}

int Jumpzero::get_count( ){
	//std::cout << "Retrieving Count" << std::endl;
	return count;
}

void Jumpzero::perform_update(){
	Symbol_Table * symbol_table = Symbol_Table::create_symbol_table();
	count = Symbol_Table::find_location(var1, scope, 0);
}

//Jumpnzero
Jumpnzero::Jumpnzero( ) {
	expected = 1;
	data_type1 = "s";
	need_update = 1;
	count = -1;
}

void Jumpnzero::display( ) {
}

void Jumpnzero::add( ){
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	Statement_Buffer::add_statement(this);
}

std::string Jumpnzero::get_instruction( ){
	//std::cout << "Retrieving Instruction" << std::endl;
	return instruction;
}

int Jumpnzero::get_count( ){
	//std::cout << "Retrieving Count" << std::endl;
	return count;
}

void Jumpnzero::perform_update(){
	std::cout << "Updating the count" << std::endl;
	Symbol_Table * symbol_table = Symbol_Table::create_symbol_table();
	count = Symbol_Table::find_location(var1, scope, 0);
}

//Gosub
Gosub::Gosub( ) {
	expected = 1;
	data_type1 = "s";
	need_update = 1;
	count = -1;
}

void Gosub::display( ) {
}

void Gosub::add( ){
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	Statement_Buffer::add_statement(this);
}

std::string Gosub::get_instruction( ){
	//std::cout << "Retrieving Instruction" << std::endl;
	return instruction;
}

int Gosub::get_count( ){
	//std::cout << "Retrieving Count" << std::endl;
	return count;
}

void Gosub::perform_update(){
	Symbol_Table * symbol_table = Symbol_Table::create_symbol_table();
	count = Symbol_Table::find_location(var1, scope, 0);
}

//Return
Return::Return( ) {
	expected = 0;		
	change_scope = -1;
	count = -1;
}

void Return::display( ) {
}

void Return::add( ){
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	Statement_Buffer::add_statement(this);
	Statement_Buffer::update_count(scope);
}

std::string Return::get_instruction( ){
	//std::cout << "Retrieving Instruction" << std::endl;
	return instruction;
}

int Return::get_count( ){
	//std::cout << "Retrieving Count" << std::endl;
	return count;
}

void Return::perform_update(){
}

//Pushscal
Pushscal::Pushscal( ) {
	expected = 1;
	data_type1 = "s";
	count = -1;
}

void Pushscal::display( ) {
}

void Pushscal::add( ){
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	count = Symbol_Table::find_location(var1, scope, 0);
	Statement_Buffer::add_statement(this);
}

std::string Pushscal::get_instruction( ){
	return instruction;
}

int Pushscal::get_count( ){
	return count;
}

void Pushscal::perform_update(){
}

//Pusharr
Pusharr::Pusharr( ) {
	expected = 1;
	data_type1 = "s";
	count = -1;
}

void Pusharr::display( ) {
}

void Pusharr::add( ){
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	count = Symbol_Table::find_location(var1, scope, 1);
	Statement_Buffer::add_statement(this);
}

std::string Pusharr::get_instruction( ){
	//std::cout << "Retrieving Instruction" << std::endl;
	return instruction;
}

int Pusharr::get_count( ){
	//std::cout << "Retrieving Count" << std::endl;
	return count;
}

void Pusharr::perform_update(){
}

//Pushi
Pushi::Pushi( ) {
	expected = 1;
	data_type1 = "i";
	count = -1;
}

void Pushi::display( ) {
}

void Pushi::add( ){
	count = stoi(var1);		//set count to corresponding integer value
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	Statement_Buffer::add_statement(this);
}

std::string Pushi::get_instruction( ){
	//std::cout << "Retrieving Instruction" << std::endl;
	return instruction;
}

int Pushi::get_count( ){
	//std::cout << "Retrieving Count" << std::endl;
	return count;
}

void Pushi::perform_update(){
}

//Pop
Pop::Pop( ) {
	expected = 0; 	//JM
}

void Pop::display( ) {
}

void Pop::add( ){
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	Statement_Buffer::add_statement(this);
}

std::string Pop::get_instruction( ){
	//std::cout << "Retrieving Instruction" << std::endl;
	return instruction;
}

int Pop::get_count( ){
	//std::cout << "Retrieving Count" << std::endl;
	return count;
}

void Pop::perform_update(){
}

//Popscal
Popscal::Popscal( ) {
	expected = 1;
	data_type1 = "s";
	count = -1;
}

void Popscal::display( ) {
}

void Popscal::add( ){
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	
	count = Symbol_Table::find_location(var1, scope, 0);
	Statement_Buffer::add_statement(this);
}

std::string Popscal::get_instruction( ){
	//std::cout << "Retrieving Instruction" << std::endl;
	return instruction;
}

int Popscal::get_count( ){
	//std::cout << "Retrieving Count" << std::endl;
	return count;
}

void Popscal::perform_update(){
}

//Poparr
Poparr::Poparr( ) {
	expected = 1;
	data_type1 = "s";
	count = -1;
}

void Poparr::display( ) {
}

void Poparr::add( ){
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	count = Symbol_Table::find_location(var1, scope, 1);
	Statement_Buffer::add_statement(this);
}

std::string Poparr::get_instruction( ){
	//std::cout << "Retrieving Instruction" << std::endl;
	return instruction;
}

int Poparr::get_count( ){
	//std::cout << "Retrieving Count" << std::endl;
	return count;
}

void Poparr::perform_update(){
}

//Dup
Dup::Dup( ) {
	expected = 0; 	//JM
	count = -1;
}

void Dup::display( ) {
}

void Dup::add( ){
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	Statement_Buffer::add_statement(this);
}

std::string Dup::get_instruction( ){
	//std::cout << "Retrieving Instruction" << std::endl;
	return instruction;
}

int Dup::get_count( ){
	//std::cout << "Retrieving Count" << std::endl;
	return count;
}

void Dup::perform_update(){
}

//Swap
Swap::Swap( ) {
	expected = 0; 	//JM
	count = -1;
}

void Swap::display( ) {
}

void Swap::add( ){
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	Statement_Buffer::add_statement(this);
}

std::string Swap::get_instruction( ){
	//std::cout << "Retrieving Instruction" << std::endl;
	return instruction;
}

int Swap::get_count( ){
	//std::cout << "Retrieving Count" << std::endl;
	return count;
}

void Swap::perform_update(){
}

//Add
Add::Add( ) {
	expected = 0; 	//JM
	count = -1;
}

void Add::display( ) {
}

void Add::add( ){
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	Statement_Buffer::add_statement(this);
}

std::string Add::get_instruction( ){
	//std::cout << "Retrieving Instruction" << std::endl;
	return instruction;
}

int Add::get_count( ){
	//std::cout << "Retrieving Count" << std::endl;
	return count;
}

void Add::perform_update(){
}

//Negate
Negate::Negate( ) {
	expected = 0; 	//JM
	count = -1;
}

void Negate::display( ) {
}

void Negate::add( ){
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	Statement_Buffer::add_statement(this);
}

std::string Negate::get_instruction( ){
	//std::cout << "Retrieving Instruction" << std::endl;
	return instruction;
}

int Negate::get_count( ){
	//std::cout << "Retrieving Count" << std::endl;
	return count;
}

void Negate::perform_update(){
}

//Mul
Mul::Mul( ) {
	expected = 0; 	//JM
	count = -1;
}

void Mul::display( ) {
}

void Mul::add( ){
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	Statement_Buffer::add_statement(this);
}

std::string Mul::get_instruction( ){
	//std::cout << "Retrieving Instruction" << std::endl;
	return instruction;
}

int Mul::get_count( ){
	//std::cout << "Retrieving Count" << std::endl;
	return count;
}

void Mul::perform_update(){
}

//Div
Div::Div( ) {
	expected = 0; 	//JM
	count = -1;
}

void Div::display( ) {
}

void Div::add( ){
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	Statement_Buffer::add_statement(this);
}

std::string Div::get_instruction( ){
	//std::cout << "Retrieving Instruction" << std::endl;
	return instruction;
}

int Div::get_count( ){
	//std::cout << "Retrieving Count" << std::endl;
	return count;
}

void Div::perform_update(){
}

//Printtos
Printtos::Printtos( ) {
	expected = 0;
	count = -1;
}

void Printtos::display( ) {
}

void Printtos::add( ){
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	Statement_Buffer::add_statement(this);
}

std::string Printtos::get_instruction( ){
	//std::cout << "Retrieving Instruction" << std::endl;
	return instruction;
}

int Printtos::get_count( ){
	//std::cout << "Retrieving Count" << std::endl;
	return count;
	count = -1;
}

void Printtos::perform_update(){
}

//Prints
Prints::Prints( ) {
	expected = 1;
	data_type1 = "b"; 
	count = -1;
	need_update = 1;
}

void Prints::display( ) {
}

void Prints::add( ){
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	Statement_Buffer::add_statement(this);
	String_Buffer * string_buffer = String_Buffer::create_string_buffer();
	String_Buffer::add_statement(this);
}

std::string Prints::get_instruction( ){
	//std::cout << "Retrieving Instruction" << std::endl;
	return instruction;
}

int Prints::get_count( ){
	//std::cout << "Retrieving Count" << std::endl;
	return count;
}

void Prints::perform_update(){
	String_Buffer * string_vector = String_Buffer::create_string_buffer();
	count = String_Buffer::find_location(var1);
}

