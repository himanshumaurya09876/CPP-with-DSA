#include<bits/stdc++.h>
using namespace std;

int calDigit(string str,int d)
{
	int i=0,count=0;
	while(str[i]!='\0')
	{
		if(str[i]-'0'==d)
		{
			count++;
		}
		i++;
	}
	return count;
}

int main() {
	string str;
	int d;
	cin>>str>>d;
	cout<<calDigit(str,d)<<endl;
	return 0;
}