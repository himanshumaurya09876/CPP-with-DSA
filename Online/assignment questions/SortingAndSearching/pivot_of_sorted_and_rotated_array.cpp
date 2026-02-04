// PIVOT OF SORTED AND ROTATED ARRAY
// You are given a sorted but rotated array. You need to fine the index of the pivot element of the array where pivot is that element in the array which is greater than its next element and divides the array into two monotonically increasing halves.

// Input Format:
// The first line denotes N - the size of the array. The following N lines each denote the numbers in the array.

// Constraints:
// Output Format
// Output the index of the pivot of the array.

// Sample Input
// 5
// 4
// 5
// 1
// 2
// 3
// Sample Output
// 1

#include<iostream>
using namespace std;
int main() {
    int arr[100],n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    i=0;
    while(arr[i]<arr[i+1])
	{
		i++;
	}
    cout<<i;
    return 0;
}