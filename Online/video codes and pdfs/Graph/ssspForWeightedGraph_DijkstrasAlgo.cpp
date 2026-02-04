#include <iostream>
#include <set>
#include <unordered_map>
#include <list>
using namespace std;

template<typename T>
class Graph
{
private:
	unordered_map<T,list<pair<T,int> > > adjList;
public:
	void addEdge(T u,T v,int wt,bool biDir=true)
	{
		adjList[u].push_back(make_pair(v,wt));
		if(biDir)
		{
			adjList[v].push_back(make_pair(u,wt));
		}
	}

	void printGraph()
	{
		for(auto i:adjList)
		{
			cout<<i.first<<" -> ";
			for(auto it:i.second)
			{
				cout<<"("<<it.first<<","<<it.second<<"), ";
			}
			cout<<endl;
		}
		cout<<endl;
	}

	// this is wrong for some testcases
	// void ssspDijkstrasAlgo(T src)
	// {
	// 	unordered_map<T,bool> isVisited;
	// 	unordered_map<T,int> dist;
	// 	set<pair<int,T> > st;
	// 	for(auto it:adjList)
	// 	{
	// 		isVisited[it.first]=false;
	// 		dist[it.first]=INT_MAX;
	// 	}

	// 	dist[src]=0;
	// 	st.insert(make_pair(0,src));

	// 	while(!st.empty())
	// 	{
	// 		pair<int,T> entry=*(st.begin());
	// 		st.erase(entry);
	// 		isVisited[entry.second]=true;
	// 		if(dist.count(entry.second))
	// 		{
	// 			dist[entry.second]=min(dist[entry.second],entry.first);
	// 		}
	// 		else
	// 		{
	// 			dist[entry.second]=entry.first;
	// 		}

	// 		for(auto it:adjList[entry.second])
	// 		{
	// 			if(!isVisited[it.first])
	// 			{
	// 				if(dist.count(it.first))
	// 				{
	// 					if(dist[it.first]>entry.first+it.second)
	// 					{
	// 						st.erase(make_pair(dist[it.first],it.first));
	// 						st.insert(make_pair(entry.first+it.second,it.first));
	// 						dist[it.first]=entry.first+it.second;
	// 					}
	// 				}
	// 				else
	// 				{
	// 					st.insert(make_pair(entry.first+it.second,it.first));
	// 				}
	// 			}
	// 		}
	// 	}

	// 	for(auto it:dist)
	// 	{
	// 		cout<<"Distance of "<<it.first<<" from "<<src<<" is "<<it.second<<endl;
	// 	}
	// 	cout<<endl;
	// }

	void ssspDijkstrasAlgo1(T src)
	{
		unordered_map<T,int> dist;
		set<pair<int,T> > st;
		for(auto it:adjList)
		{
			dist[it.first]=INT_MAX;
		}

		dist[src]=0;
		st.insert(make_pair(0,src));

		while(!st.empty())
		{
			pair<int,T> entry=*(st.begin());
			st.erase(entry);

			for(auto it:adjList[entry.second])
			{
				if(dist[entry.second]+it.second<dist[it.first])
				{
					typename set<pair<int,T> >:: iterator  p=st.find(make_pair(dist[it.first],it.first));
					if(p!=st.end())
					{
						st.erase(p);
					}

					st.insert(make_pair(dist[entry.second]+it.second,it.first));
					dist[it.first]=dist[entry.second]+it.second;
				}
			}
		}

		for(auto it:dist)
		{
			cout<<"Distance of "<<it.first<<" from "<<src<<" is "<<it.second<<endl;
		}
		cout<<endl;
	}

	void shortestPath(T src,T dest)
	{
		unordered_map<T,int> dist;
		unordered_map<T,T> parent;
		set<pair<int,T> > st;
		for(auto it:adjList)
		{
			dist[it.first]=INT_MAX;
		}

		dist[src]=0;
		st.insert(make_pair(0,src));
		parent[src]=src;

		while(!st.empty())
		{
			pair<int,T> entry=*(st.begin());
			st.erase(entry);

			for(auto it:adjList[entry.second])
			{
				if(dist[entry.second]+it.second<dist[it.first])
				{
					typename set<pair<int,T> >:: iterator  p=st.find(make_pair(dist[it.first],it.first));
					if(p!=st.end())
					{
						st.erase(p);
					}

					st.insert(make_pair(dist[entry.second]+it.second,it.first));
					dist[it.first]=dist[entry.second]+it.second;
					parent[it.first]=entry.second;
				}
			}
		}

		for(auto it:dist)
		{
			cout<<"Distance of "<<it.first<<" from "<<src<<" is "<<it.second<<endl;
		}
		cout<<endl;

		T temp=dest;
		while(temp!=src)
		{
			cout<<temp<<" <- ";
			temp=parent[temp];
		}
		cout<<src<<endl;
	}
};

int main(int argc, char const *argv[])
{
	// Graph<int> g;
	// g.addEdge(1,2,1);
	// g.addEdge(1,3,4);
	// g.addEdge(1,4,7);
	// g.addEdge(2,3,1);
	// g.addEdge(4,3,2);

	// g.printGraph();
	// g.ssspDijkstrasAlgo(1);
	// g.ssspDijkstrasAlgo1(1);

	// Graph<string> india;
	// india.addEdge("Amritsar","Delhi",1);
	// india.addEdge("Amritsar","Jaipur",4);
	// india.addEdge("Jaipur","Delhi",2);
	// india.addEdge("Jaipur","Mumbai",8);
	// india.addEdge("Bhopal","Agra",2);
	// india.addEdge("Mumbai","Bhopal",3);
	// india.addEdge("Agra","Delhi",1);

	// india.printGraph();
	// india.ssspDijkstrasAlgo("Amritsar");
	// india.ssspDijkstrasAlgo1("Amritsar");

	// india.shortestPath("Amritsar","Mumbai");

	Graph<char> g1;
	g1.addEdge('A','B',-1,false);
	g1.addEdge('A','C',4,false);
	g1.addEdge('B','C',3,false);
	g1.addEdge('B','D',2,false);
	g1.addEdge('B','E',2,false);
	g1.addEdge('E','D',-3,false);
	g1.addEdge('D','B',1,false);
	g1.addEdge('D','C',5,false);
	
	g1.printGraph();
	// g1.ssspDijkstrasAlgo('A');
	g1.ssspDijkstrasAlgo1('A');

	return 0;
}