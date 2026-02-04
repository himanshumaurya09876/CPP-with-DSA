// MAXIMUM LENGTH BIOTONIC SUBARRAY
// You are provided n numbers of array. You need to find the maximum length of bitonic subarray. A subarray A[i … j] is biotonic if there is a k with i <= k <= j such that A[i] <= A[i + 1] … <= A[k] >= A[k + 1] >= .. A[j – 1] > = A[j] i.e subarray is first increasing and then decreasing or entirely increasing or decreasing.

// Input Format:
// First line contains integer t which is number of test case. For each test case, it contains an integer n which is the size of array and next line contains n space separated integers.

// Constraints:
// 1<=t<=100 1<=n<=1000000

// Output Format
// Print the maximum length.

// Sample Input
// 2
// 6
// 12 4 78 90 45 23
// 4
// 40 30 20 10
// Sample Output
// 5
// 4

#include<iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t>0)
	{
		int n,i,j,size=0,maxsize=0;
		int A[1000000];
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>A[i];
		}
		for(int i=0;i<n;i++)
		{
			size=1;
			for(j=i;j>0;j--)
			{
				if(A[j-1]<A[j])
					size++;
				else
					break;
			}
			for(j=i;j<n-1;j++)
			{
				if(A[j]>A[j+1])
					size++;
				else
					break;
			}
			if(maxsize<size)
			{
				maxsize=size;
			}
		}
		cout<<maxsize<<endl;
		t--;
	}
	return 0;
}