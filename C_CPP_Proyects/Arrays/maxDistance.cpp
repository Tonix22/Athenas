#include <bits/stdc++.h>
#include <vector>
#include <utility>
#include <set>

using namespace std;
 
/* For a given array arr[], 
   returns the maximum j – i such that
   arr[j] > arr[i] */
int maxIndexDiff(int arr[], int n)
{
    int leftMin[n] ;
    leftMin[0] = arr[0];
    for(int i = 1 ; i<n; i++)
        leftMin[i] = min(leftMin[i-1], arr[i]);

    int maxDist = INT_MIN;
    int i = n-1, j = n-1;
 
    while(i>=0  &&  j>=0)
    {
        if(arr[j] >= leftMin[i])
        {
            maxDist = max(maxDist, j-i);
            i--;
        }
        else
            j--;
    }
 
    return maxDist;
 
         
}
int maximumGap(const vector<int> &A) 
{
    set<pair<int,int>> hash;
    int n = A.size();
    int maxDiff = INT_MIN;
    int temp = n;
    for(int i = 0 ;i<n;i++)
    {
        hash.insert({A[i],i});
    }
    for (auto it = hash.begin(); it != hash.end() ; it++) 
    {
        if (temp > it->second) 
        {
            temp = it->second;
        }
        maxDiff = max(maxDiff, it->second- temp);
    }
    return maxDiff;
}



// Driver Code
int main()
{
    vector<int> arr{ 34, 8, 10, 3, 2, 80, 30, 33, 1 };
    int ans = maximumGap(arr);
    cout << "The maxIndexDiff is : " << ans << endl;
    return 0;
}