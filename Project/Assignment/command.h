#ifndef COMMAND_H_
#define COMMAND_H_
#include <iostream>
#include <fstream>
#include <vector>
#include "statement_buffer.h"
#include "symbol_table.h"
#include "functions.h"
#include "data_memory.h"


class Command{
public:
    Command();
    Command(const Command&);
    ~Command();
    std::string instruction;
    std::string var1;//User argument 1
    std::string var2; //User argument 2
    std::string data_type1; //The data type of first arg (s = string; i = int)
    std::string data_type2; // The data type of second arg (s = string; i = int)
    int data_size; //size of the data
    int need_update = 0; //will need to be update when returned
    int scope; 
    int change_scope = 0; //checks if scope needs to be changed
    int count;
    bool check;		//if we should check for additional arguments for eg. 6 in pushi 6
	int expected = 0;	//the number of additional arguments we should expect
	virtual void display();
    virtual void add();
    virtual std::string get_instruction();
    virtual void perform_update(); //updates the count 
    virtual int get_count();
	void assign_args(std::string);
    virtual int vm_action(int, std::vector<int>&, std::vector<int>&, Data_Memory*);
private:
    std::string syntax;
};

Command* getCommand(int ind);

//-----Commands:
//Declscal
class Declscal:public Command {
public:
    Declscal( );
    void add();
    virtual int vm_action(int, std::vector<int>&, std::vector<int>&, Data_Memory*);
};


//Declarr
class Declarr:public Command {
public:
    Declarr( );
    void add();
    virtual int vm_action(int, std::vector<int>&, std::vector<int>&, Data_Memory*);
};


//Label
class Label:public Command {
public:
    Label( );
    void add();
    virtual int vm_action(int, std::vector<int>&, std::vector<int>&, Data_Memory*);
};


//Gosublabel
class Gosublabel:public Command {
public:
    Gosublabel( );
    void add();
    virtual void perform_update();
    std::string get_instruction( );
    int get_count( );
    virtual int vm_action(int, std::vector<int>&, std::vector<int>&, Data_Memory*);
private: 
    std::string instruction = "OP_ENTER_SUBROUTINE";
};

//Start 
class Start:public Command {
public:
    Start( );
    void add( );
    virtual void perform_update();
    std::string get_instruction( );
    int get_count( );
private:
    std::string instruction = "OP_START_PROGRAM";
    virtual int vm_action(int, std::vector<int>&, std::vector<int>&, Data_Memory*);
};

//End
class End:public Command {
public:
    End( );
    void add();
};


//Exit
class Exit:public Command {
public:
    Exit( );
    void add();
    std::string get_instruction( );
    int get_count( );
    virtual int vm_action(int, std::vector<int>&, std::vector<int>&, Data_Memory*);
private:
    std::string instruction = "OP_EXIT";
};


//Jump
class Jump:public Command {
public:
    Jump( );
    void add();
    virtual void perform_update();
    std::string get_instruction( );
    int get_count( );
    virtual int vm_action(int, std::vector<int>&, std::vector<int>&, Data_Memory*);
private:
    std::string instruction = "OP_JUMP";
};


//Jumpzero
class Jumpzero:public Command {
public:
    Jumpzero( );
    void add();
    virtual void perform_update();
    std::string get_instruction( );
    int get_count( );
    virtual int vm_action(int, std::vector<int>&, std::vector<int>&, Data_Memory*);
private:
    std::string instruction = "OP_JUMPZERO";
};


//Jumpnzero
class Jumpnzero:public Command {
public:
    Jumpnzero( );
    void add();
    virtual void perform_update();
    std::string get_instruction( );
    int get_count( );
    virtual int vm_action(int, std::vector<int>&, std::vector<int>&, Data_Memory*);
private:
    std::string instruction = "OP_JUMPNZERO";
};


//Gosub
class Gosub:public Command {
public:
    Gosub( );
    void add();
    virtual void perform_update();
    std::string get_instruction( );
    int get_count( );
    virtual int vm_action(int, std::vector<int>&, std::vector<int>&, Data_Memory*);
private:
    std::string instruction = "OP_GOSUB";
};

//Return
class Return:public Command {
public:
    Return( );
    void add();
    std::string get_instruction( );
    int get_count( );
    virtual int vm_action(int, std::vector<int>&, std::vector<int>&, Data_Memory*);
private:
    std::string instruction = "OP_RETURN";
};


//Pushscal
class Pushscal:public Command {
public:
    Pushscal( );
    void add();
    std::string get_instruction( );
    int get_count( );
    virtual int vm_action(int, std::vector<int>&, std::vector<int>&, Data_Memory*);
private:
    std::string instruction = "OP_PUSHSCALAR";
};


//Pusharr
class Pusharr:public Command {
public:
    Pusharr( );
    void add();
    std::string get_instruction( );
    int get_count( );
    virtual int vm_action(int, std::vector<int>&, std::vector<int>&, Data_Memory*);
private:
    std::string instruction = "OP_PUSHARRAY";
};


//Pushi
class Pushi:public Command {
public:
    Pushi( );
    void add();
    std::string get_instruction( );
    int get_count( );
    virtual int vm_action(int, std::vector<int>&, std::vector<int>&, Data_Memory*);
private:
    std::string instruction = "OP_PUSHI";
};


//Pop
class Pop:public Command {
public:
    Pop( );
    void add();
    std::string get_instruction( );
    int get_count( );
    virtual int vm_action(int, std::vector<int>&, std::vector<int>&, Data_Memory*);
private:
    std::string instruction = "OP_POP";
};


//Popscal
class Popscal:public Command {
public:
    Popscal( );
    void add();
    std::string get_instruction( );
    int get_count( );
    virtual int vm_action(int, std::vector<int>&, std::vector<int>&, Data_Memory*);
private:
    std::string instruction = "OP_POPSCAL";
};


//Poparr
class Poparr:public Command {
public:
    Poparr( );
    void add();
    std::string get_instruction( );
    int get_count( );
    virtual int vm_action(int, std::vector<int>&, std::vector<int>&, Data_Memory*);
private:
    std::string instruction = "OP_POPARRAY";
};


//Dup
class Dup:public Command {
public:
    Dup( );
    void add();
    std::string get_instruction( );
    int get_count( );
    virtual int vm_action(int, std::vector<int>&, std::vector<int>&, Data_Memory*);
private:
    std::string instruction = "OP_DUP";
};


//Swap
class Swap:public Command {
public:
    Swap( );
    void add();
    std::string get_instruction( );
    int get_count( );
    virtual int vm_action(int, std::vector<int>&, std::vector<int>&, Data_Memory*);
private:
    std::string instruction = "OP_SWAP";
};


//Add
class Add:public Command {
public:
    Add( );
    void add();
    std::string get_instruction( );
    int get_count( );
    virtual int vm_action(int, std::vector<int>&, std::vector<int>&, Data_Memory*);
private:
    std::string instruction = "OP_ADD";
};


//Negate
class Negate:public Command {
public:
    Negate( );
    void add();
    std::string get_instruction( );
    int get_count( );
    virtual int vm_action(int, std::vector<int>&, std::vector<int>&, Data_Memory*);
private:
    std::string instruction = "OP_NEGATE";
};


//Mul
class Mul:public Command {
public:
    Mul( );
    void add();
    std::string get_instruction( );
    int get_count( );
    virtual int vm_action(int, std::vector<int>&, std::vector<int>&, Data_Memory*);
private:
    std::string instruction = "OP_MUL";
};


//Div
class Div:public Command {
public:
    Div( );
    void add();
    std::string get_instruction( );
    int get_count( );
    virtual int vm_action(int, std::vector<int>&, std::vector<int>&, Data_Memory*);
private:
    std::string instruction = "OP_DIV";
};


//Printtos
class Printtos:public Command {
public:
    Printtos( );
    void add();
    std::string get_instruction( );
    int get_count( );
    virtual int vm_action(int, std::vector<int>&, std::vector<int>&, Data_Memory*);
private:
    std::string instruction = "OP_PRINTTOS";
};

//Prints
class Prints:public Command {
public:
    Prints( );
    void add();
    virtual void perform_update();
    std::string get_instruction( );
    int get_count( );
    virtual int vm_action(int, std::vector<int>&, std::vector<int>&, Data_Memory*);
private:
    std::string instruction = "OP_PRINTS";
};

#endif
