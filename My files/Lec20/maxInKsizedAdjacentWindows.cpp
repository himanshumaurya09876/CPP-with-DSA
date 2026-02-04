#include <iostream>
#include <deque>
using namespace std;

void printMaxInwind(int arr[],int n,int k)
{
	deque<int> d;
	d.push_back(0);
	for(int i=1;i<n;i++)
	{
		if(i<k)
		{
			while(!d.empty() && arr[i]>=arr[d.back()])
			{
				d.pop_back();
			}
			d.push_back(i);
		}
		else
		{
			cout<<arr[d.front()]<<" ";
			if(d.front()<=i-k)
			{
				d.pop_front();
			}
			while(!d.empty() && arr[i]>=arr[d.back()])
			{
				d.pop_back();
			}
			d.push_back(i);
		}
	}
	cout<<arr[d.front()]<<" ";
	d.pop_front();
}

int main(int argc, char const *argv[])
{
	int n,arr[100],k;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cin>>k;
	printMaxInwind(arr,n,k);
	return 0;
}