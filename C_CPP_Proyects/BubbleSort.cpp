/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int aux;
    
    int array[10]={1, 0, 2, 9, 3, 8, 4, 7, 5, 6};
    //printf("%d\n", sizeof(array)/sizeof(array[0])); //C++ is an ugly bastard

    for(int x=0; x<sizeof(array)/sizeof(array[0]); x++){
        if(x>0 && array[x]<array[x-1]){
            
            //printf("Comparing %d to %d: ", array[x], array[x-1]);

            for(int y=x; y>0; y--){
                if(array[y]<array[y-1]){
                    aux=array[y];
                    array[y]=array[y-1];
                    array[y-1]=aux;
                }
            }

            //printf(" %d, %d\n", array[x-1], array[x]);
        }
    }

    for(int i=0; i<sizeof(array)/sizeof(array[0]); i++){
        printf("%d ", array[i]);
    }
    
    //printf("NOT Hello World");

    return 0;
}
