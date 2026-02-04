//Greatest common divisor GCD / Highest common factor HCF
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

int main(int argc, char const *argv[])
{
	int a,b;
	cin>>a>>b;
	cout<<FindGCD(a,b)<<endl;
	cout<<FindGCD(b,a)<<endl;
	return 0;
}