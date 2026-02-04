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
	unordered_map<T,list<pair<T,int> > > adjList;
	int v;
public:
	Graph(int V=0)
	{
		v=V;
	}

	void addEdge(T u,T v,int wt,bool biDir=true)
	{
		adjList[u].push_back(make_pair(v,wt));
		if(biDir)
		{
			adjList[v].push_back(make_pair(u,wt));
		}
	}

	int dfsHelper(T src,unordered_map<T,bool> &isVisited,int &ans)
	{
		isVisited[src]=true;
		int count=1;
		for(auto it:adjList[src])
		{
			if(!isVisited[it.first])
			{
				int x=dfsHelper(it.first,isVisited,ans);
				cout<<v-x<<" <- "<<it.first<<" -> "<<x<<endl;
				count+=x;
				ans+=2*it.second*min(x,v-x);
			}
		}
		return count;
	}

	int maxiCost(T src)
	{
		unordered_map<T,bool> isVisited;
		int ans=0;
		for(auto it:adjList)
		{
			isVisited[it.first]=false;
		}
		dfsHelper(src,isVisited,ans);
		return ans;
	}
};

int main(int argc, char const *argv[])
{
	Graph<int> g(4);
	g.addEdge(1,2,3);
	g.addEdge(2,3,2);
	g.addEdge(3,4,2);

	cout<<g.maxiCost(1)<<endl;
	return 0;
}