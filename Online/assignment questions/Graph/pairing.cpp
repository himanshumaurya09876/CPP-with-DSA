// PAIRING
// There are N cities numbered from 0 to N-1. You have to choose 2 cities such that there is no path from first city to second city .
// You are given information in the form of M pairs (X,Y) i.e there is an undirected road between city X and city Y.
// Find out the number of ways in which cities can be chosen.

// Input Format:
// The first line contains two integers, N and M separated by a single space. M lines follow. Each line contains integers separated by a single space X and Y denoting road between X and Y.

// Constraints:
// 1 <= N <= 100000 1 <= M <= 100000 0 <= X,Y <= N-1

// Output Format
// An integer that denotes the number of permissible ways to choose a pair of cities.

// Sample Input
// 5 3
// 0 1
// 2 3
// 0 4
// Sample Output
// 6


#include <iostream>
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

	int dfsHelper(int src,bool isVisited[])
	{
		isVisited[src]=true;
		int myChild=0;

		for(auto it:adjList[src])
		{
			if(!isVisited[it])
			{
				myChild+=dfsHelper(it,isVisited);
			}
		}

		return myChild+1;
	}

	int dfsRec()
	{
		bool *isVisited=new bool[v];
		for(int i=0;i<v;i++)
		{
			isVisited[i]=false;
		}
		int totalWays=v*(v-1)/2;
		for(int i=0;i<v;i++)
		{
			if(!isVisited[i])
			{
				int count=dfsHelper(i,isVisited);
				totalWays-=count*(count-1)/2;
			}
		}

		return totalWays;
	}
};

int main(int argc, char const *argv[])
{
	int n,m;
	cin>>n>>m;
	Graph g(n,m);
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		g.addEdge(x,y);
	}
	cout<<g.dfsRec()<<endl;
	return 0;
}