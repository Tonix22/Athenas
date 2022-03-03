#include "BubbleSort.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    vector<int> arr{10,9,2,4,1,0};
    BubbleSort(arr);
    for(int& n:arr)
    {
        cout<< n <<" ,";
    }
    cout<<endl;
    return 0;
}
