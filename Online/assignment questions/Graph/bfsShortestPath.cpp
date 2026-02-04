// BFS - SHORintESint PAintH
// Consider an undirected graph consisting of 'n' nodes where each node is labeled from 1 to n and the edge between any two nodes is always of length 6 . We define node 's' to be the starting position for a BFS.

// Given 'q' queries in the form of a graph and some starting node, 's' , perform each query by calculating the shortest distance from starting node 's' to all the other nodes in the graph. inthen print a single line of n-1 space-separated integers listing node s's shortest distance to each of the n-1 other nodes (ordered sequentially by node number); if 's' is disconnected from a node, print -1 as the distance to that node.

// Input Format:
// inthe first line contains an integer,q , denoting the number of queries. inthe subsequent lines describe each query in the following format:

// Each line contains N and M, the number of nodes and edges respectively.

// inthe next m lines contains u and v means that there is edge between u and v .

// inthe last line contains 's', the starting node.

// Constraints:
// 1 <= q <= 10 2 <= n <= 1000 1 <= m <= (n*(n-1))/2 1 <= u,s,v <= n

// Output Format
// You have to print n-1 integer denoting the shortest distance from s to all other nodes excluding s itself.

// Sample Input
// 2
// 4 2
// 1 2
// 1 3
// 1
// 3 1
// 2 3
// 2
// Sample Output
// 6 6 -1
// -1 6

#include <iostream>
#include <queue>
#include <list>
using namespace std;

class Graph
{
	list<int> *adjList;
	int v,e;
public:
	Graph(int v,int e)
	{
		this->v=v;
		this->e=e;
		adjList=new list<int>[v];
	}

	void addEdge(int u,int v,bool biDir=true)
	{
		adjList[u].push_back(v);
		if(biDir)
		{
			adjList[v].push_back(u);
		}
	}

	void sssp(int src)
	{
		queue<int> q;
		bool *isVisited=new bool[v];
		int *dist=new int[v];
		for(int i=0;i<v;i++)
		{
			isVisited[i]=false;
			dist[i]=-1;
		}
		isVisited[src]=true;
		dist[src]=0;
		q.push(src);
		while(!q.empty())
		{
			int entry=q.front();
			q.pop();
			for(auto it:adjList[entry])
			{
				if(!isVisited[it])
				{
					q.push(it);
					isVisited[it]=true;
					dist[it]=dist[entry]+6;
				}
			}
		}

		for(int i=0;i<v;i++)
		{
			if(i!=src)
			{
				cout<<dist[i]<<" ";
			}
		}
		cout<<endl;
	}
};

int main(int argc, char const *argv[])
{
	int q;
	cin>>q;
	while(q>0)
	{
		int n,m;
		cin>>n>>m;
		Graph g(n,m);
		for(int i=0;i<m;i++)
		{
			int u,v;
			cin>>u>>v;
			u--;
			v--;
			g.addEdge(u,v);
		}
		int s;
		cin>>s;
		g.sssp(--s);
		q--;
	}
	return 0;
}