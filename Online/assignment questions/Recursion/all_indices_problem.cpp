// ALL INDICES PROBLEM
// Take as input N, the size of array. Take N more inputs and store that in an array. Take as input M, a number. Write a recursive function which returns an array containing indices of all items in the array which have value equal to M. Print all the values in the returned array.

// Input Format:
// Enter a number N(size of the array) and add N more numbers to the array Enter number M to be searched in the array

// Constraints:
// None

// Output Format
// Display all the indices at which number M is found in a space separated manner

// Sample Input
// 5
// 3
// 2
// 1
// 2
// 3
// 2
// Sample Output
// 1 3

#include<iostream>
using namespace std;

int createans(int arr[100],int n,int m,int ans[100],int k=0,int i=0)
{
    if(i==n)
    {
        return k;
    }
    if(arr[i]==m)
    {
        ans[k]=i;
        k++;
    }
    return createans(arr,n,m,ans,k,i+1);
}

int main() {
    int n,arr[100],ans[100],m,k;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>m;
    k=createans(arr,n,m,ans);
    for(int i=0;i<k;i++)
    {
        cout<<ans[i]<<" ";
    }
	return 0;
}