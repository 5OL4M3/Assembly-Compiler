#ifndef COMMAND_H_
#define COMMAND_H_
#include "statement_buffer.h"
#include "map.h"
#include "symbol_table.h"



class Command{
public:
    Command();
    std::string instruction;
    int count;
    bool check;		//if we should check for additional arguments for eg. 6 in pushi 6
	int expected = 0;	//the number of additional arguments we should expect
	virtual void display() = 0;
    virtual void add() = 0;
    virtual std::string get_instruction() = 0;
    virtual int get_count() = 0;
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
    std::string get_instruction( );
    int get_count( );
};


//Declarr
class Declarr:public Command {
public:
    Declarr( );
    void display( );
    void add();
    std::string get_instruction( );
    int get_count( );
};


//Label
class Label:public Command {
public:
    Label( );
    void display( );
    void add();
    std::string get_instruction( );
    int get_count( );
};


//Gosublabel
class Gosublabel:public Command {
public:
    Gosublabel( );
    void display( );
    void add();
    std::string get_instruction( );
    int get_count( );
private: 
    int count = -1;
    std::string instruction = "OP_ENTER_SUBROUTINE";
};

//Start 
class Start:public Command {
public:
    Start( );
    void display( );
    void add( );
    std::string get_instruction( );
    int get_count( );
private:
    int count = -1;
    std::string instruction = "OP_START_PROGRAM";
};

//End
class End:public Command {
public:
    End( );
    void display( );
    void add();
    std::string get_instruction( );
    int get_count( );
};


//Exit
class Exit:public Command {
public:
    Exit( );
    void display( );
    void add();
    std::string get_instruction( );
    int get_count( );
private:
    int count = -1;
    std::string instruction = "OP_EXIT";
};


//Jump
class Jump:public Command {
public:
    Jump( );
    void display( );
    void add();
    std::string get_instruction( );
    int get_count( );
private:
    int count = -1;
    std::string instruction = "OP_JUMP";
};


//Jumpzero
class Jumpzero:public Command {
public:
    Jumpzero( );
    void display( );
    void add();
    std::string get_instruction( );
    int get_count( );
private:
    int count = -1;
    std::string instruction = "OP_JUMPZERO";
};


//Jumpnzero
class Jumpnzero:public Command {
public:
    Jumpnzero( );
    void display( );
    void add();
    std::string get_instruction( );
    int get_count( );
private:
    int count = -1;
    std::string instruction = "OP_JUMPNZERO";
};


//Gosub
class Gosub:public Command {
public:
    Gosub( );
    void display( );
    void add();
    std::string get_instruction( );
    int get_count( );
private:
    int count = -1;
    std::string instruction = "OP_GOSUB";
};

//Return
class Return:public Command {
public:
    Return( );
    void display( );
    void add();
    std::string get_instruction( );
    int get_count( );
private:
    int count = -1;
    std::string instruction = "OP_RETURN";
};


//Pushscal
class Pushscal:public Command {
public:
    Pushscal( );
    void display( );
    void add();
    std::string get_instruction( );
    int get_count( );
private:
    int count = -1;
    std::string instruction = "OP_PUSHSCALAR";
};


//Pusharr
class Pusharr:public Command {
public:
    Pusharr( );
    void display( );
    void add();
    std::string get_instruction( );
    int get_count( );
private:
    int count = -1;
    std::string instruction = "OP_PUSHARRAY";
};


//Pushi
class Pushi:public Command {
public:
    Pushi( );
    void display( );
    void add();
    std::string get_instruction( );
    int get_count( );
private:
    int count = -1;
    std::string instruction = "OP_PUSHI";
};


//Pop
class Pop:public Command {
public:
    Pop( );
    void display( );
    void add();
    std::string get_instruction( );
    int get_count( );
private:
    int count = -1;
    std::string instruction = "OP_POP";
};


//Popscal
class Popscal:public Command {
public:
    Popscal( );
    void display( );
    void add();
    std::string get_instruction( );
    int get_count( );
private:
    int count = -1;
    std::string instruction = "OP_POPSCAL";
};


//Poparr
class Poparr:public Command {
public:
    Poparr( );
    void display( );
    void add();
    std::string get_instruction( );
    int get_count( );
private:
    int count = -1;
    std::string instruction = "OP_POPARRAY";
};


//Dup
class Dup:public Command {
public:
    Dup( );
    void display( );
    void add();
    std::string get_instruction( );
    int get_count( );
private:
    int count = -1;
    std::string instruction = "OP_DUP";
};


//Swap
class Swap:public Command {
public:
    Swap( );
    void display( );
    void add();
    std::string get_instruction( );
    int get_count( );
private:
    int count = -1;
    std::string instruction = "OP_SWAP";
};


//Add
class Add:public Command {
public:
    Add( );
    void display( );
    void add();
    std::string get_instruction( );
    int get_count( );
private:
    int count = -1;
    std::string instruction = "OP_ADD";
};


//Negate
class Negate:public Command {
public:
    Negate( );
    void display( );
    void add();
    std::string get_instruction( );
    int get_count( );
private:
    int count = -1;
    std::string instruction = "OP_NEGATE";
};


//Mul
class Mul:public Command {
public:
    Mul( );
	void display( );
    void add();
    std::string get_instruction( );
    int get_count( );
private:
    int count = -1;
    std::string instruction = "OP_MUL";
};


//Div
class Div:public Command {
public:
    Div( );
    void display( );
    void add();
    std::string get_instruction( );
    int get_count( );
private:
    int count = -1;
    std::string instruction = "OP_DIV";
};


//Printtos
class Printtos:public Command {
public:
    Printtos( );
    void display( );
    void add();
    std::string get_instruction( );
    int get_count( );
private:
    int count = -1;
    std::string instruction = "OP_PRINTTOS";
};

//Prints
class Prints:public Command {
public:
    Prints( );
    void display( );
    void add();
    std::string get_instruction( );
    int get_count( );
private:
    int count = -1;
    std::string instruction = "OP_PRINTS";
};

#endif
