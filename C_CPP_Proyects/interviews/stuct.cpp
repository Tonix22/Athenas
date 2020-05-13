#include <stdio.h>
int main(int argc, char const *argv[])
{
    char arr[] = {"y   el alababa la ley"};
    int size = sizeof(arr);
    char *p1;
    char *p2;
    p1 = arr;
    p2 = &arr[size-2];
    int palindromo = 0;
    printf("size : %d", size);
    printf("p1 : %c", *p1);
    printf("p2 : %c", *p2);
    while( (*p1==*p2) && (p1!=p2) ){
        p1++;
        p2--;
        while(*p1 ==' ' ){
            p1++;
        }
        while(*p2 ==' '){
            p2--;
        }

        printf("p1 : %c", *p1);
        printf("p2 : %c", *p2);
    }

    if(p1==p2){
        palindromo=1;
        printf("Palindromo!!");
    }else{
        printf("No palindromo!!");
    }
    return 0;
}
