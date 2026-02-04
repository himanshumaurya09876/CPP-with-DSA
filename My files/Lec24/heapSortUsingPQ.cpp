#include <iostream>
#include <queue>
using namespace std;

void heapsort(int arr[],int n,int choice=true)
{
	if(choice)
	{
		priority_queue<int, vector<int>, greater<int> > pq;
		for(int i=0;i<n;i++)
		{
			pq.push(arr[i]);
		}		
		for(int i=0;i<n;i++)
		{
			arr[i]=pq.top();
			pq.pop();
		}
	}
	else
	{
		priority_queue<int> pq;
		for(int i=0;i<n;i++)
		{
			pq.push(arr[i]);
		}		
		for(int i=0;i<n;i++)
		{
			arr[i]=pq.top();
			pq.pop();
		}
	}
}

int main(int argc, char const *argv[])
{
	int n,arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	//heapsort(arr,n,false);//for descending order
	heapsort(arr,n);//for ascending order
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}