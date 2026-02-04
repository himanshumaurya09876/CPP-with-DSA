// SORTED ARRAY
// Take as input N, the size of an integer array. Take one more input, which is a list of N integers separated by a space, and store that in an array. Write a recursive function which prints true if the array is sorted, and false otherwise.

// Input Format:
// N x y z

// Constraints:
// 1 < N < 1000
// -10^9 < i < 10^9, where i is an element of the array

// Output Format
// true OR false

// Sample Input
// 5
// 1 2 3 4 5
// Sample Output
// true

#include<iostream>
using namespace std;

bool checkSort(int arr[1000],int n,int i=0)
{
    if(i==n-1)
    {
        return true;
    }
    if(arr[i]>arr[i+1])
    {
        return false;
    }
    return checkSort(arr,n,i+1);
}

int main() {
    int n,arr[1000];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bool res=checkSort(arr,n);
    if(res==0)
    {
        cout<<"false";
    }
    else
    {
        cout<<"true";
    }
	return 0;
}