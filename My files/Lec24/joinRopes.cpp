#include <iostream>
#include <queue>

using namespace std;

int findMinTotalCost(int arr[],int n)
{
	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i=0;i<n;i++)
	{
		pq.push(arr[i]);
	}
	int total=0;

	// int sum=pq.top();
	// pq.pop();
	// while(!pq.empty())
	// {
	// 	sum+=pq.top();
	// 	pq.pop();
	// 	total+=sum;
	// 	cout<<total<<endl;
	// }

	int curr=0;
	int last=pq.top();
	pq.pop();
	while(!pq.empty())
	{
		curr=pq.top()+last;
		pq.pop();
		last=curr;
		total+=curr;
	}
	return total;
}

int main(int argc, char const *argv[])
{
	int n,arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<findMinTotalCost(arr,n)<<endl;
	return 0;
}