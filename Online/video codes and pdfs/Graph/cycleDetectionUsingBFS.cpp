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

	bool bfsDetectCycle(T src)
	{
		queue<T> q;
		unordered_map<T,bool> isVisited;
		for(auto it:adjList)
		{
			isVisited[it.first]=false;
		}
		unordered_map<T,T> parent;
		isVisited[src]=true;
		parent[src]=src;
		q.push(src);
		while(!q.empty())
		{
			T entry=q.front();
			q.pop();
			for(auto it:adjList[entry])
			{
				if(isVisited[it] && parent[entry]!=it)
				{
					return true;
				}
				else if(!isVisited[it])
				{
					q.push(it);
					isVisited[it]=true;
					parent[it]=entry;
				}
			}
		}
		return false;
	}
};

int main(int argc, char const *argv[])
{
	Graph<char> g;
	g.addEdge('A','B');
	g.addEdge('A','C');
	g.addEdge('B','D');
	g.addEdge('C','D');

	g.printGraph();
	if(g.bfsDetectCycle('A'))
	{
		cout<<"Cyclic"<<endl;
	}
	else
	{
		cout<<"Acyclic"<<endl;
	}
	return 0;
}