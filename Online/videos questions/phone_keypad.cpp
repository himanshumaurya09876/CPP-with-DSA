//phone keypad

#include <iostream>
#include <string>

using namespace std;

string keypad[10]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void intToStr(int n,string ouptut="")
{
	if(n==0)
	{
		cout<<ouptut<<endl;
		return;
	}
	int d=n%10;
	n=n/10;
	int l=keypad[d].length();
	if(l==0)
	{
		intToStr(n,ouptut);
	}
	for(int i=0;i<l;i++)
	{
		intToStr(n,ouptut+keypad[d][i]);
	}
}

int main()
{
	int n,m=0;
	cin>>n;
	while(n!=0)
	{
		m=m*10+n%10;
		n=n/10;
	}
	intToStr(m);
	return 0;
}