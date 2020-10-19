#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

int price[10]  = {1,5,8,9,10,17,17,20,24,30};
int revenue[10]; // revenue for different lenght 

int CutRod(int n)
{
    int q = INT_MIN;
    if(n == 0)
    {
        return 0;
    }
    for(int i=1;i < n;i++)
    {
        q =  max(q,price[i]+CutRod(n-i));
    }
    return q;
}

int main(int argc, char const *argv[])
{
    /* code */
    CutRod(3);
    return 0;
}
