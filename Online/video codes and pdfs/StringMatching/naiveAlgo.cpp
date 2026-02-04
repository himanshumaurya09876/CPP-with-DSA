#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	string str,pattern;
	cin>>str>>pattern;
	int count=0;
	int ls=str.length();
	int lp=pattern.length();


	// for(int i=0;str[i]!='\0';i++)
	// {
	// 	if(pattern==str.substr(i,lp))
	// 	{
	// 		cout<<"Pattern found at "<<i<<endl;
	// 		count++;
	// 	}
	// }

	for(int i=0;i<ls-lp;i++)
	{
		int j;
		for(j=0;j<lp;j++)
		{
			if(str[j+i]!=pattern[j])
			{
				break;
			}
		}
		if(j==lp)
		{
			cout<<"Pattern found at "<<i<<endl;
			count++;
		}
	}
	cout<<count;
	return 0;
}