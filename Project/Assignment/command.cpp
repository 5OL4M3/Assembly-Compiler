#include <string>
#include <map>
#include <iostream>
#include "statement_buffer.h"
#include "map.h"
#include "symbol_table.h"
#include "command.h"

Command::Command(){}

//Declscal
Declscal::Declscal( ) {
	check = true;	//indicates whether we check for more parameters for eg. A in declscal A
}

void Declscal::display( ) {
std::cout << "Declscal called" << std::endl;
}

//Declarr
Declarr::Declarr( ) {
	check = true;	
}

void Declarr::display( ) {
std::cout << "Declarr called" << std::endl;}

//Label
Label::Label( ) {
	bool check = true;
}

void Label::display( ) {
std::cout << "Label called" << std::endl;
}

//Gosublabel
Gosublabel::Gosublabel( ) {
	bool check = true;
}

void Gosublabel::display( ) {
std::cout << "Gosublabel called" << std::endl;
}

//End
End::End( ) {
	bool check = false;
}

void End::display( ) {
std::cout << "End called" << std::endl;
}

//Exit
Exit::Exit( ) {
	bool check = false;
}

void Exit::display( ) {
std::cout << "Exit called" << std::endl;
}

//Jump
Jump::Jump( ) {
	bool check = true;
}

void Jump::display( ) {
std::cout << "Jump called" << std::endl;
}

//Jumpzero
Jumpzero::Jumpzero( ) {
	bool check = true;
}

void Jumpzero::display( ) {
std::cout << "Jumpzero called" << std::endl;
}

//Jumpnzero
Jumpnzero::Jumpnzero( ) {
	bool check = true;
}

void Jumpnzero::display( ) {
std::cout << "Jumpnzero called" << std::endl;
}

//Gosub
Gosub::Gosub( ) {
	bool check = true;
}

void Gosub::display( ) {
std::cout << "Gosub called" << std::endl;
}

//Return
Return::Return( ) {
	bool check = false;
}

void Return::display( ) {
std::cout << "Return called" << std::endl;
}

//Pushscal
Pushscal::Pushscal( ) {
	bool check = true;
}

void Pushscal::display( ) {
std::cout << "Pushscal called" << std::endl;
}

//Pusharr
Pusharr::Pusharr( ) {
	bool check = true;
}

void Pusharr::display( ) {
std::cout << "Pusharr called" << std::endl;
}

//Pushi
Pushi::Pushi( ) {
	check = true;
	expected = 1;
}

void Pushi::display( ) {
std::cout << "Pushi called" << std::endl;
}

//Pop
Pop::Pop( ) {
	check = false;
}

void Pop::display( ) {
std::cout << "Pop called" << std::endl;
}

//Popscal
Popscal::Popscal( ) {
	check = true;
}

void Popscal::display( ) {
std::cout << "Popscal called" << std::endl;
}

//Poparr
Poparr::Poparr( ) {
	check = true;
}

void Poparr::display( ) {
std::cout << "Poparr called" << std::endl;
}

//Dup
Dup::Dup( ) {
	check = false;
}

void Dup::display( ) {
std::cout << "Dup called" << std::endl;
}

//Swap
Swap::Swap( ) {
	check = false;
}

void Swap::display( ) {
std::cout << "Swap called" << std::endl;
}

//Add
Add::Add( ) {
	check = false;
}

void Add::display( ) {
std::cout << "Add called" << std::endl;
}

//Negate
Negate::Negate( ) {
	check = false;
}

void Negate::display( ) {
std::cout << "Negate called" << std::endl;
}

//Mul
Mul::Mul( ) {
	check = false;
}

void Mul::display( ) {
std::cout << "Mul called" << std::endl;
}

//Div
Div::Div( ) {
	check = false;
}

void Div::display( ) {
std::cout << "Div called" << std::endl;
}

//Printtos
Printtos::Printtos( ) {
	check = false;
}

void Printtos::display( ) {
std::cout << "Printtos called" << std::endl;
}

//Prints
Prints::Prints( ) {
	check = true;
}

void Prints::display( ) {
std::cout << "Prints called" << std::endl;
}

//check the number of arguments and argument values in this function
//enter the values into the symbol table
bool Command::check_args(std::string _myline) {
	
	return true;
}
