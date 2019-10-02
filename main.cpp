//!@file

#include <stdio.h>
#include "Stack_Dyn_Head.h"



int main()
{
    elem_t x = 6;

    Stack_t stk1 = {};
    Stack_Constructor (stk1);



    int i = 0;
    for (i = 0; i < 1; i++) Stack_Push (&stk1, 27);

    Stack_Destruct (&stk1);

    Unitest();

    return 0;
}
