#include <stdlib.h>
#include <stdio.h>

void change(int* b)
{
    *b=45;
}

void assignptr(int** val,int data)
{  
    *val = (int*)malloc(sizeof(int));
    **val = data;
}
void assignptrcpp(int*& val,int data)
{  
    val = (int*)malloc(sizeof(int));
    *val = data;
}

void foo(int* b)
{
    (*b)++;
}
void foocpp(int& b)
{
    b++;
}

int main()
{
    int* outside;
    int a=3;
    foo(&a);
    foocpp(a);

    printf("%d\r\n",a);

    assignptr(&outside,7);
    assignptrcpp(outside,9);
    
    printf("outside: %d\r\n",*outside);
}