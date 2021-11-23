#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

//BIN      DEC
//000     = 0 
//001     = 1
//010     = 2
//011     = 3
//100     = 4
//101     = 5
//110     = 6

//101
//001
//001 = true - impar


bool isEven(int num) //PAR
{
    return (num & 1 == 0);
}
bool isODD(int num)//IMPAR
{
    return !isEven(num);
}

uint16_t one_complement(uint16_t num){
    //110 = 3
    //001 = 1

    //1010 = 10
    //0101 = 5
    return ~num ; 
}

int powerof2(int base)
{
   return base * base; 
}

//1 100
//[1,2,3,4,5,6,7,8,9,10] X 10

void closed_print()
{
    for (int i = 0; i < 100; i++)
    {
        printf("%d,", (i % 10) + 1);
        if((i%10 +1 ) == 10){
            printf("\n");
        }
    }
}

void create_array(int size)
{
    //char A[size];
}

int main(int argc, char const *argv[])
{
    char A[] = "hola";
    char B[] = "mundo";
    char C[] = "Por favor insert una opción\r\n"\
                "1) Es par o impar\r\n"\
                "2) Otra cosa";
    
    //for (int i = 0; i < argc; i++)
    //{
    //    printf("%c\r\n",*argv[i]);
    //}
    char* dynamic = (char*)malloc(sizeof(char)*10); // char[10]
    for (int i = 0; i < 10; i++)
    {
        printf("%d\r\n",dynamic[i]);
    }
    free(dynamic);
    
    

    //printf("Is %s \r\n",isEven(11)?("Even"):("ODD"));
    //uint16_t var = 10;
    //printf("%i is complement of %i\r\n",one_complement(var),var);
    //printf("%d\r\n",powerof2(10));
    //closed_print();
    //printf("%s\r\n",C);
    return 0;
}
