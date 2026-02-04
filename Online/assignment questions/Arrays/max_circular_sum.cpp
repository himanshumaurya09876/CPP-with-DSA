// MAXIMUM CIRCULAR SUM
// You are provided n numbers (both +ve and -ve). Numbers are arranged in a circular form. You need to find the maximum sum of consecutive number.

// Input Format:
// First line contains integer t which is number of test case. For each test case, it contains an integer n which is the size of numbers and next line contains n space separated integers.

// Constraints:
// 1<=t<=100 1<=n<=1000

// Output Format
// Print the maximum sum.

// Sample Input
// 1
// 7
// 8 -8 9 -9 10 -11 12
// Sample Output
// 22

#include<iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t>0)
	{
		int n,i,j;
		int A[1000],sum=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>A[i];
		}
		for(i=0;i<n;i++)
		{
			int res=A[i];
			for(j=i+1;j!=i;j++)
			{
                if(j==n)
                    j=0;
                res=res+A[j];
				if(sum<res)
					sum=res;
                if(j==n-1)
                    j=-1;
			}
		}
		cout<<sum<<endl;
		t--;
	}
	return 0;
}