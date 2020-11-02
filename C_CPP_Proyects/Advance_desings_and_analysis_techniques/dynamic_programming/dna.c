
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dna.h"
#include <string.h> // strlen
#include <time.h>

#define DEBUG (ON)

char Base_genoma[] = "ACGT";

void reverse_string(char* A)
{
    size_t l = strlen(A);
    char* r = (char*)malloc((l) * sizeof(char));
    r[l] = 0;
    for (int i = 0; i < l; i++)
    {
        r[i] = A[l-1-i];
    }
    printf("%s \r\n",r);
    free(r);
    r = NULL;
}

/*lets apply back tracing*/
void print_LCS(int row,int col,char** b,char* x,char* y)
{
    char* sub;  
    int counter = 0;
    char col_it = 0;
    if(strlen(x) > strlen(y))
    {
        col_it = 1;
        sub = malloc(sizeof(char)*strlen(x));
        memset(sub,0,strlen(x));
    }
    else
    {
        sub = malloc(sizeof(char)*strlen(y));
        memset(sub,0,strlen(y));
    }

    
    while(row && col)
    {
        if(b[row][col] == LEFT)
        {
            col--;
        }
        else if(b[row][col] == UP)
        {
            row --;
        }
        else
        {
            if(col_it)
                sub[counter++]=x[col];
            else
                sub[counter++]=y[row];
            col--;
            row--;
        }
    }   
    reverse_string(sub);
    
    free(sub);
    sub = NULL;
}   
// use graphical visualization for indexes

void LCS(char* x, char* y,int size_x,int size_y)
{    
    char temp;
    CREATE_2D_ARR(c)
    CREATE_2D_ARR(b)
    
    for (int i = 1; i < size_y; i++)
    {
        //PRINT_C_2D_ARR(c)
        for (int j = 1; j < size_x; j++)
        {
            if(y[i] == x[j])
            {
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = DIAG; 
            }
            else
            {    
                if(c[i-1][j] >= c[i][j-1]) 
                {
                    c[i][j] = c[i-1][j];
                    b[i][j] = UP;
                }
                else // LEFT
                {
                    c[i][j] = c[i][j-1];
                    b[i][j] = LEFT;
                }
            }
        }
    }
    #if DEBUG
    PRINT_C_2D_ARR(c,0)
    PRINT_C_2D_ARR(b,1)
    #endif
    /*back tracing*/
    print_LCS(size_y-1,size_x-1,b,x,y);

    Destroy_C_2D_ARR(c)
    Destroy_C_2D_ARR(b)
   
}
void Generate_random_seq(int size)
{
    char* DNA1;
    char* DNA2;
    srand((unsigned)time(NULL));
    int ranlen1 = rand() % size+size;
    int ranlen2 = rand() % size+size;
    DNA1 =(char*) malloc(sizeof(char)*ranlen1+1);
    DNA2 =(char*) malloc(sizeof(char)*ranlen2+1);
    DNA1[0]='0';
    DNA2[0]='0';

    for (int i = 1; i < ranlen1; i++)
    {   
        DNA1[i] = Base_genoma[rand() % 4];
    }
    for (int i = 1; i < ranlen2; i++)
    {   
        DNA2[i] = Base_genoma[rand() % 4];
    }
    DNA1[ranlen1] = 0;// adding NULL terminator
    DNA2[ranlen2] = 0;// adding NULL terminator

    printf("DNA1: %s\r\n",DNA1);
    printf("DNA2: %s\r\n",DNA2);
    LCS(DNA1,DNA2,ranlen1,ranlen2);
    
    free(DNA1);
    free(DNA2);

    DNA1 = NULL;
    DNA2 = NULL;
}



int main(int argc, char const *argv[])
{
    Generate_random_seq(10);
    return 0;
}
