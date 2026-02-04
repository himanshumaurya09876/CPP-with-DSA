// max no. of non overlapping circles
// maximum no. of tasks in busy man

#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2)
{
	return p1.second<p2.second;
}

int maxTasks(pair<int,int> p[],int n)
{
	int count=0;
	int i=0;
	int prev=0;
	while(i<n)
	{
		if(prev<=p[i].first)
		{
			count++;
			prev=p[i].second;
		}
		i++;
	}
	return count;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t>0)
	{
		int n;
		pair<int,int> p[100000];
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		sort(p,p+n,compare);
		cout<<maxTasks(p,n)<<endl;
		t--;
	}
	return 0;
}