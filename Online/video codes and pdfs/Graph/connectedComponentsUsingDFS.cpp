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

	void dfsHelper(T src,unordered_map<T,bool> &isVisited)
	{
		cout<<src<<" ";
		isVisited[src]=true;
		for(auto it:adjList[src])
		{
			if(!isVisited[it])
			{
				isVisited[it]=true;
				dfsHelper(it,isVisited);
			}
		}
	}

	void dfsRec(T src)
	{
		unordered_map<T,bool> isVisited;
		for(auto it:adjList)
		{
			isVisited[it.first]=false;
		}
		int component=0;
		for(auto it:adjList)
		{
			if(!isVisited[it.first])
			{
				dfsHelper(it.first,isVisited);
				cout<<endl;
				component++;
			}
		}

		cout<<"Graph has "<<component<<" connected components."<<endl;
	}
};

int main(int argc, char const *argv[])
{
	Graph<char> g;
	g.addEdge('A','B');
	g.addEdge('A','C');
	g.addEdge('A','D');
	g.addEdge('D','E');
	g.addEdge('C','E');
	g.addEdge('D','B');

	g.addEdge('G','F');
	g.addEdge('G','H');
	g.addEdge('F','H');

	g.addEdge('I','J');
	g.addEdge('K','J');
	g.addEdge('I','K');

	g.printGraph();
	g.dfsRec('A');
	return 0;
}