// MAXIMUM CIRCLES
// There are n circles arranged on x-y plane. All of them have their centers on x-axis. You have to remove some of them, such that no two circles are overlapping after that. Find the minimum number of circles that need to be removed.

// Input Format:
// First line contains a single integer, n, denoting the number of circles. Next line contains two integers, c and r each, denoting the circle with radius r and center, (c,0).

// Constraints:
// 1<=n<=10^5 |c|<=10^9 1<=r<=10^9

// Output Format
// Print a single integer denoting the answer.

// Sample Input
// 4
// 1 1
// 2 1
// 3 1
// 4 1
// Sample Output
// 2

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
	cout<<n-count<<endl;
	return 0;
}