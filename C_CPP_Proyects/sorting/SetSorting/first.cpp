#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std; // :)

#define SORT(NAME) sort_vector_##NAME(A)

#define PRINTARR()  for(auto it: A){\
                    std::cout<<it<<std::endl;\
                    }\

/*
Step 1
    A={4,5,7,6};
    B={1}
Step 2
    A={5,7,6};
    B={1,4};
Step 3
    A={7,6};
    B={1,4,5};
Step 4
    A={7};
    B={1,4,5,6};
Step 4
    A={}; // esta vacio
    B={1,4,5,6,7}
*/

void sort_vector_Paco(vector<int>& A)
{
    vector<int> B;
    vector<int>::iterator min;
    int size = A.size();

    for(int i = 0; i < size; i++){ 
        min = std::min_element(A.begin(), A.end());
        B.push_back(*min);
        A.erase(min);
    }
    //N^2
    A=B;
}


void sort_vector_Ruth(vector<int>& A)
{
    vector<int> B;
    vector<int>::iterator result;
    while(!A.empty())
    {
        result = std::min_element(A.begin(), A.end());
        B.push_back(*result);
        A.erase(result);
    }
    A = B;
}


int main(int argc, char const *argv[])
{
    vector<int> A={4,5,7,1,6};
    A.push_back(2); // append
    A.pop_back();   //remove
    A[0]; // acces elmenet
    A.empty();
    //A.erase(it)
    vector<int>::iterator result = std::min_element(A.begin(), A.end()); // retorna min pointer
    std::cout<<"previous"<<std::endl;
    PRINTARR();
    //sort_vector_Paco(A); // SORT(Paco);
    SORT(Ruth);
    std::cout<<"sorted"<<std::endl;
    PRINTARR();

    return 0;
}
