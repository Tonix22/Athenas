#include <vector>
#include <iostream>
#include <map>
#include <math.h>
#include <unordered_map>

using namespace std;

int repeatedNumber(const vector<int> &A) {
    int n = A.size();
    int sq = sqrt(n);
    int blocks = (n / sq) + 1;
    int count[blocks] = {0};
    for (int i = 0; i <= n; i++)
    {
        count[(A[i] - 1) / sq]++;
    }
    int selected_block = blocks - 1;
    for (int i = 0; i < blocks - 1; i++)
    {
        if (count[i] > sq)
        {
            selected_block = i;
            break;
        }
    }
    unordered_map<int, int> m;
    for (int i = 0; i <= n; i++)
    {
        if (((selected_block * sq) < A[i]) &&
                (A[i] <= ((selected_block + 1) * sq)))
        {
            m[A[i]]++;
 
            if (m[A[i]] > 1)
                return A[i];
        }
    }
    return -1;
}

// Driver Program
int main()
{
    // read only array, not to be modified
   const vector<int> arr{ 1, 1, 2, 3, 5, 4 };
 
    cout << "One of the numbers repeated in"
         " the array is: "
         << repeatedNumber(arr) << endl;
}