// BEAUintIFUL VERintICES
// You are given a graph with N vertices and M edges. Master parent is the vertex which has no parent but may have 0 or more children. In any connected component of the graph, vertex with the lowest value in that component serves as the master parent. A vertex is called beautiful if it has more children than its parent. Count the number of beautiful vertices in the given graph. inthe graph has no cycles or self loops.

// Input Format:
// First line consists of two space separated integers denoting N and M and the following M lines consist of two space separated integers X and Y denoting there is an edge between vertices X and Y.

// Constraints:
// 1 <= N <= 100000 0 <= M <= N-1 1 <= x,y <= N

// Output Format
// Print the number of beautiful vertices in the graph.

// Sample Input
// 4 3
// 1 2
// 2 3
// 2 4
// Sample Output
// 1

#include <iostream>
#include <list>
#include <climits>
using namespace std;

int ans;

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

	// misunderstood
	// int dfsHelper1(int src,bool isVisited[],int parent=0)
	// {
	// 	isVisited[src]=true;
	// 	int child=0;
	// 	for(auto it:adjList[src])
	// 	{
	// 		if(!isVisited[it])
	// 		{
	// 			child+=dfsHelper1(it,isVisited,parent+1);
	// 		}
	// 	}

	// 	if(child>parent)
	// 	{
	// 		cout<<src<<" ";
	// 		ans++;
	// 	}

	// 	return child+1;
	// }

	void dfsHelper(int src,bool isVisited[],int parentsChild=INT_MAX)
	{
		isVisited[src]=true;
		int myChild=0;
		for(auto it:adjList[src])
		{
			if(!isVisited[it])
			{
				myChild++;
			}
		}

		if(myChild>parentsChild)
		{
			// cout<<src<<" ";
			ans++;
		}

		for(auto it:adjList[src])
		{
			if(!isVisited[it])
			{
				dfsHelper(it,isVisited,myChild);
			}
		}
	}

	void dfsRec()
	{
		bool *isVisited=new bool[v];
		for(int i=0;i<v;i++)
		{
			isVisited[i]=false;
		}
		for(int i=0;i<v;i++)
		{
			if(!isVisited[i])
			{
				dfsHelper(i,isVisited);
			}
		}
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
		x--;
		y--;
		g.addEdge(x,y);
	}
	ans=0;
	g.dfsRec();
	cout<<endl<<ans<<endl;
	return 0;
}