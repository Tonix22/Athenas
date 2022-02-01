#include <stdio.h>
int check( char *ptr);

int check(char* ptr) { 
    // es una copia temporal 
    //ptr apunta igual que el ptr de afuera, 
    ptr="Yellow";
    return 0;
}

void check2( char **ptr) {
char *new_ptr = "Yellow";
//ptr="Yellow";
*ptr = new_ptr;
}

int check3( char **ptr) {
char *new_ptr = "Yellow";
//ptr="Yellow";
*ptr = new_ptr;
return 0;
}

int main() {
    char *ptr="Blue";
    check(ptr);
    check3(&ptr);
    printf("%s \n",ptr);
    return 0;
}

