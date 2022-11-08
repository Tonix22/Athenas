#include <iostream>
#include <unordered_set>
using namespace std;

// Not completly optimized but work
void bureka_algorithm() 
{
    int t = 0;
    //N test cases
    cin >> t;
    
    while(t--)
    {
        int n = 0;
        //n elements per test case
        cin >> n;
        int* arr = new int[n];
        
        //Recieved elements
        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        
        // Partial XOR sums
        int count_zero = 0;
        unordered_set<int> repeated;
        for(int i = 1; i < n; ++i)
        {
            arr[i] ^= arr[i - 1];
            //cout<< arr[i]<<", ";
        }
        //cout<<endl;
        repeated.insert(0);

        //Remove repeated elements that may be cleared with XOR
        for(int i = 0; i < n; ++i)
        {
            if(repeated.find(arr[i]) != repeated.end()){
                count_zero++;
                repeated.clear();
            }
            repeated.insert(arr[i]);
        }
       
        cout << n - count_zero << endl;
    }
}
int main(int argc, char const *argv[])
{       
    bureka_algorithm();
    return 0;
}





