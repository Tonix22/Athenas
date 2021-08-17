#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char names[5][20] = 
{
    {"Alan"},
    {"Giselle"},
    {"Luis"},
    {"Ruth"},
    {"Wicho"},
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));
    int index = rand() % 4;
    printf("Question is for %s\r\n",names[index]);
    return 0;
}
