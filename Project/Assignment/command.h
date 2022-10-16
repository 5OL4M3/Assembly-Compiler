#ifndef COMMAND_H_
#define COMMAND_H_
#include "statement_buffer.h"
#include "map.h"
#include "symbol_table.h"

class Command{
public:
    Command();
    int temp;
    virtual void display() = 0;
private:
    std::string syntax;
};

//-----Commands:
//Declscal
class Declscal:public Command {
public:
    Declscal( );
    void display( );
};


//Declarr
class Declarr:public Command {
public:
    Declarr( );
    void display( );
};


//Label
class Label:public Command {
public:
    Label( );
    void display( );
};


//Gosublabel
class Gosublabel:public Command {
public:
    Gosublabel( );
    void display( );
};


//End
class End:public Command {
public:
    End( );
    void display( );
};


//Exit
class Exit:public Command {
public:
    Exit( );
    void display( );
};


//Jump
class Jump:public Command {
public:
    Jump( );
    void display( );
};


//Jumpzero
class Jumpzero:public Command {
public:
    Jumpzero( );
    void display( );
};


//Jumpnzero
class Jumpnzero:public Command {
public:
    Jumpnzero( );
    void display( );
};


//Gosub
class Gosub:public Command {
public:
    Gosub( );
    void display( );
};

//Return
class Return:public Command {
public:
    Return( );
    void display( );
};


//Pushscal
class Pushscal:public Command {
public:
    Pushscal( );
    void display( );
};


//Pusharr
class Pusharr:public Command {
public:
    Pusharr( );
    void display( );
};


//Pushi
class Pushi:public Command {
public:
    Pushi( );
    void display( );
};


//Pop
class Pop:public Command {
public:
    Pop( );
    void display( );
};


//Popscal
class Popscal:public Command {
public:
    Popscal( );
    void display( );
};


//Poparr
class Poparr:public Command {
public:
    Poparr( );
    void display( );
};


//Dup
class Dup:public Command {
public:
    Dup( );
    void display( );
};


//Swap
class Swap:public Command {
public:
    Swap( );
    void display( );
};


//Add
class Add:public Command {
public:
    Add( );
    void display( );
};


//Negate
class Negate:public Command {
public:
    Negate( );
    void display( );
};


//Mul
class Mul:public Command {
public:
    Mul( );
void display( );
};


//Div
class Div:public Command {
public:
    Div( );
    void display( );
};


//Printtos
class Printtos:public Command {
public:
    Printtos( );
    void display( );
};


//Prints
class Prints:public Command {
public:
    Prints( );
    void display( );
};


#endif