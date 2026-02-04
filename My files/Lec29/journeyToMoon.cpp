//journey to the moon
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class Graph
{
private:
	unordered_map<int,list<int> > adjList;
public:
	void addNode(int src,int dst,bool bidir=true)
	{
		adjList[src].push_back(dst);
		if(bidir)
		{
			adjList[dst].push_back(src);
		}
	}

	void printGraph()
	{
		for(auto it:adjList)
		{
			int src=it.first;
			cout<<src<<"==";
			for(auto neighbour:it.second)
			{
				cout<<"("<<neighbour<<")"<<"->";
			}
			cout<<endl;
		}
	}

	void noOfWaysHelperdfs(int src,int &countrySize,unordered_map<int,bool>& isVisit)
	{
		isVisit[src]=true;
		countrySize++;
		for(auto it:adjList[src])
		{
			if(!isVisit[it])
			{
				noOfWaysHelperdfs(it,countrySize,isVisit);
			}
		}
	}

	int noOfWays(int n)
	{
		int totalWays=n*(n-1)/2;
		unordered_map<int,bool> isVisit;

		for(int i=0;i<n;i++)
		{
			if(!isVisit[i])
			{
				int countrySize=0;
				noOfWaysHelperdfs(i,countrySize,isVisit);
				totalWays-=countrySize*(countrySize-1)/2;
			}
		}
		return totalWays;
	}
};

int main(int argc, char const *argv[])
{
	int n,p;
	cin>>n>>p;
	Graph g;
	for(int i=0;i<p;i++)
	{
		int u,v;
		cin>>u>>v;
		g.addNode(u,v);
	}
	g.printGraph();
	cout<<g.noOfWays(n);
	return 0;
}

//input
// 5 3
// 0 1
// 2 3
// 0 4
// output
// 4==(0)->
// 3==(2)->
// 2==(3)->
// 0==(1)->(4)->
// 1==(0)->
// 6