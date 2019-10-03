//!@file

#include <stdio.h>
#include "Stack_Dyn_Head.h"



int main()
{
    elem_t x = 6;

    Stack_t stk1 = {};
    Stack_Constructor (stk1);

    Stack_Push (&stk1, 27);

    int val = Stack_Pop (&stk1);

    printf ("value = %d\n", val);

    Stack_Destruct (&stk1);

    Unitest ();

    return 0;
}
