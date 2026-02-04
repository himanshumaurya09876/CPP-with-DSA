#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
	// int arr1[]={45,12,-9,5,02,36,74,85};
	// int arr2[]={14,25,69,78,36,2,5};
	// int arr3[]={-4,52,-56,9989,1254,56};
	// int arr4[]={10,25,36,8000,2455,022,6320,55500,22502};
	// int k=4;


	vector<vector<int> > arr;
	int k;
	cin>>k;
	for(int i=0;i<k;i++)
	{
		vector<int> v;
		int d;
		cin>>d;
		while(d!=-1)
		{
			v.push_back(d);
			cin>>d;
		}
		arr.push_back(v);
	}
	vector<int> finalArr;
	priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > pq;
	for(int i=0;i<k;i++)
	{
		pq.push(make_pair(arr[i][0],make_pair(i,0)));
	}
	while(pq.top().first!=INT_MAX)
	{
		pair<int,pair<int,int> > p;
		p=pq.top();
		finalArr.push_back(p.first);
		pq.pop();
		if(arr[p.second.first].size()-1<=p.second.second)
		{
			pq.push(make_pair(INT_MAX,make_pair(p.second.first,p.second.second+1)));
		}
		else
		{
			pq.push(make_pair(arr[p.second.first][p.second.second+1],make_pair(p.second.first,p.second.second+1)));
		}
	}

	for(int i=0;i<finalArr.size();i++)
	{
		cout<<finalArr[i]<<" ";
	}
	return 0;
}