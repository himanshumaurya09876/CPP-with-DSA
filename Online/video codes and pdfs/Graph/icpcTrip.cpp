#include <iostream>
#include <set>
#include <unordered_map>
#include <list>
using namespace std;

template<typename T>
class Graph
{
private:
	unordered_map<T,list<pair<T,pair<int,int> > > > adjList;
public:
	void addEdge(T u,T v,int wt1,int wt2,bool biDir=true)
	{
		adjList[u].push_back(make_pair(v,make_pair(wt1,wt2)));
		if(biDir)
		{
			adjList[v].push_back(make_pair(u,make_pair(wt1,wt2)));
		}
	}

	void printGraph()
	{
		for(auto i:adjList)
		{
			cout<<i.first<<" -> ";
			for(auto it:i.second)
			{
				cout<<"("<<it.first<<","<<it.second.first<<","<<it.second.second<<"), ";
			}
			cout<<endl;
		}
		cout<<endl;
	}

	int findCheapestPath(T src,T dest)
	{
		unordered_map<T,int> dist1;
		unordered_map<T,int> dist2;
		set<pair<int,T> > st;

		for(auto it:adjList)
		{
			dist1[it.first]=INT_MAX;
			dist2[it.first]=INT_MAX;
		}

		dist1[src]=0;
		st.insert(make_pair(0,src));

		while(!st.empty())
		{
			pair<int,T> entry=*(st.begin());
			st.erase(entry);

			for(auto it:adjList[entry.second])
			{
				if(dist1[entry.second]+it.second.first<dist1[it.first])
				{
					typename set<pair<int,T> >:: iterator  p=st.find(make_pair(dist1[it.first],it.first));
					if(p!=st.end())
					{
						st.erase(p);
					}

					st.insert(make_pair(dist1[entry.second]+it.second.first,it.first));
					dist1[it.first]=dist1[entry.second]+it.second.first;
				}
			}
		}

		dist2[dest]=0;
		st.insert(make_pair(0,dest));

		while(!st.empty())
		{
			pair<int,T> entry=*(st.begin());
			st.erase(entry);

			for(auto it:adjList[entry.second])
			{
				if(dist2[entry.second]+it.second.first<dist2[it.first])
				{
					typename set<pair<int,T> >:: iterator  p=st.find(make_pair(dist2[it.first],it.first));
					if(p!=st.end())
					{
						st.erase(p);
					}

					st.insert(make_pair(dist2[entry.second]+it.second.first,it.first));
					dist2[it.first]=dist2[entry.second]+it.second.first;
				}
			}
		}

		int minCost=dist1[dest];//when i am not taking flight

		for(auto i:adjList)//try each pair for taking 1 flight
		{
			for(auto it:i.second)
			{
				int currCost=it.second.second;
				if(i.first!=src)
				{
					currCost+=dist1[i.first];
				}
				if(it.first!=dest)
				{
					currCost+=dist2[it.first];
				}
				minCost=min(minCost,currCost);
			}
		}

		for(auto it:dist1)
		{
			cout<<"Distance of "<<it.first<<" from "<<src<<" is "<<it.second<<endl;
		}
		cout<<endl;

		for(auto it:dist2)
		{
			cout<<"Distance of "<<it.first<<" from "<<dest<<" is "<<it.second<<endl;
		}
		cout<<endl;

		return minCost;
	}
};

int main(int argc, char const *argv[])
{
	Graph<char> route;
	route.addEdge('A','B',10,2);
	route.addEdge('A','D',15,50);
	route.addEdge('D','B',6,10);
	route.addEdge('C','B',1,2);
	route.addEdge('C','D',5,10);
	route.addEdge('A','E',7,100);
	route.addEdge('D','E',3,200);
	route.addEdge('D','G',10,1);
	route.addEdge('G','F',5,1000);
	route.addEdge('E','F',15,20);
	route.addEdge('C','F',2,10);

	cout<<route.findCheapestPath('A','G')<<endl;
	return 0;
}