// C++ implementation of Radix Sort 
#include<stdio.h>
#include<string.h>
#include "radix.h"
// A utility function to get maximum value in arr[] 
int getMax(int arr[], int n) 
{ 
	int mx = arr[0]; 
	for (int i = 1; i < n; i++) 
		if (arr[i] > mx) 
			mx = arr[i]; 
	return mx; 
} 

// A utility function to print an array 
void print_arr(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		printf("%d",i);
}

void my_radix(int arr[], int n)
{
	// Find the maximum number to know number of digits 
	int max = getMax(arr, n);

	int i, count[2] = {0}; 
	int output[n]; // output array 
	for (int bit = 0; max > 0; bit++)
	{
		max>>=1;

		for(i=0; i < n; i++)
		{
			count[ (arr[i] & (1<<bit)) >> bit]++;
		}

		count[1]+=count[0];/// count 0 [0,j] , count 1[j+1,size]

		for (i = n - 1; i >= 0; i--) 
		{ 
			output[count[ (arr[i] & (1<<bit)) >> bit] - 1] = arr[i]; 
			count[(arr[i] & (1<<bit)) >> bit]--; 
		}
		count[1]=0;//delete pitvot
		memcpy(arr,output,n*sizeof(int));
	}
}
/*
// Driver program to test above functions 
int main() 
{ 
	int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
	//int arr[] = {5, 8, 11, 1}; 
	int n = sizeof(arr)/sizeof(arr[0]);
	my_radix(arr, n); 
	//radixsort(arr, n); 
	print_arr(arr, n); 
	return 0; 
} 
*/