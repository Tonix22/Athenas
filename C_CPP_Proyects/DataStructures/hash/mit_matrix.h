#ifndef MATRIX
#define MATRIX
#include <stdbool.h> 

int  Get_key(int value);

int* get_table(void);

void print_binary(int var);
void Generate_Hash_Matrix(int key_size,int max_input_size);
void deinit_clean_hash(void);

bool insert_value(int value);
bool delete(int value);
bool search_key(int value);
#endif
