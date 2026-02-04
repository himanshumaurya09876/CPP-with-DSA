// UNLOCK
// Shekhar is a bomb defusal specialist. He once encountered a bomb that can be defused only by a secret code. He is given a number N and a number K. And he is also given permutation of first N natural numbers . The defusal code is the largest permutation possible by doing exactly K swaps among a pair of the given permutation. Help him to find the final permutation.

// Input Format:
// First line contains ​an integer N and an integer k. The next line contains N space separated integers denoting the given permutation.

// Constraints:
// 1 <= n <= 10^5 1<= K <= 10^9

// Output Format
// The final permutation of the numbers with every number separated by a space with other number.

// Sample Input
// 5 2
// 3 4 1 2 5
// Sample Output
// 5 4 3 2 1

#include <iostream>
#include <unordered_map>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,k;
	cin>>n>>k;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	unordered_map<int,int> hash;
	for(int i=0;i<n;i++)
	{
		hash.insert(make_pair(arr[i],i));
	}

	int num=n;
	while(k>0 && num>0)
	{
		int pos=n-num;
		if(pos!=hash[num])
		{
            hash[arr[pos]]=hash[num];
            swap(arr[pos],arr[hash[num]]);
            hash[num]=pos;
			k--;
		}
		num--;
	}

	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}