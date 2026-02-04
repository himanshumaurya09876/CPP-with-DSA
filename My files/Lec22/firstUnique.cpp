#include <iostream>
#include <queue>
using namespace std;

char firstUnique(string str)
{
	int freq[26]={0},i=0;
	queue<char> q;
	while(str[i]!='\0')
	{
		freq[str[i]-'a']++;
		if(freq[str[i]-'a']>1)
		{
			while(!q.empty() && freq[q.front()-'a']>1)
			{
				q.pop();
			}
		}
		else
		{
			q.push(str[i]);
		}
		i++;
	}
	return q.front();
}

int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	cout<<firstUnique(str)<<endl;
	return 0;
}