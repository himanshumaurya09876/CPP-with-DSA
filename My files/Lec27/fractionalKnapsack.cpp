#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2)
{
	return ((float)p1.second/((float)p1.first))>((float)p2.second/((float)p2.first));
}

float fractionalKnapsack(pair<int,int> p[],int n,int cap)
{
	float total=0;
	int i=0;
	while(cap>0)
	{
		cap=cap-p[i].first;
		total+=p[i].second;
		i++;
	}
	i--;
	cap=cap+p[i].first;
	total=total-p[i].second;
	float cost=(float)p[i].second/((float)p[i].first)*cap;
	total+=cost;
	return total;
}

int main(int argc, char const *argv[])
{
	pair<int,int> p[100];
	int n,cap;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>p[i].first>>p[i].second;
	}
	cin>>cap;
	sort(p,p+n,compare);
	cout<<fractionalKnapsack(p,n,cap)<<endl;
	return 0;
}