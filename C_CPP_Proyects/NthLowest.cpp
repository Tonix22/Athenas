#include <stdio.h>
using namespace std;
#define ARsize 10

struct NthLowest{
    int nthl(int nth, int* array){
        int aux;
        int i=0;
        printf("I NEED THE %dth", nth);

        for(int x=1; x<ARsize; x++){
            if(array[x]<array[x-1]){
                for(int y=x; y>0; y--){
                    if(array[y]<array[y-1]){
                        aux=array[y];

                        if(x==nth){
                            return aux;
                        }

                        array[y]=array[y-1];
                        array[y-1]=aux;
                    }
                }
            }
        }

        for(int i=0; i<sizeof(array)/sizeof(array[0]); i++){
            printf("%d ", array[i]);
        }

        return aux;
    }
};


int main(int argc, char const *argv[]){
    int numbers[ARsize]={1, 0, 2, 9, 3, 8, 4, 7, 5, 6};
    int n=3;
    NthLowest run;

    printf("%dth lowest number from ", n);
    for(int i=0; i<ARsize; i++){
        printf("%d ", numbers[i]);
    }
    
    printf("...\n%dth lowest number is: %d", n, run.nthl(n, numbers));

    return 0;
}
