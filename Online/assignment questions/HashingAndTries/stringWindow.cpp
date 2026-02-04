// STRING WINDOW
// Ravi has been given two strings named string1 and string 2. He is supposed to find the minimum length substring of the string1 which contains all the characters of string2. Help him to find the substring

// Input Format:
// The first line of the input contains string1. String1 can be a string containing spaces also. The second line of the input contains string2. String2 can be a string containing spaces also.

// Constraints:
// Length of both the strings can be at max 10^4

// Output Format
// Output the substring in a single line. If no such substring exist then output "No string" without quotes

// Sample Input
// qwerty asdfgh qazxsw
// qas
// Sample Output
// qazxs

#include <iostream>
#include <string>
#include <queue>
#include <climits>
#include <unordered_map>
using namespace std;

// string minStrWindow1(string str1,string str2)
// {
// 	queue<pair<char,int> > q;
// 	unordered_map<char,int> mp2;
// 	for(int i=0;str2[i]!='\0';i++)
// 	{
// 		if(mp2.count(str2[i]))
// 		{
// 			mp2[str2[i]]++;
// 		}
// 		else
// 		{
// 			mp2[str2[i]]=1;
// 		}
// 	}

// 	int minLen=INT_MAX;
// 	int a=-1;
// 	for(int i=0;str1[i]!='\0';i++)
// 	{
// 		if(mp2.count(str1[i]))
// 		{
// 			mp2[str1[i]]--;
// 			q.push(make_pair(str1[i],i));
// 			if(mp2[str1[i]]==0)
// 			{
// 				mp2.erase(str1[i]);
// 			}

// 			if(mp2.empty())
// 			{
// 				pair<char,int> p=q.front();
// 				q.pop();
// 				if(mp2.count(p.first))
// 				{
// 					mp2[p.first]++;
// 				}
// 				else
// 				{
// 					mp2[p.first]=1;
// 				}
// 				if(i-p.second+1<minLen)
// 				{
// 					a=p.second;
// 					minLen=i-p.second+1;
// 				}
// 			}
// 		}
// 	}
// 	if(a==-1)
// 	{
// 		return "No string";
// 	}
// 	return str1.substr(a,minLen);
// }

string minStrWindow(string str1,string str2)
{
	unordered_map<char,int> mp2;
	for(int i=0;str2[i]!='\0';i++)
	{
		if(mp2.count(str2[i]))
		{
			mp2[str2[i]]++;
		}
		else
		{
			mp2[str2[i]]=1;
		}
	}

	unordered_map<char,int> temp;
	int jump=-1;
	int minLen=INT_MAX;
	int a=-1;
	for(int i=0;str1[i]!='\0';i+=jump)
	{
		jump=1;
		if(mp2.count(str1[i]))
		{
			temp=mp2;
			temp[str1[i]]--;
			if(temp[str1[i]]==0)
			{
				temp.erase(str1[i]);
			}
			int j=i+1;
			bool flag=false;
			while(!temp.empty() && str1[j]!='\0')
			{
				if(temp.count(str1[j]))
				{
					if(!flag)
					{
						jump=j-i;
						flag=true;
					}
					temp[str1[j]]--;
					if(temp[str1[j]]==0)
					{
						temp.erase(str1[j]);
					}
				}
				j++;
			}
			if(temp.empty() and j-i<minLen)
			{
				a=i;
				minLen=j-i;
			}
		}
	}
	if(a==-1)
	{
		return "No string";
	}
	return str1.substr(a,minLen);
}

int main(int argc, char const *argv[])
{
	string str1,str2;
	getline(cin,str1);
	getline(cin,str2);
	cout<<minStrWindow(str1,str2)<<endl;
	return 0;
}