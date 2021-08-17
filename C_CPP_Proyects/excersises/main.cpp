#include "stdio.h"
#include <iostream>

using namespace std;

int factorial(int n)//3, 2, 1
{
    return (n != 0) ? n * factorial(n-1) : 1;
}

int main(int argc, char const *argv[])
{
    cout<<factorial(5)<<endl;
    /* code */
    return 0;
}
