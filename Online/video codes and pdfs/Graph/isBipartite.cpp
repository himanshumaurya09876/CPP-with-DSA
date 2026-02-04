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

	bool isBipartite(T src)
	{
		queue<T> q;
		unordered_map<T,int> color;
		for(auto it:adjList)
		{
			color[it.first]=-1;
		}
		color[src]=1;
		q.push(src);
		while(!q.empty())
		{
			T entry=q.front();
			q.pop();
			for(auto it:adjList[entry])
			{
				if(color[it]==-1)
				{
					q.push(it);
					color[it]=1-color[entry];
				}
				else if(color[entry]==color[it])
				{
					return false;
				}
			}
		}
		return true;
	}
};

int main(int argc, char const *argv[])
{
	Graph<char> g;
	g.addEdge('A','B');
	g.addEdge('A','D');
	g.addEdge('B','C');
	g.addEdge('C','D');
	g.addEdge('A','C');

	g.printGraph();
	if(g.isBipartite('A'))
	{
		cout<<"Graph is Bipartite"<<endl;
	}
	else
	{
		cout<<"Graph is not Bipartite"<<endl;
	}
	return 0;
}