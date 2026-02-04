//least common multiple LCM
#include <iostream>
using namespace std;

int FindGCD(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	return FindGCD(b,a%b);
}

int FindLCM(int a,int b)
{
	return (a*b)/FindGCD(a,b);
}

int main(int argc, char const *argv[])
{
	int a,b;
	cin>>a>>b;
	cout<<FindLCM(a,b)<<endl;
	cout<<FindLCM(b,a)<<endl;
	return 0;
}