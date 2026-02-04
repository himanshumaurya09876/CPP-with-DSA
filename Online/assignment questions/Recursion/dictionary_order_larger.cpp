//all permutations which are larger than the given string in dictionary order
#include<iostream>
#include<string>
using namespace std;

void dictionary(string str,string input,string output="",bool flag = false)
{
	int l=input.length();
	if(l==0)
	{
		if(output!=str)
			cout<<output<<endl;
		return;
	}
	for(int j=0;j<l;j++)
	{
		char ch=input[j];
		//cout<<"ch "<<ch<<endl;
		if(flag || ch>=input[0])
		{
			dictionary(str,input.substr(0,j)+input.substr(j+1),output+ch, flag);
		}
		// else
		// {
		// 	if(ch>= input[0])
		// 	{
		// 		//cout<<"input "<<input.substr(0,j)+input.substr(j+1)<<endl;
		// 		dictionary(str,input.substr(0,j)+input.substr(j+1),output+ch, ch>= input[0] or flag);
		// 	}
		// }
		//cout<<endl;
	}
}

int main() {
	string str;
	cin>>str;
	dictionary(str,str);
	return 0;
}

//making all permutations and then comparing with original
// #include<iostream>
// #include<string>
// using namespace std;

// void dictionary(string str,string input,string output="")
// {
// 	int l=input.length();
// 	if(l==0)
// 	{
// 		if(output>str)
// 			cout<<output<<endl;
// 		return;
// 	}
// 	for(int j=0;j<l;j++)
// 	{
// 		char ch=input[j];
// 		dictionary(str,input.substr(0,j)+input.substr(j+1),output+ch);
// 	}
// }

// int main() {
// 	string str;
// 	cin>>str;
// 	dictionary(str,str);
// 	return 0;
// }