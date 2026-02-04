#include <iostream>
#include <queue>
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
		cout<<endl;
	}

	void sssp(T src)
	{
		queue<T> q;
		unordered_map<T,bool> isVisited;
		unordered_map<T,int> dist;
		for(auto it:adjList)
		{
			isVisited[it.first]=false;
			dist[it.first]=INT_MAX;
		}
		isVisited[src]=true;
		dist[src]=0;
		q.push(src);
		while(!q.empty())
		{
			T entry=q.front();
			q.pop();
			for(auto it:adjList[entry])
			{
				if(!isVisited[it])
				{
					q.push(it);
					isVisited[it]=true;
					dist[it]=dist[entry]+1;
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
	g.sssp('A');
	g.sssp('D');
	return 0;
}