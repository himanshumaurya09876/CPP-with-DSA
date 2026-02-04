#include <iostream>
#include <list>
#include <stack>
#include <unordered_map>
using namespace std;

template <typename T,typename W>
class Graph
{
private:
	unordered_map<T,list<pair<T,W> > >adjList;

	void dfsHelper(T src,unordered_map<T,bool>& isVisited)
	{
		isVisited[src]=true;
		cout<<src<<"->";
		for(auto it:adjList[src])
		{
			if(!isVisited[it.first])
				dfsHelper(it.first,isVisited);
		}
	}
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

	void dfsTraversal(T src)//recursively
	{
		unordered_map<T,bool> isVisited;
		dfsHelper(src,isVisited);
		cout<<endl;
	}

	void dfsTraversal1(T src)
	{
		stack<T> st;
		unordered_map<T,bool> isVisited;
		st.push(src);
		isVisited[src]=true;
		while(!st.empty())
		{
			T vertex=st.top();
			st.pop();
			cout<<vertex<<"->";
			for(auto it:adjList[vertex])
			{
				if(!isVisited[it.first])
				{
					st.push(it.first);
					isVisited[it.first]=true;
				}
			}
		}
		cout<<endl;
	}
};

int main(int argc, char const *argv[])
{
	Graph <int,string> g;
	g.addNode(1,2,false,"a");
	g.addNode(1,3,false,"b");
	g.addNode(1,4,false,"c");
	g.addNode(2,1,false,"d");
	g.addNode(2,5,false,"e");
	g.addNode(4,5,false,"f");
	g.addNode(5,3,false);

	g.printGraph();
	g.dfsTraversal(1);
	g.dfsTraversal1(1);
	return 0;
}