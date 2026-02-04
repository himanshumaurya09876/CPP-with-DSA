// FIND UPPER AND LOWER BOUND
// Find position of the last and first occurrence of a given number in a sorted array. If number not exist then print lower and upper bound as -1.

// Input Format:
// An integer n denoting the size of the array followed by n integers denoting array elements Followed by T testcases Each testcase contains integer x (whose positions are to be found)

// Constraints:
// Output Format
// Lower bound position followed by upper bound position separates by space in each line

// Sample Input
// 5
// 1 2 3 3 4
// 3
// 2
// 3
// 10
// Sample Output
// 1 1
// 2 3
// -1 -1

#include<iostream>
using namespace std;
int main() {
	int n,arr[100],t;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cin>>t;
	while(t>0)
	{
		int m,lb=-1,ub=-1,i;
		cin>>m;
		for(i=0;i<n;i++)
		{
			if(m==arr[i] && lb==-1)
			{
				lb=i;
			}
			if(arr[i]>m)
			{
				break;
			}
		}
		if(lb!=-1)
		{
			ub=i-1;
		}
		cout<<lb<<" "<<ub<<endl;
		t--;
	}
	return 0;
}