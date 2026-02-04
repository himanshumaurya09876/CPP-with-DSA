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

	void dfsHelper(T src,unordered_map<T,bool> &isVisited,list<T> &order)
	{
		isVisited[src]=true;
		for(auto it:adjList[src])
		{
			if(!isVisited[it])
			{
				isVisited[it]=true;
				dfsHelper(it,isVisited,order);
			}
		}

		order.push_front(src);
	}

	void dfsTopologicalSort()
	{
		unordered_map<T,bool> isVisited;
		for(auto it:adjList)
		{
			isVisited[it.first]=false;
		}
		list<T> order;
		for(auto it:adjList)
		{
			if(!isVisited[it.first])
			{
				dfsHelper(it.first,isVisited,order);
			}
		}

		for(auto it:order)
		{
			cout<<it<<" -> ";
		}
		cout<<endl;
	}
};

int main(int argc, char const *argv[])
{
	// Graph<char> g;
	// g.addEdge('A','C',false);
	// g.addEdge('B','C',false);
	// g.addEdge('D','E',false);
	// g.addEdge('C','E',false);
	// g.addEdge('C','F',false);
	// g.addEdge('F','G',false);
	// g.addEdge('E','G',false);
	// g.addEdge('G','H',false);

	// g.addEdge('I','J',false);
	// g.addEdge('K','J',false);
	// g.addEdge('J','L',false);
	// g.addEdge('J','M',false);

	Graph<string> g;
	g.addEdge("English","Programming logic",false);
	g.addEdge("Maths","Programming logic",false);
	g.addEdge("English","HTML",false);
	g.addEdge("Programming logic","HTML",false);
	g.addEdge("Programming logic","Python",false);
	g.addEdge("Programming logic","Java",false);
	g.addEdge("HTML","CSS",false);
	g.addEdge("CSS","JS",false);
	g.addEdge("Programming logic","JS",false);
	g.addEdge("JS","Web Development",false);
	g.addEdge("Python","Web Development",false);
	g.addEdge("Java","Web Development",false);

	g.printGraph();
	g.dfsTopologicalSort();
	return 0;
}