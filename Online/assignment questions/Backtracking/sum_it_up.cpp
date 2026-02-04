// SUM IT UP
// You are given an array of numbers and a target number(T) , print all unique combinations in the array whose sum equals the target number T. Note that each number in the array may only be used once in the combination.
// Note:

// All numbers (including target) will be positive integers
// Elements in the combination must be in non-descending order
// There should be no duplicate combinations
// Input Format:
// The first line will contain N indicating the number of elements in the array.
// The second line will contain space separated N integers , A[i].
// The third line will contain the target number T.

// Constraints:
// N <= 15 1<= A[I] <= 100

// Output Format
// Print all unique combinations of the numbers satisfying the above constraints in a separate line in lexicographic manner.

// Sample Input
// 7
// 10 1 2 7 6 1 5
// 8
// Sample Output
// 1 1 6 
// 1 2 5 
// 1 7 
// 2 6 

#include <iostream>
#include <algorithm>
using namespace std;

void printComb(int arr[],int n,int sum,int sol[],int j=0,int k=0)
{
	if(sum==0)
	{
		for(int i=0;i<j;i++)
		{
			cout<<sol[i]<<" ";
		}
		cout<<endl;
		return;
	}
	else if(sum<0)
	{
		return;
	}
	sol[j]=arr[k];
	printComb(arr,n,sum-arr[k],sol,j+1,1+k);
	for(int i=k+1;i<n;i++)
	{
		if(arr[i]!=arr[i-1])
		{
			sol[j]=arr[i];
			printComb(arr,n,sum-arr[i],sol,j+1,1+i);
		}
	}
}

int main() {
	int n,arr[100],sol[100]={0},t;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cin>>t;
	sort(arr,arr+n);
	for(int i=0;i<n;i++)
	{ 
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	printComb(arr,n,t,sol);
	return 0;
}