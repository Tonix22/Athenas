#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;

int price[11]  = {0,1,5,8,9,10,17,17,20,24,30};
int r[11]      = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}; // revenue for different lenght 
int s[11];
int cost = 1;

int counter= 0;
int opt = 0;

int CutRod(int n)
{
    int q = INT_MIN;
    if(n == 0)
    {
        return 0;
    }
    for(int i=1;i <= n;i++)
    {
        q =  max(q,price[i]+CutRod(n-i));
    }
    counter++;
    return q;
}

int memoized_solution(int n)
{
    opt++;
    if(r[n] >= 0)
    {
        
        return r[n];
    }
    if(n==0)
    {
        return 0;
    }
    else 
    {
        int q = INT_MIN;
        for(int i=1;i <= n;i++)
        {
             q =  max(q,price[i]+memoized_solution(n-i));
        }
        r[n] = q;
        return q;
    }
}
int button_up(int n)
{
    r[0]=0;
    for (int j = 1; j <= n; j++)
    {
        int q = INT_MIN;
        for (int i = 1; i <= j; i++)
        {
            if (q < price[i]+r[j-i])
            {
                q = price[i]+r[j-i];
                s[j]=i;
            }
        }
        r[j] = q;
    }
    return r[n];
}
int button_up_with_charge(int n)
{
    r[0]=0;
    int charge = 0;
    for (int j = 1; j <= n; j++)
    {
        int q = INT_MIN;
        for (int i = 1; i <= j; i++)
        {
            // if i and j are the same there 
            //are not cuts so there is not charge
            charge = (i!=j) & cost; 
            if (q < price[i]+r[j-i]-charge)
            {
                q = price[i]+r[j-i]-charge;
                s[j]=i;
            }
        }
        r[j] = q;
    }
    return r[n];
}
int main(int argc, char const *argv[])
{
    /* code */
    CutRod(2);//exponetial growth 2^n
    memoized_solution(2);
    button_up(10);
    button_up_with_charge(10);
    //cout<<"counter: "<<counter <<endl;
    //cout<<"opt: "    <<opt     <<endl;
    //cout<<"*****"<<endl;
    //cout<<"cut: "<<cut<<endl;    
    //cout<<"mem: "<<mem<<endl;
    return 0;
}
