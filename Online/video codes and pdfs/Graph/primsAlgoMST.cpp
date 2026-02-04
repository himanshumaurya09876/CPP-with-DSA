#include <iostream>
#include <list>
#define inf 1e9
using namespace std;

class Graph
{
private:
	int V;
	list<pair<int,int> > *adjList;
public:
	Graph(int v)
	{
		V=v;
		adjList=new list<pair<int,int> >[V];
	}

	void addEdge(int u,int v,int wt,bool biDir=true)
	{
		adjList[u].push_back(make_pair(v,wt));
		if(biDir)
		{
			adjList[v].push_back(make_pair(u,wt));
		}
	}

	int findMin(int weight[],bool visited[])
	{
		int minVertex=-1;
		for(int i=0;i<V;i++)
		{
			if(!visited[i] and (minVertex==-1 or weight[minVertex]>weight[i]))
			{
				minVertex=i;
			}
		}
		return minVertex;
	}

	void primsMST()
	{
		bool *visited=new bool[V];
		int *parent=new int[V];
		int *weight=new int[V];
		for(int i=0;i<V;i++)
		{
			visited[i]=false;
			weight[i]=inf;
		}
		weight[0]=0;
		parent[0]=-1;
		for(int i=0;i<V;i++)
		{
			int minVertex=findMin(weight,visited);
			visited[minVertex]=true;
			for(auto it:adjList[minVertex])
			{
				if(!visited[it.first])
				{
					if(weight[it.first]>it.second)
					{
						weight[it.first]=it.second;
						parent[it.first]=minVertex;
					}
				}
			}
		}

		for(int i=1;i<V;i++)
		{
			cout<<i<<" <--> "<<parent[i]<<" with weight "<<weight[i]<<endl;
		}
	}
};

int main(int argc, char const *argv[])
{
	int v,e;
	cin>>v>>e;
	Graph g(v);
	for(int i=0;i<e;i++)
	{
		int u,v,wt;
		cin>>u>>v>>wt;
		g.addEdge(u,v,wt);
	}

	g.primsMST();
	return 0;
}