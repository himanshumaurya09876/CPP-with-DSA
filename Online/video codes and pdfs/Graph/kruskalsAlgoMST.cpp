// kruskalsAlgoMST
#include <iostream>
#include <algorithm>
using namespace std;

class edge
{
public:
	int src;
	int dest;
	int wt;
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

bool compare(edge e1,edge e2)
{
	return e1.wt<e2.wt;
}

graph* kruskalsMST(graph &g1)
{
	graph *g2=new graph(g1.v,g1.v-1);
	sort(g1.ejList,g1.ejList+g1.e,compare);
	int *parent=new int[g1.v];
	int *rank=new int[g1.v];

	for(int i=0;i<g1.v;i++)
	{
		rank[i]=0;
		parent[i]=-1;
	}

	int i=0,j=0;
	while(j<g2->e)
	{
		int u=findParent(parent,g1.ejList[i].src);
		int v=findParent(parent,g1.ejList[i].dest);

		if(u!=v)
		{
			g2->ejList[j].src=g1.ejList[i].src;
			g2->ejList[j].dest=g1.ejList[i].dest;
			g2->ejList[j].wt=g1.ejList[i].wt;
			makeUnion(parent,rank,u,v);	
			j++;
		}
		i++;
	}

	return g2;
}

int main(int argc, char const *argv[])
{
	int v,e;
	cin>>v>>e;
	graph g(v,e);
	for(int i=0;i<e;i++)
	{
		cin>>g.ejList[i].src>>g.ejList[i].dest>>g.ejList[i].wt;
	}

	graph *mst=kruskalsMST(g);
	int total=0;
	for(int i=0;i<mst->e;i++)
	{
		cout<<"("<<mst->ejList[i].src<<" <-> "<<mst->ejList[i].dest<<", "<<mst->ejList[i].wt<<")"<<endl;
		total+=mst->ejList[i].wt;
	}
	cout<<"Total weight="<<total<<endl;

	return 0;
}

// 5 6
// 0 1 2
// 0 3 3
// 1 3 1
// 3 4 8
// 1 2 5
// 2 4 6

// 7 8
// 0 3 4
// 0 1 6
// 1 2 5
// 3 2 7
// 3 4 2
// 4 5 4
// 5 6 1
// 4 6 3