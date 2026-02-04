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

	void bfs(T src)
	{
		queue<T> q;
		unordered_map<T,bool> isVisited;
		for(auto it:adjList)
		{
			isVisited[it.first]=false;
		}
		isVisited[src]=true;
		q.push(src);
		while(!q.empty())
		{
			T entry=q.front();
			q.pop();
			cout<<entry<<" ";
			for(auto it:adjList[entry])
			{
				if(!isVisited[it])
				{
					q.push(it);
					isVisited[it]=true;
				}
			}
		}
		cout<<endl;
	}

	void dfs(T src)
	{
		stack<T> st;
		unordered_map<T,bool> isVisited;
		for(auto it:adjList)
		{
			isVisited[it.first]=false;
		}
		isVisited[src]=true;
		st.push(src);
		while(!st.empty())
		{
			T entry=st.top();
			st.pop();
			cout<<entry<<" ";
			for(auto it:adjList[entry])
			{
				if(!isVisited[it])
				{
					st.push(it);
					isVisited[it]=true;
				}
			}
		}
		cout<<endl;
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
		dfsHelper(src,isVisited);
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
	g.bfs('A');
	g.dfs('A');
	g.dfsRec('A');
	return 0;
}