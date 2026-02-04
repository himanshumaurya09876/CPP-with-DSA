// Dijkstra algorithm gives the minimum distance of a node from rest of the nodes of the graph
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
	void addNode(T src,T dst,W wt="",bool bidir=true)
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

	void dijkstra(T src) 
	{
		set<pair<int,T> > priority;
		unordered_map<T,int> minDist;
		unordered_map<T,bool> isVisit;
		priority.insert(make_pair(0,src));
		isVisit[src]=true;
		minDist[src]=0;
		while(!priority.empty())
		{
			pair<int,T> front=*priority.begin();
			priority.erase(front);
			isVisit[front.second]=true;
			for(auto it:adjList[front.second])
			{
				if(!isVisit[it.first])
				{
					if(minDist.count(it.first))//update here
					{
						if(minDist[it.first] > it.second+front.first)
						{
							priority.erase(make_pair(minDist[it.first],it.first));
							priority.insert(make_pair(it.second+front.first,it.first));
							minDist[it.first]=it.second+front.first;
						} 
					}
					else//insert only
					{
						priority.insert(make_pair(it.second+front.first,it.first));
						minDist[it.first]=it.second+front.first;
					}
				}
			}
		}

		for(auto it:minDist)
		{
			cout<<it.first<<"->"<<it.second<<endl;
		}
	}
};

int main(int argc, char const *argv[])
{
	Graph <string,int> g1;
	g1.addNode("1","4",3);
	g1.addNode("1","3",7);
	g1.addNode("1","2",5);
	g1.addNode("2","6",2);
	g1.addNode("1","6",9);
	g1.addNode("1","9",10);
	g1.addNode("2","3",1);
	g1.addNode("4","3",5);
	g1.addNode("4","9",3);

	// Graph <int,int> g1;
	// g1.addNode(1,4,3);
	// g1.addNode(1,6,5);
	// g1.addNode(1,2,4);
	// g1.addNode(1,3,2);
	// g1.addNode(2,3,6);
	// g1.addNode(2,6,4);
	// g1.addNode(3,6,8);
	// g1.addNode(3,5,9);
	// g1.addNode(3,4,3);
	// g1.addNode(5,4,5);

	// Graph <int,int> g1;
	// g1.addNode(1,4,1);
	// g1.addNode(1,6,7);
	// g1.addNode(1,2,1);
	// g1.addNode(1,3,3);
	// g1.addNode(2,3,1);
	// g1.addNode(2,6,3);
	// g1.addNode(3,6,2);
	// g1.addNode(3,5,3);
	// g1.addNode(3,4,2);
	// g1.addNode(5,4,1);

	g1.printGraph();
	g1.dijkstra("1");
	return 0;
}