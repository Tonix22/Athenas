#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

void print(int arr[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;
}


void func();
int main(int argc, char const *argv[])
{       
    //int set7[] = {27,27,34,32,2,31,23,56,52,4}; // 7 
    //int set6[] = {1822,1799,57,23,55}; // 4 
    //int set5[]  = {1, 2, 3, 3, 2, 1}; // 4 
    //int set4[] = {5,5 ,5, 5}; // 2
    //int set3[] = {1,3,2}; // 2
    //int set1[] = {0,0}; // 0
    //int size = 2;
    //int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 4 a 8 39
    // subArray(arr,4,8);
    //A XOR B = C
    //A = B XOR C

    

    //for(int i = 1; i < size; ++i)
    //{
    //    set1[i] ^= set1[i - 1];
    //}



    // cout <<  (arr[8] ^ arr[4]) << endl;

    //print(set1, size);
    func();
    
    return 0;
}

void func()
{
    int t = 0; 
    cin >> t;

    while(t--)
    {
        int n = 0;
        cin >> n;
        int* arr = new int[n];
        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        
        int count_zero = 0;
        unordered_set<int> repeated;
        for(int i = 1; i < n; ++i)
        {
            arr[i] ^= arr[i - 1];
            //cout<< arr[i]<<", ";
        }
        //cout<<endl;
        repeated.insert(0);
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



