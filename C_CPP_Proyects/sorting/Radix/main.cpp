#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;


void print_arr(int arr[], int size){
    for(int i=0; i<size; i++){
        printf("%i, ",arr[i]);
    }
}

int max(int arr[], int size){
    int max=0;
    for(int i=0; i<size;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

void radix(int arr[], int size){
    int b=0, k=0, max_bits=0, count_zeros=0;
    int max_value = max(arr,size);
    int* copia = (int*) malloc(sizeof(int)*size);
    while(max_value !=0){
        max_value >>= 1;
        max_bits++;
    }
    //cout<<"MAXBITS = "<<max_bits;
    for(int i=0; i<max_bits; i++){
        cout<<"\nVuelta "<<i<<endl;
        for (int j=0; j<size; j++){
            b = (arr[j]&1<<i)>>i;
            cout<<b<<endl;
            if(b == 0){
                count_zeros++;
            }
        }
       cout<<"Count zeros: "<<count_zeros<<endl;
        for (int j=0; j<size; j++){
            b = (arr[j]&1<<i)>>i;
            //cout<<b<<endl;
            if(b == 0){
                copia [k] = arr[j];
                k++;
                cout<<"K: "<<k<<endl;
            }else{
                copia[count_zeros] = arr[j];
                count_zeros++;
                cout<<"indice zeros: "<<count_zeros<<endl;
            }
        }
        cout<<"\nORIGINAL ARR\n";
        print_arr(arr, size);
        memcpy(arr,copia,size*sizeof(int));
        
        cout<<"\nCOPIA\n";
        print_arr(copia, size);
        count_zeros = 0;
        k=0;

        
    }
    free (copia);
    copia = NULL;
}
/*
     3210
__________
4 -> 100 b = 0  0000  1 3 2 4
3 -> 011 b = 1
2 -> 010 b = 0
1 -> 001 b = 1
    i j
  4 2 1 3
  0100
  0010
  0001
  0011

  V0
  4,2,3,1

  V1
  4,1,3,2

  V2
  1,2,3,4

*/ 
int main(){
    int arr[] = {4,3,2,1,100,120,10,11,25};
    radix(arr,sizeof(arr)/sizeof(int));
    //print_arr(arr,sizeof(arr)/sizeof(int));
   // printf("\nMAX = %i",max(arr,sizeof(arr)/sizeof(int)));
    
    return 0;
}