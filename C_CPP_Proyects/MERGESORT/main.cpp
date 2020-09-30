#include <iostream>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

void print_arr (int arr[], int size){
        printf("[");
    for (int i=0; i<size; i++){
        printf("%i,",arr[i]);
    }
    printf("]\n");
}

void split(int *arr,int size)
{
    int mid2 = size/2; // 2
    int mid1 = size-mid2;// 3
    int a[mid1];
    int b[mid2];

    if(mid2!=0)
    {
        // copias temporales
        memcpy(a,arr,mid1*sizeof(int)); //primeros
        memcpy(b,arr+mid1,mid2*sizeof(int));

        //print_arr(a, sizeof(a)/sizeof(int));
       // print_arr(b, sizeof(b)/sizeof(int));
        //system("pause");

        split(a,mid1); // Has esto con papel amigo
        split(b,mid2); // Igual para esto

        //ALTO!! 
        //Aqui solo vamos a llegar cuando 
        // la ranita tenga dos hojitas para brincar
        // como minimo.
        int arr_nuevo [mid1+mid2], j=0,k=0; //regresar arr_nuevo
        for(int i=0; i<(mid1+ mid2);i++){
            if(a[j] < b[k] && j < mid1){
                arr_nuevo[i] = a[j];
                j++;
            }else{
                arr_nuevo[i] = b[k];
                k++;
            }
        }

        
        arr = arr_nuevo;
        printf("MERGE DE ARREGLOS ");
        print_arr(arr_nuevo, sizeof(arr)/sizeof(int));
        
        /*
        int* rana   = &a[0];
        int* brinca = &b[0];
        int* nueva_base;
        int  cnt    = 0;

        while(cnt < size-1)
        {
            if((*rana) > (*brinca))
            {
                arr[cnt] = *brinca; // la rana no quiso brinca a este bloque y se cae
                brinca++;           // la rana brinca para al siguiente bloque
            }
            else
            {
                arr[cnt] =  *rana; // se cae donde estaba la rana
                nueva_base = brinca; //la ranita brinco tenemos nueva base 
                brinca = rana+1; // nueva posición donde la rana brincara
                rana   = nueva_base; // la rana brinca a un lugar seguro!!
            }
            cnt++; // se lleno el bloque que se cayo, vamos al siguiente bloque!!!
        }
        arr[cnt] = *rana; // la rana se fue a mimir
        */

    }
 
}

int main(int argc, char const *argv[])
{
    int arr[]={35,12,87,26,0};
    split(arr,sizeof(arr)/sizeof(int));

    print_arr(arr, sizeof(arr)/sizeof(int));

    return 0;
}
