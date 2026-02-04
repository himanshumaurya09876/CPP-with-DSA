// TOP K MOST FREQUENT NUMBER IN A STREAM
// Given an array of n numbers. Your task is to read numbers from the array and keep at-most K numbers at the top (according to their decreasing frequency) every time a new number is read. We basically need to print top k numbers sorted by frequency when input stream has included k distinct elements, else need to print all distinct elements sorted by frequency. If frequency of two numbers are same then print them in increasing order.

// Input Format:
// First line contains integer t as number of test cases. Each test case contains following input. First line contains integer n which represents the length of the array and next line contains n space separated integers.

// Constraints:
// 1 < t < 100 1< n < 100000

// Output Format
// Print top k running stream.

// Sample Input
// 1
// 5 2
// 5 1 3 5 2
// Sample Output
// 5 1 5 1 3 5 1 5 1

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int,int> mp;

class compare
{
public:
	bool operator()(int a,int b)
	{
		if(mp[a]==mp[b])
		{
			return a>b;
		}
		return mp[a]<mp[b];
	}
};

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t>0)
	{
		int n,k;
		mp.clear();
		cin>>n>>k;
		for(int i=0;i<n;i++)
		{
			int d;
			cin>>d;
			if(mp.count(d))
			{
				mp[d]++;
			}
			else
			{
				mp[d]=1;
			}

			priority_queue<int,vector<int>,compare> pq;
			// cout<<endl<<"************************************************"<<endl;
			for(auto it:mp)
			{
				// cout<<it.first<<" "<<it.second<<endl;
				pq.push(it.first);
			}
			// cout<<endl<<"************************************************"<<endl;

			if(mp.size()<=k)
			{
				while(!pq.empty())
				{
					cout<<pq.top()<<" ";
					pq.pop();
				}
			}
			else
			{
				int j=k;
				while(!pq.empty() && j>0)
				{
					cout<<pq.top()<<" ";
					pq.pop();
					j--;
				}
			}
		}
		cout<<endl;
		t--;
	}
	return 0;
}