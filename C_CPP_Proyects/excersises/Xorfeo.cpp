#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*
a|b|xor
0 0 0
0 1 1
1 0 1
1 1 0

Caso 1:
4
5 5 5 5
101b 101b 101b 101b  
b2 =1
b1 =0
b0=1

x=101b=5

x=5 (101b), l=1, r=4

Caso 2: 
3
1 3 2
01b 11b 10b

Fase 1:
b1=0
b0=1
x=1=01b, l=1, r=2

3
00b 10b 10b
b1=1
b0=0
x=2, l=2, r=3

00b 00b 00b

1.- Decidir x

*/

void xor(int *a, int *b){
   *a= *a^*b;
    return;
}

void decide_l(){
    return;
}

void decide_r(){
    return;
}

void operation_time(int *r, int *l, int *a_i){
    *a_i = ceil((*r - *l +1)/2); 
    return;
}

void arrayXOR(int *arr, int *l, int *r, int *x){
    
    for(int i = *l-1; i < *r; i++){
        arr[i] = arr[i]^*x;
    }
    return;
}

void printArr(int *arr, int *arrSize){
    for(int i=0; i < *arrSize; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

bool checkArrZeroes(int *arr, int *arrSize){
    for(int i=0; i < *arrSize; i++){
        if(arr[i] ==! 0){
            return false;
        }
    }
    return true;
}
void print_binary(int a)
{
    int num_bits = 16;
    for(int i=0;i<num_bits;i++)
    {
        printf("%d",(a&(1<<i))>>i);
    }
}

int main(){
    
    int arr[]={5, 5, 5, 5};
    int arrSize = sizeof(arr)/sizeof(int);
    
    int l=1;
    int r=4;
    int x=5; 

    int a_i;

    arrayXOR(&arr,&l,&r,&x);
    printArr(&arr, &arrSize);
    operation_time(&r, &l, &a_i);
    //printf("%d\n", a_i);
    //printf("%d\n", checkArrZeroes(&arr, &arrSize));
    
    /*
    int a=12;
    int b=25;
    xor(&a,&b);
    printf("Output = %d\n", arrSize);
    */
    return 0;
}