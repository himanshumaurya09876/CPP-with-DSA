// SORTING IN LINEAR TIME
// You will be given an array containing only 0s, 1s and 2s. you have sort the array in linear time that is O(N) where N is the size of the array.

// Input Format:
// The first line contains N, which is the size of the array. The following N lines contain either 0, or 1, or 2.

// Constraints:
// Each input element x, such that x ∈ { 0, 1, 2 }.

// Output Format
// Output the sorted array with each element separated by a newline.

// Sample Input
// 5
// 0
// 1
// 2
// 1
// 2
// Sample Output
// 0
// 1
// 1
// 2
// 2


#include<iostream>
using namespace std;
int main() {
	int arr[100000],n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int low=0,mid=0,high=n-1;
	while(mid<=high)
	{
		int temp;
		if(arr[mid]==2)
		{
			temp=arr[mid];
			arr[mid]=arr[high];
			arr[high]=temp;
			high--;
		}
		else if(arr[mid]==0)
		{
			temp=arr[mid];
			arr[mid]=arr[low];
			arr[low]=temp;
			mid++;
			low++;
		}
		else
		{
			mid++;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
	return 0;
}