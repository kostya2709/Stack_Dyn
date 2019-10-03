#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#define empty -666

#define Stack_Constructor( this )         \
    Stack_Construct ( &this );            \
    this.name = #this;

#define Dump( this )                      \
    Dump_Def ( &this , __LINE__, __FILE__, __PRETTY_FUNCTION__);


//! These are codes of possible errors.
enum Error_codes {OK, Stack_OverFlow, Stack_Empty, Canary_Stack_Dead, Canary_Arr_Dead, Wrong_Hash};

const double multy = 1.7;

const int MAX_SIZE = 5;

const long int can_size = 27272727;

typedef int elem_t;

struct Stack_t
{
    long int canary_front;
    elem_t* data;
    int size;
    int max_size;
    char* name;
    int error;
    long int hash;
    long int* canary_arr_front;
    long int* canary_arr_back;
    long int canary_back;
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


