#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	sort(arr,arr+n);

	int sum;
	cin>>sum;

	int total=0;
	for(int i=n-1;i>=0 && sum>0;i--)
	{
		int coins=sum/arr[i];
		if(coins!=0)
		{
			cout<<arr[i]<<" -> "<<coins<<endl;
			total+=coins;
			sum=sum%arr[i];
		}
	}
	cout<<"Minimum number of coins -> "<<total<<endl;
	return 0;
}