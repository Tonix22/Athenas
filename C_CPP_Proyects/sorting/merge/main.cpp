#include <iostream>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>

int* split(int arr[],int size)
{
    int mid2 = size/2;
    int mid1 = size-mid2;
    int a[mid1];
    int b[mid2];

    if(mid2!=0)
    {
        // copias temporales
        memcpy(a,arr,mid1*sizeof(int));
        memcpy(b,arr+mid2,mid2*sizeof(int));

        split(a,mid2); // Has esto con papel amigo
        split(b,mid1); // Igual para esto

        //ALTO!! 
        //Aqui solo vamos a llegar cuando 
        // la ranita tenga dos hojitas para brincar
        // como minimo.
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
        
        return arr;
    }
    else
    {
        return arr;
    }
}

int main(int argc, char const *argv[])
{
    int arr[]={35,12,87,26};
    split(arr,sizeof(arr)/sizeof(int));


    return 0;
}
