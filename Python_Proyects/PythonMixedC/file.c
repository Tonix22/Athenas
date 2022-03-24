#include <stdio.h>


void no_normal(int * var,int size)
{
    int i;
    for(i=0; i<size;i++)
    {
        var[i]= var[i]* 2;
        // var[i] *= 2;
    }
    printf(" =) ");

}

void normal(int var)
{
    var = 1;
    printf("Yolo!!! ");
}