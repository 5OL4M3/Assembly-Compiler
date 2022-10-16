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
}

void Declscal::display( ) {
std::cout << "Declscal called" << std::endl;
}

//Declarr
Declarr::Declarr( ) {
}

void Declarr::display( ) {
std::cout << "Declarr called" << std::endl;}

//Label
Label::Label( ) {
}

void Label::display( ) {
std::cout << "Label called" << std::endl;
}

//Gosublabel
Gosublabel::Gosublabel( ) {
}

void Gosublabel::display( ) {
std::cout << "Gosublabel called" << std::endl;
}

//End
End::End( ) {
}

void End::display( ) {
std::cout << "End called" << std::endl;
}

//Exit
Exit::Exit( ) {
}

void Exit::display( ) {
std::cout << "Exit called" << std::endl;
}

//Jump
Jump::Jump( ) {
}

void Jump::display( ) {
std::cout << "Jump called" << std::endl;
}

//Jumpzero
Jumpzero::Jumpzero( ) {
}

void Jumpzero::display( ) {
std::cout << "Jumpzero called" << std::endl;
}

//Jumpnzero
Jumpnzero::Jumpnzero( ) {
}

void Jumpnzero::display( ) {
std::cout << "Jumpnzero called" << std::endl;
}

//Gosub
Gosub::Gosub( ) {
}

void Gosub::display( ) {
std::cout << "Gosub called" << std::endl;
}

//Return
Return::Return( ) {
}

void Return::display( ) {
std::cout << "Return called" << std::endl;
}

//Pushscal
Pushscal::Pushscal( ) {
}

void Pushscal::display( ) {
std::cout << "Pushscal called" << std::endl;
}

//Pusharr
Pusharr::Pusharr( ) {
}

void Pusharr::display( ) {
std::cout << "Pusharr called" << std::endl;
}

//Pushi
Pushi::Pushi( ) {
}

void Pushi::display( ) {
std::cout << "Pushi called" << std::endl;
}

//Pop
Pop::Pop( ) {
}

void Pop::display( ) {
std::cout << "Pop called" << std::endl;
}

//Popscal
Popscal::Popscal( ) {
}

void Popscal::display( ) {
std::cout << "Popscal called" << std::endl;
}

//Poparr
Poparr::Poparr( ) {
}

void Poparr::display( ) {
std::cout << "Poparr called" << std::endl;
}

//Dup
Dup::Dup( ) {
}

void Dup::display( ) {
std::cout << "Dup called" << std::endl;
}

//Swap
Swap::Swap( ) {
}

void Swap::display( ) {
std::cout << "Swap called" << std::endl;
}

//Add
Add::Add( ) {
}

void Add::display( ) {
std::cout << "Add called" << std::endl;
}

//Negate
Negate::Negate( ) {
}

void Negate::display( ) {
std::cout << "Negate called" << std::endl;
}

//Mul
Mul::Mul( ) {
}

void Mul::display( ) {
std::cout << "Mul called" << std::endl;
}

//Div
Div::Div( ) {
}

void Div::display( ) {
std::cout << "Div called" << std::endl;
}

//Printtos
Printtos::Printtos( ) {
}

void Printtos::display( ) {
std::cout << "Printtos called" << std::endl;
}

//Prints
Prints::Prints( ) {
}

void Prints::display( ) {
std::cout << "Prints called" << std::endl;
}