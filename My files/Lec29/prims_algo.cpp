#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

//undirected graph
class graph{
private:
	unordered_map<int,list<pair<int,int> > > adjlist;
public:
	void insert(int src,int dest,int wt)
	{
		adjlist[src].push_back(make_pair(dest,wt));
		adjlist[dest].push_back(make_pair(src,wt));
	}

	void print()
	{
		for(auto it: adjlist)
		{
			cout<<it.first<<"-->";
			for(auto it1: it.second)
			{
				cout<<"("<<it1.first<<", "<<it1.second<<") & ";
			}
			cout<<endl;
		}
	}

	void prims(int srcVer,graph &tree)
	{
		priority_queue<pair<int,pair<int,int> >, vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > pq;
		unordered_map<int,bool> isVisited;
		isVisited[srcVer]=true;
		for(auto it:adjlist[srcVer])
		{
			pq.push(make_pair(it.second,make_pair(srcVer,it.first)));
		}
		while(!pq.empty())
		{
			pair<int,pair<int,int> > ele = pq.top();
			pq.pop();
			if(!isVisited[ele.second.second])
			{
				tree.insert(ele.second.first,ele.second.second,ele.first);
				isVisited[ele.second.second]=true;
				for(auto it:adjlist[ele.second.second])
				{
					if(!isVisited[it.first])
					{
						pq.push(make_pair(it.second,make_pair(ele.second.second,it.first)));
					}
				}
			}
		}
	}
};

int main(int argc, char const *argv[])
{
	graph g1;
	g1.insert(0,1,4);
	g1.insert(0,7,8);
	g1.insert(1,2,8);
	g1.insert(1,7,11);
	g1.insert(2,8,2);
	g1.insert(7,8,7);
	g1.insert(8,6,6);
	g1.insert(2,3,7);
	g1.insert(2,5,4);
	g1.insert(6,5,2);
	g1.insert(3,5,14);
	g1.insert(3,4,9);
	g1.insert(5,4,10);
	g1.insert(7,6,1);
	g1.print();
	graph tree;
	g1.prims(0,tree);
	cout<<"Minimum spanning tree is: "<<endl;
	tree.print();
	return 0;
}