#include "stdio.h"
#include "string.h"
#include "stdlib.h"

void foo(int** a)
{
    *a = (int*) malloc(3*sizeof(int));
    (*a)[0]=1;
    (*a)[1]=1;
    (*a)[2]=2;
}
int bar(int* a)
{
    *a = 3;
}



int main(int argc, char const *argv[])
{ // push
    int val=2;
    bar(&val);
    printf("%d\r\n",val);

    int* ptr;
    foo(&ptr);
    printf("%d",ptr[2]);

    return 0;
}// pop stack
