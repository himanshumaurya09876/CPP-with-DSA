#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

template<typename T>
class Graph
{
private:
	unordered_map<T,list<T> > adjList;
public:
	void addEdge(T u,T v,bool biDir=true)
	{
		adjList[u].push_back(v);
		if(biDir)
		{
			adjList[v].push_back(u);
		}
	}

	void printGraph()
	{
		for(auto i:adjList)
		{
			cout<<i.first<<" -> ";
			for(auto it:i.second)
			{
				cout<<it<<", ";
			}
			cout<<endl;
		}
	}
};

int main(int argc, char const *argv[])
{
	Graph<char> g;
	g.addEdge('A','B');
	g.addEdge('A','C');
	g.addEdge('A','D');
	g.addEdge('D','E');
	g.addEdge('D','F');
	g.addEdge('C','E');
	g.addEdge('C','G');
	g.addEdge('G','F');
	g.addEdge('D','B');

	g.printGraph();
	return 0;
}