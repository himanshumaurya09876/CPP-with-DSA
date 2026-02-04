//permutations some other approach

#include <iostream>
#include <string>

using namespace std;

/*void permute(string input,string output="")
{
	int l=input.length();
	if(l==0)
	{
		cout<<output<<endl;
		return;
	}
	for(int i=l-1;i>=0;i--)
	{
		permute(input.substr(0,i)+input.substr(i+1),output+input[i]);
	}
}*/

void permute(string input,string output="")
{
	int l=input.length();
	if(l==0)
	{
		cout<<output<<endl;
		return;
	}
	for(int i=0;i<l;i++)
	{
		permute(input.substr(0,i)+input.substr(i+1),output+input[i]);
	}
}

int main()
{
	string str;
	cin>>str;
	permute(str);
	return 0;
}
