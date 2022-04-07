#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> A {3, 6, 6, 6};
    vector<int> B {2, 7 , 4, 1};
    int opt = 0;
    int  n = 3;//size -1
    int sum1 = 0;
    int sum2 = 0;
    for (int i = n-1; i>=0; i--)
    {
        for (int j = i; j<n; j++)
        {
            sum1 += pow(A[i]+A[j+1],2) + pow(B[i]+B[j+1],2);
            sum2 += pow(B[i]+A[j+1],2) + pow(A[i]+B[j+1],2);
        }
        sum1+=opt;
        sum2+=opt;
        if(sum2 < sum1)
        {
            swap(A[i],B[i]);
        }
        opt = min(sum1,sum2);
        sum1 = 0;
        sum2 = 0;
    }
    
    for (auto k : A)
    {
        cout<<k<<" "; 
    }

    cout<<endl;

    for(auto k : B)
    {
        cout<<k<<" ";
    }
    cout<<endl;
    return 0;
}
