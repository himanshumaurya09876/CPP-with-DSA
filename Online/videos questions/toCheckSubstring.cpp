//to check whether a string is substring of another
#include <iostream>
#include <string>

using namespace std;

bool isSubstr(string parent,string child)
{
	int pl=parent.length(),cl=child.length();
	char flag='n';
	int i=0,j=0;
	while(j<pl)
	{
		if(parent[j]==child[i])
		{
			i++;
			if(i==cl)
			{
				return true;
			}
			flag='y';
		}
		else if(flag=='y')
		{
			i=0;
			flag='n';
		}
		j++;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	string str1="Hello Mr Himanshu maurya";
	string str2="Mr";
	string str3="Himan";
	string str4="elloMr";
	string str5="ashish";
	cout<<isSubstr(str1,str2)<<endl;
	cout<<isSubstr(str1,str3)<<endl;
	cout<<isSubstr(str1,str4)<<endl;
	cout<<isSubstr(str1,str5)<<endl;
	return 0;
}