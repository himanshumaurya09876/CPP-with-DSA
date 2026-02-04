#include <iostream>
#include <list>
using namespace std;

class Graph
{
private:
	int V;
	list<int> *adjList;
public:
	Graph(int v=0)
	{
		V=v;
		adjList=new list<int>[V];
	}

	void addEdge(int u,int v,bool biDir=true)
	{
		adjList[u].push_back(v);
		if(biDir)
		{
			adjList[v].push_back(u);
		}
	}

	void printGraph()
	{
		for(int i=0;i<V;i++)
		{
			cout<<i<<" -> ";
			for(auto it:adjList[i])
			{
				cout<<it<<", ";
			}
			cout<<endl;
		}
	}
};

int main(int argc, char const *argv[])
{
	Graph g(8);
	g.addEdge(1,2);
	g.addEdge(1,4);
	g.addEdge(1,3);
	g.addEdge(2,4);
	g.addEdge(4,5);
	g.addEdge(3,7);
	g.addEdge(4,6);
	g.addEdge(6,7);
	g.addEdge(3,5);

	g.printGraph();
	return 0;
}