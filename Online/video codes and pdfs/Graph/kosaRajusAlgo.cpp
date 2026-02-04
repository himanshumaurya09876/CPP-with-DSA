//to ceheck whether a graph is strongly connected or not
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <list>
using namespace std;

template<typename T>
class Graph
{
public:
	unordered_map<T,list<T> > adjList;
	int v;
	Graph(int v)
	{
		this->v=v;
	}

	int getVertices()
	{
		return v;
	}

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

	int dfsHelper(T src,unordered_map<T,bool> &isVisited)
	{
		int count=1;
		isVisited[src]=true;
		for(auto it:adjList[src])
		{
			if(!isVisited[it])
			{
				isVisited[it]=true;
				count+=dfsHelper(it,isVisited);
			}
		}
		return count;
	}

	int dfsRec(T src)
	{
		unordered_map<T,bool> isVisited;
		for(auto it:adjList)
		{
			isVisited[it.first]=false;
		}
		return dfsHelper(src,isVisited);
	}
};

template<typename T>
bool kosaRajusForSCC(T src,Graph<T> &grf)
{
	Graph<T> temp(grf.v);
	for(auto it:grf.adjList)
	{
		for(auto neighbour:it.second)
		{
			temp.addEdge(neighbour,it.first,false);
		}
	}
	if(grf.v==grf.dfsRec(src) && grf.v==temp.dfsRec(src))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main(int argc, char const *argv[])
{
	// Graph<char> g1(3);
	// g1.addEdge('A','B',false);
	// g1.addEdge('A','C',false);
	// g1.addEdge('B','C',false);

	Graph<char> g2(6);
	g2.addEdge('A','B',false);
	g2.addEdge('B','C',false);
	g2.addEdge('C','D',false);
	g2.addEdge('D','E',false);
	g2.addEdge('E','A',false);
	g2.addEdge('D','F',false);
	g2.addEdge('F','D',false);

	// g1.printGraph();
	// cout<<kosaRajusForSCC('A',g1)<<endl;

	g2.printGraph();
	cout<<kosaRajusForSCC('A',g2)<<endl;

	return 0;
}