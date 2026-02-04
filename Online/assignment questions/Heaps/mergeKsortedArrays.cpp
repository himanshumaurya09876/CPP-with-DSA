// MERGE K SORTED ARRAYS
// Given K sorted arrays each with N elements merge them and output the sorted array

// Input Format:
// First line contains 2 integers K and N.

// K is number of arrays.

// N is number of elements in each array.

// Constraints:
// Elements of array <= |10^15| N <= 10^5 K <= 10

// Output Format
// Single line consisting of space separated numbers

// Sample Input
// 3 4
// 1 3 5 7
// 2 4 6 8
// 0 9 10 11
// Sample Output
// 0 1 2 3 4 5 6 7 8 9 10 11

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
	int k,n;
	cin>>k>>n;
	int **arr=new int*[k];
	for(int i=0;i<k;i++)
	{
		arr[i]=new int[n];
	}

	for(int i=0;i<k;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}

	vector<int> finalArr;
	priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > pq;
	for(int i=0;i<k;i++)
	{
		pq.push(make_pair(arr[i][0],make_pair(i,0)));
	}
	while(pq.top().first!=INT_MAX)
	{
		pair<int,pair<int,int> > p;
		p=pq.top();
		finalArr.push_back(p.first);
		pq.pop();
		if(n-1<=p.second.second)
		{
			pq.push(make_pair(INT_MAX,make_pair(p.second.first,p.second.second+1)));
		}
		else
		{
			pq.push(make_pair(arr[p.second.first][p.second.second+1],make_pair(p.second.first,p.second.second+1)));
		}
	}

	for(int i=0;i<finalArr.size();i++)
	{
		cout<<finalArr[i]<<" ";
	}
	return 0;
}