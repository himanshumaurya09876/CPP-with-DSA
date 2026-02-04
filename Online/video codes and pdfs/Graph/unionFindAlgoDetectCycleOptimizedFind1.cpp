#include <iostream>
using namespace std;

class edge
{
public:
	int src;
	int dest;
};

class graph
{
public:
	int v,e;
	edge* ejList;

	graph(int v,int e)
	{
		this->v=v;
		this->e=e;
		ejList=new edge[e];
	}
};

int findParent(int parent[],int child)
{
	if(parent[child]==-1)
	{
		return child;
	}

	return findParent(parent,parent[child]);
}

void makeUnion(int parent[],int rank[],int u,int v)
{
	int parentU=findParent(parent,u);
	int parentV=findParent(parent,v);

	if(rank[parentU]>rank[parentV])
	{
		parent[parentV]=parentU;
		rank[parentU]++;
	}
	else
	{
		parent[parentU]=parentV;
		rank[parentV]++;
	}
}

bool isCyclic(graph &g)
{
	int *parent=new int[g.v];
	int *rank=new int[g.v];

	for(int i=0;i<g.v;i++)
	{
		rank[i]=0;
		parent[i]=-1;
	}

	for(int i=0;i<g.e;i++)
	{
		int u=findParent(parent,g.ejList[i].src);
		int v=findParent(parent,g.ejList[i].dest);

		if(u==v)
		{
			return true;
		}
		makeUnion(parent,rank,u,v);
	}

	return false;
}

int main(int argc, char const *argv[])
{
	int v,e;
	cin>>v>>e;
	graph g(v,e);
	for(int i=0;i<e;i++)
	{
		cin>>g.ejList[i].src>>g.ejList[i].dest;
	}

	if(isCyclic(g))
	{
		cout<<"Cyclic"<<endl;
	}
	else
	{
		cout<<"Non Cyclic"<<endl;
	}
	return 0;
}

// 6 8
// 0 1
// 1 2
// 0 4
// 1 3
// 4 5
// 2 3
// 5 3
// 4 2