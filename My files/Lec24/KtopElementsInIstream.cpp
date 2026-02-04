#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
	priority_queue<int,vector<int>,greater<int> > pq;
	int in,k,m;
	cin>>k>>in;
	m=k;

	// one more method of taking input stream
	// while(scanf("%d",&in)!=EOF)
	// {
	// 	//.....code...
	// }

	while(in!='x'-'a')
	{
		if(in!=-1)
		{
			if(m>0)
			{
				pq.push(in);
				m--;
			}
			else
			{
				if(in>pq.top())
				{
					pq.pop();
					pq.push(in);
				}
			}
		}
		else
		{
			// priority_queue<int,vector<int>,greater<int> > temp;
			// int n=k;
			// while(n>0)
			// {
			// 	cout<<pq.top()<<" ";
			// 	temp.push(pq.top());
			// 	pq.pop();
			// 	n--;
			// }
			// pq=temp;

			priority_queue<int,vector<int>,greater<int> > temp=pq;
			while(!temp.empty())
			{
				cout<<temp.top()<<" ";
				temp.pop(); 
			}
			cout<<endl;
		}
		cin>>in;
	}
	return 0;
}

//input
//3
//5 4 9 8 -1 7 6 -1 100 -1 800 -1 2 -1 x