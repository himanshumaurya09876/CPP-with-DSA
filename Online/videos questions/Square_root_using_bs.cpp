//square root using binary search
#include <iostream>
using namespace std;
float findSquareRoot(int n,int p)
{
	int low=0,high=n;
	float ans=0;
	while(low<=high)
	{
		int mid=low+(high-low)/2;
		if(mid*mid==n)
		{
			ans=mid;
			break;
		}
		else if(mid*mid<n)
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	float increment=0.1;
	while(p>0)
	{
		ans+=increment;
		if(ans*ans>n)
		{
			ans-=increment;
			increment/=10;
			p--;
		}
	}
	return ans;
}
 
int main() {
	int n,p;
	cin>>n>>p;
	cout<<findSquareRoot(n,p)<<endl;
	cin>>n>>p;
	cout<<findSquareRoot(n,p)<<endl;
	cin>>n>>p;
	cout<<findSquareRoot(n,p)<<endl;
	cin>>n>>p;
	cout<<findSquareRoot(n,p)<<endl;
	return 0;
}