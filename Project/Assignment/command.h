#ifndef COMMAND_H_
#define COMMAND_H_
#include "statement_buffer.h"
#include "map.h"
#include "symbol_table.h"



class Command{
public:
    Command();
    std::string instruction;
    int count = 0;
    bool check;		//if we should check for additional arguments for eg. 6 in pushi 6
	int expected = 0;	//the number of additional arguments we should expect
	virtual void display() = 0;
    virtual void add() = 0;
	bool check_args(std::string);
private:
    std::string syntax;
};

//-----Commands:
//Declscal
class Declscal:public Command {
public:
    Declscal( );
    void display( );
    void add();
};


//Declarr
class Declarr:public Command {
public:
    Declarr( );
    void display( );
    void add();
};


//Label
class Label:public Command {
public:
    Label( );
    void display( );
    void add();
};


//Gosublabel
class Gosublabel:public Command {
public:
    Gosublabel( );
    void display( );
    void add();
};

//Start 
class Start:public Command {
public:
    Start( );
    void display( );
    void add( );
    int count = -1;
    std::string instruction = "OP_START_PROGRAM";
private:
    
};

//End
class End:public Command {
public:
    End( );
    void display( );
    void add();
};


//Exit
class Exit:public Command {
public:
    Exit( );
    void display( );
    void add();
};


//Jump
class Jump:public Command {
public:
    Jump( );
    void display( );
    void add();
};


//Jumpzero
class Jumpzero:public Command {
public:
    Jumpzero( );
    void display( );
    void add();
};


//Jumpnzero
class Jumpnzero:public Command {
public:
    Jumpnzero( );
    void display( );
    void add();
};


//Gosub
class Gosub:public Command {
public:
    Gosub( );
    void display( );
    void add();
};

//Return
class Return:public Command {
public:
    Return( );
    void display( );
    void add();
};


//Pushscal
class Pushscal:public Command {
public:
    Pushscal( );
    void display( );
    void add();
};


//Pusharr
class Pusharr:public Command {
public:
    Pusharr( );
    void display( );
    void add();
};


//Pushi
class Pushi:public Command {
public:
    Pushi( );
    void display( );
    void add();
};


//Pop
class Pop:public Command {
public:
    Pop( );
    void display( );
    void add();
};


//Popscal
class Popscal:public Command {
public:
    Popscal( );
    void display( );
    void add();
};


//Poparr
class Poparr:public Command {
public:
    Poparr( );
    void display( );
    void add();
};


//Dup
class Dup:public Command {
public:
    Dup( );
    void display( );
    void add();
};


//Swap
class Swap:public Command {
public:
    Swap( );
    void display( );
    void add();
};


//Add
class Add:public Command {
public:
    Add( );
    void display( );
    void add();
};


//Negate
class Negate:public Command {
public:
    Negate( );
    void display( );
    void add();
};


//Mul
class Mul:public Command {
public:
    Mul( );
	void display( );
    void add();
};


//Div
class Div:public Command {
public:
    Div( );
    void display( );
    void add();
};


//Printtos
class Printtos:public Command {
public:
    Printtos( );
    void display( );
    void add();
};


//Prints
class Prints:public Command {
public:
    Prints( );
    void display( );
    void add();
};

#endif
