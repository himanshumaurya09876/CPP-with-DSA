//all permutations of a string using swap and backtracking

#include <iostream>
#include <string>

using namespace std;

void permute(string input,int i)
{
	//base case
	if(i==0)
	{
		cout<<input<<", ";
	}
	//recursive case
	for(int j=i;j>=0;j--)
	{
		swap(input[i],input[j]);
		permute(input,i-1);
		//backtracking
		swap(input[i],input[j]);
	}
}

int main()
{
	string str;
	cin>>str;
	int l=str.length();
	permute(str,l-1);
	return 0;
}