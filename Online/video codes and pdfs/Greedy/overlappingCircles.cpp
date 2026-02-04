#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> a,pair<int,int> b)
{
	return a.second<b.second;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	pair<int,int> *c=new pair<int,int>[n];
	for(int i=0;i<n;i++)
	{
		cin>>c[i].first>>c[i].second;
	}
	pair<int,int> *p=new pair<int,int>[n];
	for(int i=0;i<n;i++)
	{
		p[i].first=c[i].first-c[i].second;
		p[i].second=c[i].first+c[i].second;
	}
	sort(p,p+n,compare);

	int count=1;
	int prev=0;
	cout<<p[0].first<<"<-->"<<p[0].second<<endl;
	for(int i=1;i<n;i++)
	{
		if(p[i].first>=p[prev].second)
		{
			count++;
			prev=i;
			cout<<p[i].first<<"<-->"<<p[i].second<<endl;
		}
	}
	cout<<count<<endl;
	return 0;
}