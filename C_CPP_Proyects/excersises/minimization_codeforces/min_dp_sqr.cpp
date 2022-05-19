#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>

using namespace std;

void minimization2(int n, vector<int> a, vector<int> b)
{

	int minSum = 0, maxSum = 0, sumOfSquares = 0;
	for(int i = 0; i < n; ++i)
	{
		if(a[i] > b[i])
			swap(a[i], b[i]);
		
		minSum += a[i];
		maxSum += b[i];
		sumOfSquares += a[i] * a[i] + b[i] * b[i];
	}

	set<int> s;
    set<int> tempSet;

	for(int i = 0; i < n; ++i)
	{
		int diff = b[i] - a[i];
		
		// iterate set, add the value to 
		// everyone on the set, then insert the value itself
		for (set<int>::iterator it=s.begin(); it!=s.end(); ++it)
        {
            // cout << " " << (diff + *it);
			tempSet.insert(diff + *it);
        }
        
		s.insert(diff);
        s.insert(tempSet.begin(), tempSet.end());
        tempSet.clear();
	}

    int ans = 10e9;
    for(set<int>::iterator it=s.begin(); it!=s.end(); ++it) 
    {
        int diff = *it;
        int temp = (minSum + diff) * (minSum + diff) + (maxSum - diff) * (maxSum - diff);
        ans = min(ans, temp);
    }
    cout << ((n - 2) * sumOfSquares) + ans << endl;
}
void minimization(int n, vector<int> A, vector<int> B) 
{
	
    // vector<int> A {3, 6, 6, 6};
    // vector<int> B {2, 7 , 4, 1};

    int opt = 0;
    n = n - 1;//size -1
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
    
    cout << opt << endl;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;

	while(t--)
	{
		
		int n = 0;
		cin >> n;
		
		vector<int> A(n), B(n);
	   	for(auto &x : A)
		    cin >> x;
		
		for(auto &x: B)
		    cin >> x;

		minimization(n, A, B);
        cout << "---- me" << endl;
        minimization2(n, A, B);
	}
	return 0;
}

