#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;

void print(priority_queue<int,vector<int>,greater<int> > pq)
{
	while(!pq.empty())
	{
		cout<<pq.top()<<", ";
		pq.pop();
	}

	cout<<endl;
}

int main(int argc, char const *argv[])
{
	// // input stream -> running stream
	// int n;
	// while(scanf("%d",&n)!=EOF)
	// {
	// 	cout<<n<<" ";
	// }

	priority_queue<int,vector<int>,greater<int> > pq;
	int k;
	cin>>k;

	int n,cs=0;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==-1)
		{
			print(pq);
		}
		else if(cs<k)
		{
			pq.push(n);
			cs++;
		}
		else
		{
			if(pq.top()<n)
			{
				pq.pop();
				pq.push(n);
			}
		}
	}





	// int n,k;
	// priority_queue<int,vector<int>,greater<int> > pq;
	// cin>>k>>n;
	// int i=1;
	// while(n!=-1)
	// {
	// 	if(i<=k)
	// 	{
	// 		pq.push(n);
	// 		i++;
	// 	}
	// 	else
	// 	{
	// 		if(n>pq.top())
	// 		{
	// 			pq.pop();
	// 			pq.push(n);
	// 		}
	// 	}
	// 	cin>>n;
	// }
	// while(!pq.empty())
	// {
	// 	cout<<pq.top()<<" ";
	// 	pq.pop();
	// }
	return 0;
}