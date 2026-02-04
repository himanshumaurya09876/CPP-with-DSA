//mapped strings

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
	intToWord(n/10,ch1+output);
	int n1=n%100;
	if(n1<=26 && n1>9)
	{
		char ch2=char(n1+'A'-1);
		intToWord(n/100,ch2+output);
	}
}

int main() {
	int n;
	cin>>n;
	intToWord(n);
	return 0;
}
