#include <iostream>
#include <vector>
using namespace std;

int minCost(vector<pair<int,int> > vec)
{
	int n=vec.size();
	int minc=0;
	int prevcost=INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(vec[i].first<prevcost)
		{
			minc+=vec[i].first*vec[i].second;
			prevcost=vec[i].first;
		}
		else
		{
			minc+=prevcost*vec[i].second;
		}
	}
	return minc;
}

int main()
{
	int t;
	cin>>t;
	while(t>0)
	{
		int n;
		vector<pair<int,int> > vec;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int c,l;
			cin>>c>>l;
			vec.push_back(make_pair(c,l));
		}
		cout<<minCost(vec)<<endl;
		t--;
	}
}