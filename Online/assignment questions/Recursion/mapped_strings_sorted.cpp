//mapped strings sorted

#include<iostream>
#include<string>
using namespace std;

void intToWord(int n,string output="")
{
	if(n==0)
	{
		cout<<output<<endl;
		return;
	}
	char ch1=char(n%10+'A'-1);
	intToWord(n/10,output+ch1);
	int m1=n%10,m2=(n/10)%10;
	int n1=m1*10+m2;
	if(n1<=26 && n1>9)
	{
		char ch2=char(n1+'A'-1);
		intToWord(n/100,output+ch2);
	}
}

int main() {
	int n,m=0;
	cin>>n;
	while(n>0)
	{
		m=m*10+n%10;
		n/=10;
	}
	intToWord(m);
	return 0;
}
