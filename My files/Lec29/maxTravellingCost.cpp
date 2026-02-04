#include <iostream>
#include <list>
#include <unordered_map>
#include <set>
using namespace std;

template <typename T,typename W>
class Graph
{
private:
	unordered_map<T,list<pair<T,W> > >adjList;
public:
	void addNode(T src,T dst,W wt,bool bidir=true)
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

	void dfsHelper(T src,int &ans,unordered_map<int,bool>& isVisit,int v)
	{
		isVisit[src]=true;
		int count=1;
		int x=0;
		for(auto it:adjList[src])
		{
			T child =it.first;
			W wt=it.second;
			if(!isVisit[child])
			{
				x=dfsHelper(child,ans,isVisit);
				count+=x;
				ans+=2*wt*min(x,v-x);
			}
		}
		return count;
	}

	int dfs(int v)
	{
		int ans=0;
		unordered_map<int,bool> isVisit;
		dfsHelper(0,ans,isVisit,v);
		return ans;
	}
};

int main(int argc, char const *argv[])
{
	int vertex;
	cin>>vertex;

	Graph<int,int> g;
	for (int i = 0; i < vertex; ++i)
	{
		int u, v, wt;
		cin>>u>>v>>wt;
		g.addNode(u,v,wt);
	}

	cout<<g.dfs(vertex)<<endl;


	return 0;
}