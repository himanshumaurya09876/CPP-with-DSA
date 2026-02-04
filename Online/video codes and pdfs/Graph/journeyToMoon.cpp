#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class Graph
{
private:
	list<int> *l;
	int v;
public:
	Graph(int v)
	{
		this->v=v;
		l=new list<int>[v];
	}

	void addEdge(int u,int v)
	{
		l[u].push_back(v);
		l[v].push_back(u);
	}

	void dfsHelper(int i,bool visited[],int &countrySize)
	{
		visited[i]=true;
		countrySize++;
		for(auto it:l[i])
		{
			if(!visited[it])
			{
				dfsHelper(it,visited,countrySize);
			}
		}
	}

	int dfs()
	{
		bool *visited=new bool[v];
		for(int i=0;i<v;i++)
		{
			visited[i]=false;
		}
		int ans=v*(v-1)/2;

		for(int i=0;i<v;i++)
		{
			if(!visited[i])
			{
				int countrySize=0;
				dfsHelper(i,visited,countrySize);
				ans-=countrySize*(countrySize-1)/2;
			}
		}

		return ans;
	}
};

int main(int argc, char const *argv[])
{
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(3,4);
	cout<<g.dfs()<<endl;
	return 0;
}