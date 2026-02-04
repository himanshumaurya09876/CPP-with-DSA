// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <string.h>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int key;
string rev;
string str;

bool compare(vector<string> v1,vector<string> v2)
{
	// cout<<"Comparing...."<<endl;
	// for(auto it:v1)
	// {
	// 	cout<<it<<" ";
	// }
	// cout<<endl;
	// for(auto it:v2)
	// {
	// 	cout<<it<<" ";
	// }
	// cout<<endl;

	// cout<<v1[key-1]<<" "<<v2[key-1]<<endl;

	// cout<<key<<" "<<rev<<" "<<str<<endl;

	if(str=="numeric")
	{
		ll num1=stoi(v1[key-1]);
		ll num2=stoi(v2[key-1]);
		// cout<<num1<<" "<<num2<<endl;
		// return num1>num2 && rev;
		if(rev=="true")
		{
			return num1>num2;
		}
		else
		{
			return num1<num2;
		}
	}
	else
	{
		if(rev=="true")
		{
			return v1[key-1]>v2[key-1];
		}
		else
		{
			return v1[key-1]<v2[key-1];
		}
	}
}

int main()
{
	int n;
	cin>>n;
	// char *ch=new char[50];

	// cin.get();
	// cin.getline(ch,50);

	// int i=0;
	// cin.get();
	// cin.get(ch[i]);
	// while(ch[i]!='\n')
	// {
	// 	i++;
	// 	cin.get(ch[i]);
	// }
	// cout<<ch;

	// int m=0;//this piece of code not needed since i am using vector
	// for(int j=0;ch[j]!='\0' && j<50;j++)
	// {
	// 	if(ch[j]==' ')
	// 	{
	// 		m++;
	// 	}
	// }
	// m++;

	vector<vector<string> > v;
	cin.get();
	for(int i=0;i<n;i++)
	{
		char *ch=new char[50];
		cin.getline(ch,50);
		vector<string> temp;
		stringstream check(ch);
		string part;
		while(getline(check,part,' '))
		{
			temp.push_back(part);
		}
		v.push_back(temp);
	}

	cin>>key>>rev>>str;
	// for(auto it:v)
	// {
	// 	for(auto itr:it)
	// 	{
	// 		cout<<itr<<" ";
	// 	}
	// 	cout<<endl;
	// }
	sort(v.begin(),v.end(),compare);
	for(auto it:v)
	{
		for(auto itr:it)
		{
			cout<<itr<<" ";
		}
		cout<<endl;
	}
	return 0;
}