#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int n1,n2;
	cin>>n1;
	int *arr1=new int[n1];
	for(int i=0;i<n1;i++)
	{
		cin>>arr1[i];
	}
	cin>>n2;
	int *arr2=new int[n2];
	for(int i=0;i<n2;i++)
	{
		cin>>arr2[i];
	}

	sort(arr1,arr1+n1);
	sort(arr2,arr2+n2);

	int length=0;
	for(int i=0;i<n1 && i<n2;i++)
	{
		cout<<arr1[i]<<" <---> "<<arr2[i]<<endl;
		length+=abs(arr2[i]-arr1[i]);
	}

	cout<<length<<endl;
	return 0;
}