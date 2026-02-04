// ARRAYS-TARGET SUM TRIPLETS
// Take as input N, the size of array. Take N more inputs and store that in an array. Take as input “target”, a number. Write a function which prints all triplets of numbers which sum to target.

// Input Format:
// First line contains input N. Next N lines contains the elements of array and N+1 line contains target number.

// Constraints:
// Length of Array should be between 1 and 1000.

// Output Format
// Print all the triplet present in the array.

// Sample Input
// 9
// 5
// 7
// 9
// 1
// 2
// 4
// 6
// 8
// 3
// 10
// Sample Output
// 1, 2 and 7
// 1, 3 and 6
// 1, 4 and 5
// 2, 3 and 5

#include <iostream>
using namespace std;
void sort(int arr[],int n)
{
    int min;
    for(int i=0;i<n;i++)
    {
        min=arr[i];
        for(int j=i;j<n;j++)
        {
            if(min>arr[j])
            {
                min=arr[j];
                arr[j]=arr[i];
                arr[i]=min;
            }
        }
    }
}
void fun(int arr[],int n,int t)
{
	for(int i=0;i<n-2;i++)
	{
		int *l=&arr[i+1],*r=&arr[n-1];
    	while(*l<*r)
    	{
        	if(*l + *r==t-arr[i])
        	{
            	cout<<arr[i]<<", "<<*l<<" and "<<*r<<endl;
           	 	l++;
            	r--;
        	}
        	else if(*l + *r <t-arr[i])
        	{
            	l++;
        	}
        	else
        	{
            	r--;
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
    sort(arr,n);
    fun(arr,n,t);
	return 0;
}