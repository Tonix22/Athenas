#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {

    int array[10]={1, 0, 2, 9, 3, 8, 4, 7, 5, 6};
    int aux;

    for(int x=1; x<sizeof(array)/sizeof(array[0]); x++){
        if(array[x]<array[x-1]){
            for(int y=x; y>0; y--){
                if(array[y]<array[y-1]){
                    aux=array[y];
                    array[y]=array[y-1];
                    array[y-1]=aux;
                }
            }
        }
    }

    //Print
    for(int i=0; i<sizeof(array)/sizeof(array[0]); i++){
        printf("%d ", array[i]);
    }

    return 0;
}
