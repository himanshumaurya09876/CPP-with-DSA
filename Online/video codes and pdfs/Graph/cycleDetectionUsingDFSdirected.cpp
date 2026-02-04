#include <iostream>
#include <queue>
#include <stack>
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

	bool dfsHelper(T src,unordered_map<T,bool> &isVisited,unordered_map<T,bool> &inStack)
	{
		isVisited[src]=true;
		inStack[src]=true;
		for(auto it:adjList[src])
		{
			if(!isVisited[it] && dfsHelper(it,isVisited,inStack) || inStack[it])
			{
				return true;
			}
		}
		inStack[src]=false;
		return false;
	}

	bool dfsCycleDetectDirected(T src)
	{
		unordered_map<T,bool> isVisited;
		unordered_map<T,bool> inStack;
		for(auto it:adjList)
		{
			isVisited[it.first]=false;
			inStack[it.first]=false;
		}

		for(auto it:adjList)
		{
			if(dfsHelper(src,isVisited,inStack))
			{
				return true;
			}
		}

		return false;
	}
};

int main(int argc, char const *argv[])
{
	Graph<int> g;
	g.addEdge(0,1,false);
	g.addEdge(0,2,false);
	g.addEdge(1,5,false);
	g.addEdge(4,5,false);
	g.addEdge(2,4,false);
	g.addEdge(2,3,false);
	g.addEdge(3,0,false); 

	// g.addEdge(1,2,false);
	// g.addEdge(2,3,false);
	// g.addEdge(3,4,false);
	// g.addEdge(4,1,false);

	g.printGraph();
	if(g.dfsCycleDetectDirected(0))
	{
		cout<<"Cyclic"<<endl;
	}
	else
	{
		cout<<"Acyclic"<<endl;
	}
	return 0;
}