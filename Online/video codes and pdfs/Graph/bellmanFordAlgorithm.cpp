#include <iostream>
#include <set>
#include <unordered_map>
#include <list>
#define inf 1e9
using namespace std;

template<typename T>
class Graph
{
private:
	unordered_map<T,list<pair<T,int> > > adjList;
	int v;
public:
	Graph(int V)
	{
		v=V;
	}

	void addEdge(T u,T v,int wt,bool biDir=true)
	{
		adjList[u].push_back(make_pair(v,wt));
		if(biDir)
		{
			adjList[v].push_back(make_pair(u,wt));
		}
	}

	void printGraph()
	{
		for(auto i:adjList)
		{
			cout<<i.first<<" -> ";
			for(auto it:i.second)
			{
				cout<<"("<<it.first<<","<<it.second<<"), ";
			}
			cout<<endl;
		}
		cout<<endl;
	}

	void bellmanFordAlgo(T src)
	{
		unordered_map<T,int> dist;
		//we have to do a lot to make dist of each vertex as inf using adjacency list
		//so we should use adjacency matrix or edge list
		for(auto it:adjList)
		{
			dist[it.first]=inf;
			for(auto i:it.second)
			{
				dist[i.first]=inf;
			}
		}
		dist[src]=0;

		// relaxation code
		for(int i=1;i<v;i++)
		{
			for(auto it:adjList)
			{
				for(auto i:it.second)
				{
					// relaxation check
					if(dist[it.first]!=inf and dist[it.first]+i.second < dist[i.first])
					{
						dist[i.first]=dist[it.first]+i.second;
					}
				}
			}
		}

		// check for negative weight cycle
		for(auto it:adjList)
		{
			for(auto i:it.second)
			{
				// relaxation check
				if(dist[it.first]!=inf and dist[it.first]+i.second < dist[i.first])
				{
					cout<<"Negative cycle is present"<<endl;
					return;
				}
			}
		}

		for(auto it:dist)
		{
			cout<<"Distance of "<<it.first<<" from "<<src<<" is "<<it.second<<endl;
		}
		cout<<endl;
	}
};

int main(int argc, char const *argv[])
{
	Graph<char> g1(5);
	g1.addEdge('A','B',-1,false);
	g1.addEdge('A','C',4,false); 
	g1.addEdge('B','C',3,false);
	g1.addEdge('B','D',2,false);
	g1.addEdge('B','E',2,false);
	g1.addEdge('E','D',-3,false);
	g1.addEdge('D','B',1,false);
	g1.addEdge('D','C',5,false);
	
	g1.printGraph();
	g1.bellmanFordAlgo('A');
	return 0;
}