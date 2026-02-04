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

	void bfsTopologicalSort()
	{
		queue<T> q;
		unordered_map<T,bool> isVisited;
		unordered_map<T,int> indegree;
		for(auto it:adjList)
		{
			indegree[it.first]=0;
			isVisited[it.first]=false;
		}

		for(auto it:adjList)
		{
			for(auto neighbour:it.second)
			{
				indegree[neighbour]++;
			}
		}

		for(auto it:adjList)
		{
			if(indegree[it.first]==0)
			{
				isVisited[it.first]=true;
				q.push(it.first);
			}
		}

		while(!q.empty())
		{
			T entry=q.front();
			q.pop();
			cout<<entry<<" -> ";
			for(auto it:adjList[entry])
			{
				indegree[it]--;
				if(!isVisited[it])
				{
					q.push(it);
					isVisited[it]=true;
				}
			}
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
	g.bfsTopologicalSort();
	return 0;
}