#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class queData
{
public:
	int ver;
	int dist;
};

int minMoves(int moves[],int n)
{
	queue<queData> q;
	unordered_map<int,bool> isVisit;
	queData curr={0,0};
	q.push(curr);
	while(!q.empty())
	{
		curr=q.front();
		q.pop();
		if(curr.ver==n-1)
		{
			break;
		}
		for(int i=curr.ver+1;i<=curr.ver+6 && i<n;i++)
		{
			if(!isVisit[i])
			{
				queData qd;
				qd.dist=curr.dist+1;
				if(moves[i]!=-1)
				{
					qd.ver=moves[i];
				}
				else
				{
					qd.ver=i;
				}
				q.push(qd);
				isVisit[i]=true;
				// cout<<qd.ver<<" "<<qd.dist<<endl;
			}
		}
	}
	return curr.dist;
}

int main(int argc, char const *argv[])
{
	int n;
	//cin>>n;
	n=30;
	int *moves=new int[n];
	for(int i=0;i<n;i++)
	{
		moves[i]=-1;
	}

	// Ladders
	moves[2] = 15;
	moves[4] = 7;
	moves[10] = 20;
	moves[19] = 21;

	// Snakes
	// moves[29] = 0;//look at this
	moves[20] = 8;
	moves[16] = 3;
	moves[18] = 6;

	cout<<minMoves(moves,n)<<endl;

	return 0;
}