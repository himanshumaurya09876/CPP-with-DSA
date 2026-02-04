#include <iostream>
#include<string>

using namespace std;

int strToInt(string str,int num=0)
{
	if(str.length()==0)
	{
		return num;
	}
	num=num*10+(str[0]-'0');
	return strToInt(str.substr(1),num);
}

int main()
{
	string str;
	cout<<"Enter a string: ";
	cin>>str;
	cout<<strToInt(str);
}