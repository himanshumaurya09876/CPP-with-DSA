//(1) check if any subarray sum is equal to k in a given array
//(2) identify and print the largest subarray with sum k
#include <iostream>
#include <unordered_map>
using namespace std;

bool isSum0found(int arr[],int n)
{
	int csum[100]={0};
	unordered_map<int,int> map;
	csum[0]=arr[0];
	for(int i=1;i<n;i++)
	{
		csum[i]=csum[i-1]+arr[i];
	}

	// for(int i=0;i<n;i++)
	// {
	// 	cout<<csum[i]<<" ";
	// }

	for(int i=0;i<n;i++)
	{
		// if(map.find(csum[i])!=map.end())
		// {
		// 	return true;
		// }
		if(map.count(csum[i])!=0)
		{
			return true;
		}
		map.insert(make_pair(csum[i],i));
	}
	return false;
}

bool isSumKfound(int arr[],int n,int k)
{
	int csum[100]={0};
	unordered_map<int,int> map;
	csum[0]=arr[0];
	for(int i=1;i<n;i++)
	{
		csum[i]=csum[i-1]+arr[i];
	}

	// for(int i=0;i<n;i++)
	// {
	// 	cout<<csum[i]<<" ";
	// }

	for(int i=0;i<n;i++)
	{
		// if(map.find(csum[i]-k)!=map.end())
		// {
		// 	return true;
		// }
		if(map.count(csum[i]-k)!=0)
		{
			return true;
		}
		map.insert(make_pair(csum[i],i));
	}
	return false;
}

void printSubArrOfSum0(int arr[],int n)
{
	int csum[100]={0};
	int a=-1,b=-1,max=0;
	unordered_map<int,int> map;
	csum[0]=arr[0];
	for(int i=1;i<n;i++)
	{
		csum[i]=csum[i-1]+arr[i];
	}

	for(int i=0;i<n;i++)
	{
		unordered_map<int,int>::iterator it=map.find(csum[i]);
		if(it!=map.end())
		{
			int tempmax=i-it->second;
			if(tempmax>max)
			{
				a=it->second;
				b=i;
				max=tempmax;
			}
		}
		map.insert(make_pair(csum[i],i));
	}
	if(a!=-1)
	{
		for(int i=a+1;i<=b;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	else
	{
		cout<<"Doesnot exist"<<endl;
	}
}

void printSubArrOfSumK(int arr[],int n,int k)
{
	int csum[100]={0};
	int a=-1,b=-1,max=0;
	unordered_map<int,int> map;
	csum[0]=arr[0];
	for(int i=1;i<n;i++)
	{
		csum[i]=csum[i-1]+arr[i];
	}

	for(int i=0;i<n;i++)
	{
		unordered_map<int,int>::iterator it=map.find(csum[i]-k);
		if(it!=map.end())
		{
			int tempmax=i-it->second;
			if(tempmax>max)
			{
				a=it->second;
				b=i;
				max=tempmax;
			}
		}
		map.insert(make_pair(csum[i],i));
	}
	if(a!=-1)
	{
		for(int i=a+1;i<=b;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	else
	{
		cout<<"Doesnot exist"<<endl;
	}
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
	cout<<isSum0found(arr,n)<<endl;
	printSubArrOfSum0(arr,n);
	cout<<isSumKfound(arr,n,k)<<endl;
	printSubArrOfSumK(arr,n,k);
	return 0;
}