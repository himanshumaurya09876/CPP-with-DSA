// print 1024 as one zero two four
// (a)for 1024 as int
// (b)1024 as string

#include <iostream>
#include <string>

using namespace std;

string word[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

string intToWords(int n,string output="")
{
	if(n==0)
	{
		return output;
	}
	output+=intToWords(n/10,output);
	output+=word[n%10];
	output+=" ";
	return output;
}

string stringToWords(string input,string output="")
{
	if(input.length()==0)
	{
		return output;
	}
	output+=word[(input[0]-'0')];
	output+=" ";
	return stringToWords(input.substr(1),output);
}

int main()
{
	int n;
	string num;
	cout<<"Enter a number: ";
	cin>>n;
	cout<<intToWords(n)<<endl;
	cout<<"Enter a string: ";
	cin>>num;
	cout<<stringToWords(num)<<endl;
	return 0;
}