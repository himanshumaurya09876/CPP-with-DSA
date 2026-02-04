// ARRAYS-TARGET SUM PAIRS
// Take as input N, the size of array. Take N more inputs and store that in an array. Take as input “target”, a number. Write a function which prints all pairs of numbers which sum to target.

// Input Format:
// The first line contains input N. Next N lines contains the elements of array and (N+1)th line contains target number.

// Constraints:
// Length of the arrays should be between 1 and 1000.

// Output Format
// Print all the pairs of numbers which sum to target. Print each pair in increasing order.

// Sample Input
// 5
// 1
// 3
// 4
// 2
// 5
// 5
// Sample Output
// 1 and 4
// 2 and 3

#include<iostream>
using namespace std;

void fun(int arr[],int n,int t)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==t)
            {
                if(arr[i]<arr[j])
                    cout<<arr[i]<<" and "<<arr[j]<<endl;
                else
                    cout<<arr[j]<<" and "<<arr[i]<<endl;
            }
        }
    }
}

int main() {
    int n,t;
    int arr[1000];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>t;
    fun(arr,n,t);
	return 0;
}