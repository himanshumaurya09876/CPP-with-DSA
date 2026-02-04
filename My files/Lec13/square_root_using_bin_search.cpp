//square root of n using binary search

#include <iostream>

using namespace std;

int binarySearch(int last,int first=0)
{
	int num=last,ans;
	while(first<=last)
	{
		int mid=(first+last)/2;
		if(num==mid*mid)
		{
			ans=mid;
			return mid;
		}
		else if(mid*mid>num)
		{
			last=mid-1;
		}
		else
		{
			ans=mid;
			first=mid+1;
		}
	}
	return ans;
}

int main()
{
	int n;
	cin>>n;
	cout<<binarySearch(n);
	return 0;
}