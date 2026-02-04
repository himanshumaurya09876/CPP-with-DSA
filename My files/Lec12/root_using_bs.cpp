//square root of n using binary search with precision

#include <iostream>

using namespace std;

double binarySearch(int last,int precision,int first=0)
{
	int num=last,mid;
	double ans;
	while(first<=last)
	{
		mid=(first+last)/2;//mid=first+(last-first)/2;
		if(num==mid*mid)
		{
			ans=mid;
			break;
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

	double prec=0.1;
	while(precision>0)
	{
		ans+=prec;
		if(ans*ans>num)
		{
			ans-=prec;
			precision--;
			prec/=10;
		}
	}
	return ans;
}

int main()
{
	int n,precision;
	cin>>n>>precision;
	cout<<binarySearch(n,precision);
	return 0;
}