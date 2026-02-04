#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[1000][1000];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}

	//take transpose
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			swap(arr[i][j],arr[j][i]);
		}
	}

	//reverse each column
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n/2;j++)
		{
			swap(arr[j][i],arr[n-j-1][i]);
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}