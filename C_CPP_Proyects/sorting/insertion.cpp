#include <iostream>
#include <vector>
#include <string.h>
int count = 0;
void insertion_sort(int* seq, int size)//Tonix y lougi <|:^{) a.k.a "solo luigi"
{
    int aux;

    for(int x=1; x<size; x++)
    {
        printf("x: %d, ",x);
        printf("%d<%d\r\n",seq[x],seq[x-1]);
        if(seq[x]<seq[x-1]){
            do{
                //x = 3 , x-1 = 4
                aux=seq[x]; //aux 4
                seq[x]=seq[x-1]; //x  = 3
                seq[x-1]=aux; //x-1 = 4
                x--;
                printf("x: %d",x);
                //
            }while(seq[x]<seq[x-1] && x>0);
       }
    }
}
/*
        Loop from i = 1 to n-1.
       a) Pick element arr[i] and insert
          it into sorted sequence arr[0..i-1] 
    Recursion Idea.

    Base Case: If array size is 1 or smaller, return.
    Recursively sort first n-1 elements.
    Insert last element at its correct position in sorted array.

*/
void insert_sort_rec(int* seq, int size)//Jumex y Tutifruti :)
{
    int aux = 0;
    if(size <=1)
    {
        return;
    }
    insert_sort_rec(seq, size-1);
    int last  = seq[size-1];
    int prev  = size-2;
    while(last<seq[prev] && prev>0)
    {
        last = seq[prev];//SWAP
        prev--;///PORT ESTO
    }
    seq [prev+1] = last; // PREV+1 SWAP

//"Podemos ser felices sin hablar" -Sona, 2009
//"Podemos ser felices sin hablar" -Sona, 2009
//shhhhhhhhhh :D crewmate
}
/*  EL QUE PUEDA, O EL LUIGI O EL TONAYAN
report Telmex gg
Telmex inter por eso estas en bronze culio

{4,6,7,1,-5,2};insert_sort_rec
{4,6,7,1,-5,2};insert_sort_rec
{4,6,7,1,-5}
{4,6,7,1} === C
{4,6,7} === B
{4,6} === A
{4} /// ya esta ordenado wiii
{4,6} === A
{4,6,7} === B
{1,4,6,7} === C


*/
//zukis trukis


int main(int argc, char const *argv[])
{
    int arr[] = {4,6,7,1,-5,2};
    int arr_size = sizeof(arr)/sizeof(int);
    insertion_sort(arr,arr_size);
    //insert_sort_rec(arr,arr_size);
    for(int i=0;i<6;i++)
    {
        printf("%d,",arr[i]);
    }


    return 0;
}
//ALOHAAAAAAAAAAAAAAAAAAAAAA :D    //insertion_sort(arr,arr_size);

//{1,4,6,7,-5,2};
// ^

/*
{4,6,7,1,-5,2};
     ^
        ->
{4,6,[],7,1,-5,2};

{4,6,[3],7,1,-5,2};


#include <string.h>
#include <stdio.h>

char* hostname;

hostname = malloc(sizeof(char)*30);
strcpy(hostname,"localhost");
*/