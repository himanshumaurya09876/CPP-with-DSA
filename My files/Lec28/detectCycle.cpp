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
public:
	void addNode(T src,T dst,bool bidir=true,W wt="")
	{
		adjList[src].push_back(make_pair(dst,wt));
		if(bidir)
		{
			adjList[dst].push_back(make_pair(src,wt));
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

	bool isCyclic(T src)
	{
		queue<T> q;
		unordered_map<T,bool> visOrNot;

		q.push(src);
		visOrNot[src]=true;

		while(!q.empty())
		{
			T vertex=q.front();
			q.pop();
			for(auto it:adjList[vertex])
			{
				if(!visOrNot[it.first])
				{
					q.push(it.first);
					visOrNot[it.first]=true;
				}
				else
				{
					return true;
				}
			}
		}
		return false;
	}
};

int main(int argc, char const *argv[])
{
	Graph <string,string> g;

	// g.addNode("A","B",false);
	// g.addNode("A","C",false);

	g.addNode("A","B",false);
	g.addNode("A","C",false);
	g.addNode("C","D",false);
	g.addNode("D","F",false);
	g.addNode("B","E",false);
	g.addNode("E","F",false);

	g.printGraph();
	cout<<g.isCyclic("A");
	return 0;
}