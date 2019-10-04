#include <cstdio>
#include <cstdlib>
#include <string>
#include <cassert>
#include "max_libs.h"


int Test1 (void)
{
	printf ("Start Test1\n");
	DedStack_t dStack1 = {};

    DEB(std::string TmpName1  = "dStack1");
    DEB(dStack1.Name = &TmpName1);

    StackInit(&dStack1);

    StackPush(&dStack1, 10);

    dStack1.data = NULL;

    StackDestruck(&dStack1);
    printf ("End Test1");
}

int Test2 (void)
{
	printf ("Start Test2\n");
	DedStack_t dStack1 = {};

    DEB(std::string TmpName1  = "dStack1");
    DEB(dStack1.Name = &TmpName1);

    StackInit(&dStack1);

    StackPush(&dStack1, 10);
    StackPush(&dStack1, 10);

    int i = 0;
    for (i = 1; i < 4; i++)
        *((char*)dStack1.CanaryLeft + i) = 0;

    StackDestruck(&dStack1);
    printf ("End Test2");
}

int Test3 (void)
{
	printf ("Start Test3\n");
	DedStack_t dStack1 = {};

    DEB(std::string TmpName1  = "dStack1");
    DEB(dStack1.Name = &TmpName1);

    StackInit(&dStack1);

    int i = 0;
    for (i = 0; i < 1000; i++)
    	StackPush(&dStack1, 10 * i);

    *((long long*)dStack1.data - 1)= 2772;

    StackDestruck(&dStack1);
    printf ("End Test3");
}

int Tests (void)
{
	Test1 ();
	Test2 ();
	Test3 ();
}

