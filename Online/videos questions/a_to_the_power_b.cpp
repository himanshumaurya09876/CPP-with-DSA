#include <iostream>

using namespace std;

long long int normalfun(int a,int b)//its time complexity is O(b) or O(n)
{
	if(b==0)
	{
		return 1;
	}
	return a*normalfun(a,b-1);
}

long long int fastfun(int a,int b)
{
	if(b==0)
		return 1;
	int ans=fastfun(a,b/2);
	ans*=ans;
	if(b&1)
	{
		ans*=a;
	}
	return ans;
}

int main()
{
	int a,b;
	cout<<"Enter a and b for a^b: "<<endl;
	cin>>a>>b;
	cout<<"Using normal recursive function: "<<normalfun(a,b)<<endl;
	cout<<"Using fast recursive function: "<<fastfun(a,b)<<endl;
}