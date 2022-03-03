
#include "BubbleSort.h"
#include <algorithm>

void BubbleSort(vector<int>& A)
{
    vector<int> B;
    vector<int>::iterator result;
    while(!A.empty())
    {
        result = std::min_element(A.begin(), A.end()); // serach
        B.push_back(*result); // Move
        A.erase(result); // move
    }
    A = B; // update
}