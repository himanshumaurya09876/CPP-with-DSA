#include <bits/stdc++.h>
using namespace std;

char firstUnique()
{
	int freq[26]={0};
	queue<char> q;
	char ch;
	cin>>ch;
	while(ch!='*')
	{
		freq[ch-'a']++;
		if(freq[ch-'a']>1)
		{
			while(!q.empty() && freq[q.front()-'a']>1)
			{
				q.pop();
			}
		}
		else
		{
			q.push(ch);
		}
		cin>>ch;
	}
	return q.front();
}

int main(int argc, char const *argv[])
{
	cout<<firstUnique()<<endl;
	return 0;
}