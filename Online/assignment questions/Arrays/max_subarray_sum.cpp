// MAXIMUM SUBARRAY SUM
// You are given a one dimensional array that may contain both positive and negative integers, find the sum of contiguous subarray of numbers which has the largest sum. For example, if the given array is {-2, -5, 6, -2, -3, 1, 5, -6}, then the maximum subarray sum is 7.

// Input Format:
// The first line consists of number of test cases T. Each test case consists of N followed by N integers.

// Constraints:
// 1 <= N <= 100000

// 1 <= t <= 20

//  -100000000 <= A[i] <= 100000000

// Output Format
// The maximum subarray sum

// Sample Input
// 2
// 4
// 1 2 3 4
// 3
// -10 5 10
// Sample Output
// 10
// 15

#include<iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t>0)
	{
		int n,i,j;
		long int A[100000],sum=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>A[i];
		}
		for(i=0;i<n-1;i++)
		{
			long int res=A[i];
			for(j=i+1;j<n;j++)
			{
				res=res+A[j];
				if(sum<res)
					sum=res;
			}
		}
		cout<<sum<<endl;
		t--;
	}
	return 0;
}