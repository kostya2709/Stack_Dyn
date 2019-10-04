#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#define empty -666

#define Stack_Constructor( this )         \
    this.name = #this;                    \
    Stack_Construct ( &this );

#define Dump( this )                      \
    Dump_Def ( &this , __LINE__, __FILE__, __PRETTY_FUNCTION__);


//! These are codes of possible errors.
enum Error_codes {OK, Stack_OverFlow, Stack_Empty, Canary_Stack_Dead, Canary_Arr_Dead, Wrong_Hash};

const double multy = 1.7;

const int MAX_SIZE = 5;

const long int can_size = 27272727;

typedef int elem_t;

/*!
@detailed This is stack named Stack_t. It allows you:
to make the stack with Stack_Construct;
to Push elements with function Stack_Push;
to Pop elements with function Stack_Pop;
to check errors in stack with function Stack_OK;
to display the hole information about the stack;
to check information with function Hash;
to change the size of the stack with function Size_Change;
to destroy the stack with Stack_Destruct;

Stack poles:
canary_front - left canary, to check stack safety;
data - pointer to the array with information;
size - current amount of elements;
max_size - callocated amount of elements in the stack;
name - the name of the stack;
error - return the code of error in stack;
canary_arr_front - canary before the array to check safety of the information in data;
canary_arr_back - canary after the array to check safety of the information in data;
canary_back - canary after the stack to check its safety;
hash - hash to check safety of the stack;

*/

struct Stack_t
{
    long int canary_front;          
    elem_t* data;                
    int size;
    int max_size;
    char* name;
    int error;
    long int* canary_arr_front;
    long int* canary_arr_back;
    long int canary_back;
    long int hash;
};

int Dump_Def (Stack_t* stk, const int line, const char* file, const char* function);

long Hash (Stack_t* stk);

int Size_Change (Stack_t* stk, int new_size);

int Stack_Construct (Stack_t* stk);

int Stack_Destruct (Stack_t* stk);

int Stack_OK (Stack_t* stk);

elem_t Stack_Pop (Stack_t* stk);

int Stack_Push (Stack_t* stk, elem_t value);

int Unitest (void);


