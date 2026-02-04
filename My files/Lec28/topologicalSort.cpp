#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

template <typename T,typename W>
class Graph
{
private:
	unordered_map<T,list<pair<T,W> > >adjList;
	unordered_map<T,int> indegree;
public:
	void addNode(T src,T dst,bool bidir=true,W wt="")
	{
		adjList[src].push_back(make_pair(dst,wt));
		indegree[dst]++;
		// cout<<src<<" "<<dst<<" "<<indegree[src]<<endl;
		if(bidir)
		{
			adjList[dst].push_back(make_pair(src,wt));
			indegree[src]++;
		}
	}

	void printGraph()
	{
		for(auto it:adjList)
		{
			T src=it.first;
			cout<<src<<"==";
			for(auto neighbour:it.second)
			{
				cout<<"("<<neighbour.first<<","<<neighbour.second<<")"<<"->";
			}
			cout<<endl;
		}
	}

	void topologicalPrint()
	{
		queue<T> q;
		for(auto it:adjList)
		{
			if(indegree[it.first]==0)
			{
				q.push(it.first);
				// cout<<it.first<<" ";
			}
		}

		while(!q.empty())
		{
			T vertex=q.front();
			q.pop();
			cout<<vertex<<"->";
			for(auto it:adjList[vertex])
			{
				indegree[it.first]--;
				if(indegree[it.first]==0)
				{
					q.push(it.first);
				}
			}
		}
	}
};

int main(int argc, char const *argv[])
{
	Graph <string,string> g;
	g.addNode("Logic","Programming",false);
	g.addNode("Language","Programming",false);
	g.addNode("Programming","ML",false);
	g.addNode("Programming","Web Dev",false);
	g.addNode("ML","Data Scientist",false);
	g.addNode("Data science","Data Scientist",false);

	// g.printGraph();
	g.topologicalPrint();
	return 0;
}