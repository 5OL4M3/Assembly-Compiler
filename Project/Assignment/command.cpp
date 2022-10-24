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
Command::Command(const Command& p1){}

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
				std::cout << "Variables can't start with an int and int can't start with an char\n";
				exit(0);
			}
		}
		var1_type = "i";
	}
	if (var1_type != data_type1){
		std::cout << "First argument is of incorrect type\n";
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
					std::cout << "Variables can't start with an int and int can't start with an char\n";
					exit(0);
				}
			}
			var2_type = "i";
		}
		if (var2_type != data_type2){
			std::cout << "Second argument is of incorrect type\n";
			exit(0);
		}
	}
}

//Declscal 
Declscal::Declscal( ) {
	expected = 1;
	data_type1 = "s";
	data_size = 1;
}

void Declscal::display( ) {
	std::cout << "Declscal called" << std::endl;
}

void Declscal::add( ){
	std::cout << "Adding to Symbol Table" << std::endl;
	Symbol_Table* symbol_table = Symbol_Table::create_symbol_table();
	if (scope == 1){
        Symbol_Table::num_var_scope1 +=1;
    }
    else if (scope == 2){
        Symbol_Table::num_var_scope2 +=1;
    }
	Symbol_Table::add_symbol(this);

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

void Declarr::display( ) {
	std::cout << "Declarr called" << std::endl;}

void Declarr::add( ){
	std::cout << "Adding to Symbol Table" << std::endl;
	Symbol_Table* symbol_table = Symbol_Table::create_symbol_table();
	if (scope == 1){
        Symbol_Table::num_var_scope1 +=1;
    }
    else if (scope == 2){
        Symbol_Table::num_var_scope2 +=1;
    }
	Symbol_Table::add_symbol(this); 
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
	add_index = 1;
}

void Label::display( ) {
	std::cout << "Label called" << std::endl;
}

void Label::add( ){
	std::cout << "Adding to Symbol Table" << std::endl;
	Symbol_Table* symbol_table = Symbol_Table::create_symbol_table();
	Symbol_Table::add_symbol(this); 
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
std::cout << "Gosublabel called" << std::endl;
}

void Gosublabel::add( ){
	std::cout << "Adding to Instruction Buffer" << std::endl;
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	Statement_Buffer::add_statement(this);
	std::cout << "Adding to Symbol Table" << std::endl;
	Symbol_Table* symbol_table = Symbol_Table::create_symbol_table();
	Symbol_Table::add_symbol(this);
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
	std::cout << scope << "\n";
	std::cout << "Updating the count" << std::endl;
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
	std::cout << "Start called" << std::endl;
}
void Start::add( ){
	std::cout << "Adding to Instruction Buffer" << std::endl;
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	Statement_Buffer::add_statement(this);
}

std::string Start::get_instruction( ){
	std::cout << "Retrieving Instruction" << std::endl;
	return instruction;
}

int Start::get_count( ){
	std::cout << "Retrieving Count" << std::endl;
	return count;
}

void Start::perform_update(){
	std::cout << "Updating the count" << std::endl;
	count = Symbol_Table::num_var_scope1;
}

//End
End::End( ) {
	expected = 0;		
}

void End::display( ) {
std::cout << "End called" << std::endl;
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
	std::cout << "Exit called" << std::endl;
}

void Exit::add( ){
	std::cout << "Adding to Instruction Buffer" << std::endl;
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
	std::cout << "Jump called" << std::endl;
}

void Jump::add( ){
	std::cout << "Adding to Instruction Buffer" << std::endl;
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
	std::cout << "Updating the count" << std::endl;
	Symbol_Table * symbol_table = Symbol_Table::create_symbol_table();
	count = Symbol_Table::find_location(var1, scope);
}

//Jumpzero
Jumpzero::Jumpzero( ) {
	expected = 1;
	data_type1 = "s";
	need_update = 1;
	count = -1;
}

void Jumpzero::display( ) {
	std::cout << "Jumpzero called" << std::endl;
}

void Jumpzero::add( ){
	std::cout << "Adding to Instruction Buffer" << std::endl;
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
	std::cout << "Updating the count" << std::endl;
	Symbol_Table * symbol_table = Symbol_Table::create_symbol_table();
	count = Symbol_Table::find_location(var1, scope);
}

//Jumpnzero
Jumpnzero::Jumpnzero( ) {
	expected = 1;
	data_type1 = "s";
	need_update = 1;
	count = -1;
}

void Jumpnzero::display( ) {
	std::cout << "Jumpnzero called" << std::endl;
}

void Jumpnzero::add( ){
	std::cout << "Adding to Instruction Buffer" << std::endl;
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
	count = Symbol_Table::find_location(var1, scope);
}

//Gosub
Gosub::Gosub( ) {
	expected = 1;
	data_type1 = "s";
	need_update = 1;
	count = -1;
}

void Gosub::display( ) {
	std::cout << "Gosub called" << std::endl;
}

void Gosub::add( ){
	std::cout << "Adding to Instruction Buffer" << std::endl;
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
	std::cout << "Updating the count" << std::endl;
}

//Return
Return::Return( ) {
	expected = 0;		
	change_scope = -1;
	count = -1;
}

void Return::display( ) {
	std::cout << "Return called" << std::endl;
}

void Return::add( ){
	std::cout << "Adding to Instruction Buffer" << std::endl;
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
	std::cout << "Pushscal called" << std::endl;
}

void Pushscal::add( ){
	std::cout << "Adding to Instruction Buffer" << std::endl;
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	count = Symbol_Table::find_location(var1, scope);
	Statement_Buffer::add_statement(this);
}

std::string Pushscal::get_instruction( ){
	std::cout << "Retrieving Instruction" << std::endl;
	return instruction;
}

int Pushscal::get_count( ){
	std::cout << "Retrieving Count" << std::endl;
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
	std::cout << "Pusharr called" << std::endl;
}

void Pusharr::add( ){
	std::cout << "Adding to Instruction Buffer" << std::endl;
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
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
	std::cout << "Pushi called" << std::endl;
}

void Pushi::add( ){
	count = stoi(var1);		//set count to corresponding integer value
	std::cout << "Adding to Instruction Buffer" << std::endl;
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
	std::cout << "Pop called" << std::endl;
}

void Pop::add( ){
	std::cout << "Adding to Instruction Buffer" << std::endl;
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
	std::cout << "Popscal called" << std::endl;
}

void Popscal::add( ){
	std::cout << "Adding to Instruction Buffer" << std::endl;
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	std::cout << "Prior Count" << count << "\n";
	count = Symbol_Table::find_location(var1, scope);
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
	std::cout << "Poparr called" << std::endl;
}

void Poparr::add( ){
	std::cout << "Adding to Instruction Buffer" << std::endl;
	Statement_Buffer * buffer_statement = Statement_Buffer::create_statement_buffer();
	count = Symbol_Table::find_location(var1, scope);
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
	std::cout << "Dup called" << std::endl;
}

void Dup::add( ){
	std::cout << "Adding to Instruction Buffer" << std::endl;
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
	std::cout << "Swap called" << std::endl;
}

void Swap::add( ){
	std::cout << "Adding to Instruction Buffer" << std::endl;
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
	std::cout << "Add called" << std::endl;
}

void Add::add( ){
	std::cout << "Adding to Instruction Buffer" << std::endl;
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
	std::cout << "Negate called" << std::endl;
}

void Negate::add( ){
	std::cout << "Adding to Instruction Buffer" << std::endl;
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
	std::cout << "Mul called" << std::endl;
}

void Mul::add( ){
	std::cout << "Adding to Instruction Buffer" << std::endl;
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
	std::cout << "Div called" << std::endl;
}

void Div::add( ){
	std::cout << "Adding to Instruction Buffer" << std::endl;
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
	std::cout << "Printtos called" << std::endl;
}

void Printtos::add( ){
	std::cout << "Adding to Instruction Buffer" << std::endl;
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
}

void Prints::display( ) {
	std::cout << "Prints called" << std::endl;
}

void Prints::add( ){
	std::cout << "Adding to Instruction Buffer" << std::endl;
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
}

