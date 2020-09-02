#include <iostream>
#include <stdio.h>
#include <stdlib.h>
int array[5] = {5,7,2,8,0};


int a = 0;
int b = 0;

void incrementa(int *variable) {
 (*variable)++;
}

int main(int argc, char const *argv[]) // :)
{

    int *c = (int*) malloc(sizeof(int)); // 1 
    *c = 10; // 2
    int** a = &c; // 3
    int ***b = &a;
    printf("%d",**a);//¿Que imprime en consola? //4

    //-1474023824

    return 0;
}
