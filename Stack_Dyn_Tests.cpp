#include "Stack_Dyn_Head.h"

int Stack_Push_Test (void);

int Stack_Pop_Test (void);

int Canary_Test (void);


int Unitest (void)
{
    Stack_Push_Test ();
    Stack_Pop_Test ();
    Canary_Test ();

}

int Stack_Push_Test (void)
{
    Stack_t stk = {};
    Stack_Constructor (stk);
    int i = 0;

    int ss = stk.max_size;



    for (i = 0; i < ss - 1; i++)
        Stack_Push (&stk, 5 * i);

    int temp = 0;
    for (i = 0; i < ss - 1; i++)
        if (*((elem_t*)stk.data + i) != 5 * i) temp++;

    Stack_OK (&stk);

    if (stk.error == 0 && temp == 0)
    {
        printf ("Stack_Push is O'Kay!\n");
        return 0;
    }
    else
    {
        printf ("Stack_Push has failed!\n\
                 Expected temp = %d, received %d!\n", 0, temp);
        return 1;
    }

    return 0;
}

int Stack_Pop_Test (void)
{
    Stack_t stk = {};
    Stack_Constructor (stk);

//First Test
    int temp = Stack_Pop (&stk);
    int error = Stack_OK (&stk);

    if (error == Stack_Empty)
        printf ("The first Stack_Pop test is alright!\n");
    else
        printf ("The first Stack_Pop test has failed!\n\
                 Expected error = %d, received %d\n", Stack_Empty, error);

//Second Test
    int i = 0;
    int ss = stk.max_size;
    for (i = 0; i < ss - 1; i++)
        Stack_Push (&stk, 5 * i);


    int arr[ss] = {};

    for (i = 0; i < ss - 1; i++)
        arr[i] = Stack_Pop (&stk);

    Stack_OK (&stk);

    for (i = ss - 2; i > 0; i--)
        if (arr[ss - i - 2] != 5 * i)
        {
            printf ("The second Stack_Pop_Test has failed!\n\
                     Expected %d, recieved %d!\n", 5 * i, arr[ss - i - 1], ss);
            return -1;
        }

    printf ("The second Stack_Pop_Test is O'K!\n");

    return 0;
}

int Canary_Test (void)
{
    Stack_t stk = {};
    Stack_Constructor (stk);
    int ss = stk.max_size;

    int i = 0;
    for (i = 0; i < ss - 1; i++)
        Stack_Push (&stk, rand() % 100);

//Test 1

    *((long*)&stk) = 10;

    int error = Stack_OK (&stk);

    if (error == Canary_Stack_Dead)
        printf (  "First Canary_Test is alright!\n");
    else printf ( "First Canary_Test has failed!\n\
                   Expected error code %d, recieved %d\n", Canary_Stack_Dead, error);
    *((long*)&stk) = can_size;

//Test 2

    *((long*)(&stk + 1) - 1) = 10;

    error = Stack_OK (&stk);

    if (error == Canary_Stack_Dead)
        printf (  "Second Canary_Test is alright!\n");
    else printf ( "Second Canary_Test has failed!\n\
                   Expected error code %d, recieved %d\n", Canary_Stack_Dead, error);
    *((long*)(&stk + 1) - 1) = can_size;

//Test 3

    *((long*)stk.data - 1) = 10;

    error = Stack_OK (&stk);

    if (error == Canary_Arr_Dead)
        printf (  "Third Canary_Test is alright!\n");
    else printf ( "Third Canary_Test has failed!\n\
                   Expected error code %d, recieved %d\n", Canary_Arr_Dead, error);

    *((long*)stk.data - 1) = can_size;

//Test 4

    *((elem_t*)stk.data + stk.max_size) = 10;

    error = Stack_OK (&stk);

    if (error == Canary_Arr_Dead)
        printf (  "Fourth Canary_Test is alright!\n");
    else printf ( "Fourth Canary_Test has failed!\n\
                   Expected error code %d, recieved %d\n", Canary_Arr_Dead, error);

    *((elem_t*)stk.data + stk.max_size) = can_size;

    return 0;

}
