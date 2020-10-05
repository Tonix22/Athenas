/*------------------------------------------------------------------------------
@Author: Emilio Tonix 
@Date: Oct 4 2020
@Description Hash Table with Matrix multiplication for N bits size
------------------------------------------------------------------------------*/

// =====================================================================
// INCLUDES
// =====================================================================
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "mit_matrix.h"
// =====================================================================
// DEFINE
// =====================================================================

#define AVAILABLE INT_MAX
#define EMPTY 0
#define pow_2(val)  (1 << val)

#define DEBUG (1) // ENABLE OR DISABLE DEBUG

#if DEBUG
#define DEBUG_PRINT printf
#define PRINT_BIN_VALUE print_binary
#else
#define DEBUG_PRINT 
#define PRINT_BIN_VALUE
#endif


// =====================================================================
// Local Variables
// =====================================================================
char max_bits_in_hash_value; // Horizontal size of Hash, N bits
char table_size; // real table size is 2^(table size)
int* Hash_table; // table size is pow(2,3)
int* M;

int* get_table(void)
{
    return Hash_table;
}

void print_binary(int var)
{
    for(char k=3; k >=0 ;k--)
    {
        printf("%d",(var & 1<<k)>>k);
    }
    printf("\r\n");
}

/*Generates a random matrix 
Each M[i] it could be seen as a bidimensional matrix

@param: 
    M: Matrix array
    key_size: Hash_table size. NOTE: Hash size and array size are the same
    max_input_size: Total lenght of bits in M[i]

@EXAMPLE

    Generate_Hash_Matrix(M,3,4)

        ----------> 4 bits width
        [ 1 0 0 1 ] |
    M = | 0 1 1 1 | | 3 Hight
        [ 1 1 1 0 ] |

    Hash_table [8]; A has table of size two_power(3)

*/
void Generate_Hash_Matrix(int key_size,int max_input_size) 
{
    srand(time(NULL)); // Initialization, should only be called once.

    /*Generate globals*/
    max_bits_in_hash_value = max_input_size;
    table_size             = key_size;

    /*Dynamic array for Hash*/
    Hash_table = malloc(sizeof(int)*pow_2(table_size));
    memset(Hash_table,0,sizeof(int)*pow_2(table_size));
    M = malloc(sizeof(int)*table_size);
    memset(M,0,sizeof(int)*table_size);

    DEBUG_PRINT("----------------------------\r\n");
    DEBUG_PRINT("Matrix: \r\n");

    for(int i=0; i < key_size ;i++)
    {
        M[i] = rand()%((1 << max_input_size)-1);//limit max number;
        PRINT_BIN_VALUE(M[i]);
    }
}

void deinit_clean_hash(void)
{
    free(Hash_table);
    free(M);
}

/*
@EXAMPLE

    An input of 4 bit vector 
    VAL = 10; BINARY 1010
    {1}
    {0}
    {1}
    {0}
    You need to multiply it by VAL

        A[ 1 0 0 1 ]    [1]
    M = B| 0 1 1 1 |  X |0|
        C[ 1 1 1 0 ]    |1|
                        [0]

    Lets Multiply First ROW with COL
       1     0     1     0
       |     |     |     |
       v     v     v     v
  A  (1*1)+(0*0)+(0*1)+(1*0) = 1 + 0 + 0 + 0 = 1
  B  (0*1)+(1*0)+(1*1)+(1*0) = 0 + 0 + 1 + 0 = 1
  C  (1*1)+(1*0)+(1*1)+(0*0) = 1 + 0 + 1 + 0 = 0 // rember 1+1 is 0 in binary
  
  But multiply could be cost effective and if we
  are in a binary system making "AND" has the 
  same result. And making sum is the same as XOR.
  1 XOR 0 = 1
  0 XOR 1 = 1
  1 XOR 1 = 0
  0 XOR 0 = 0

  So it will be asier to do AND and then XOR with 
  shifting thru all bits. 

*/
int Get_key(int value)
{    
    int matrix_mul;
    int hash = 0;
    int bit_process;
    DEBUG_PRINT("----------------------------\r\n");
    for(int i = 0; i < table_size ;i++)
    {
        matrix_mul = M[i] & value;
        DEBUG_PRINT("M_%d X V: ",i);
        PRINT_BIN_VALUE(matrix_mul);

        bit_process = matrix_mul & 1; // Same as matrix mult firs part

        for(int bit=1; bit < max_bits_in_hash_value; bit++)
        {
            bit_process ^= (matrix_mul & 1 << bit) >> bit; // sum all bits 
        }
        DEBUG_PRINT("XOR = %d\r\n",bit_process);
        hash |= bit_process << (i); // save all bits saved in a variable 
    }
    DEBUG_PRINT("----------------------------\r\n");
    DEBUG_PRINT("KEY: %d, bin: ", hash);
    PRINT_BIN_VALUE(hash);
    return hash;
}

bool insert_value(int value)
{
    int key   = Get_key(value);//(value, # of bits in value,  Matrix, table_size)
    
    DEBUG_PRINT("insert key[%d] with val %d\r\n",key,value);
    
    if(Hash_table[key] == EMPTY || Hash_table[key] == AVAILABLE)
    {
        Hash_table[key] = value;    
    }
    //else if(Hash_table[key] != value)
    else
    {   
        // =====================================================================
        // Linear probing
        // =====================================================================
        DEBUG_PRINT("collide\r\n");
        int i=1;
        int hash_size = pow_2(table_size);

        while( Hash_table[(key+i) % hash_size] != EMPTY && (i < hash_size))
        {
            i++;
        }
        if(i != hash_size)
        {
            Hash_table[(key+i) % hash_size] = value;
        }
        else
        {
            printf("FULL HASH\r\n");
            return false;
        }
    }
    return true;
}
bool delete(int value)
{
    int key = Get_key(value);//(value, # of bits in value,  Matrix, table_size)
    int i   = 0;
    int hash_size = pow_2(table_size);

    while(Hash_table[(key+i) % hash_size] != EMPTY && (i < hash_size))
    {
        if(Hash_table[(key+i) % hash_size] == value)
        {
            Hash_table[(key+i) % hash_size] = AVAILABLE;
            return true;
        }
        i++;
    }
    return false;
}

// search key has overhead on linear probing
bool search_key(int value)
{
    int key = Get_key(value);//(value, # of bits in value,  Matrix, table_size)
    int i   = 0;
    int hash_size = pow_2(table_size);

    while(Hash_table[(key+i) % hash_size] != EMPTY && (i < hash_size))
    {
        if(Hash_table[(key+i) % hash_size] == value)
        {
            return true;
        }
        i++;
    }
    return false;
}

int main(int argc, char const *argv[])
{   
    /*NOTE:
        Review birthday paradox to calc probability of collision
    */
    int t_size_in_bits  = 3; // MAX BITS OF HASH TABLE IS 30 bits 
    char data_bit_size  = 4;  // DATA INPUT SIZE

    Generate_Hash_Matrix(t_size_in_bits,data_bit_size);//table size, max bits input value

    insert_value(0X1); // insert 1
    insert_value(0XB); // insert 11
    insert_value(0XA); // insert 10
    insert_value(0X7); // insert 7
    insert_value(0X3); // insert 3
    insert_value(0X8); // insert 3

    delete(0X1);
    delete(0XA);

    insert_value(0X2); // insert 3

    deinit_clean_hash();
    
    return 0;
}
