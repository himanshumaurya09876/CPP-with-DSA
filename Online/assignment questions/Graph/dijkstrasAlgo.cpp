// DIJKSTRA'S ALGORITHM
// Given a graph consisting 'N' nodes (labeled 1 to N) where a specific given node 'S' represents the starting position and an edge between two nodes is of a given length, which may or may not be equal to other lengths in the graph.

// It is required to calculate the shortest distance from the start position (Node 'S') to all of the other nodes in the graph.

// If a node is unreachable, the distance is assumed as -1.

// Input Format:
// The first line contains T, denoting the number of test cases. First line of each test case has two integers N, M denoting the number of nodes in the graph and, denoting the number of edges in the graph.

// The next M lines each consist of three space-separated integers x,y,r where x and y denote the two nodes between which the undirected edge exists, 'r' denotes the length of edge between these corresponding nodes.

// The last line has an integer, 'S' denoting the starting position.

// Constraints:
// 1 <= N <= 3000 1 <= M <= (N*(N-1))/2 1 <= x,y <= N 1 <= r <= 10^5

// Output Format
// For each of the T test cases, print a single line consisting N-1 space separated integers denoting the shortest distance of N-1 nodes other than from starting position S in increasing order of their labels.

// For unreachable nodes, print -1.

// Sample Input
// 1
// 4 4
// 1 2 24
// 1 4 20
// 3 1 3
// 4 3 12
// 1
// Sample Output
// 24 3 15


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

	// void printGraph()
	// {
	// 	for(auto i:adjList)
	// 	{
	// 		cout<<i.first<<" -> ";
	// 		for(auto it:i.second)
	// 		{
	// 			cout<<"("<<it.first<<","<<it.second<<"), ";
	// 		}
	// 		cout<<endl;
	// 	}
	// 	cout<<endl;
	// }

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
	// 		dist[entry.second]=min(dist[entry.second],entry.first);

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
			if(it.second!=INT_MAX)
			{
				cout<<it.second<<" ";
			}
			else
			{
				cout<<-1<<" ";
			}
		}
		cout<<endl;
	}

	// void shortestPath(T src,T dest)
	// {
	// 	unordered_map<T,int> dist;
	// 	unordered_map<T,T> parent;
	// 	set<pair<int,T> > st;
	// 	for(auto it:adjList)
	// 	{
	// 		dist[it.first]=INT_MAX;
	// 	}

	// 	dist[src]=0;
	// 	st.insert(make_pair(0,src));
	// 	parent[src]=src;

	// 	while(!st.empty())
	// 	{
	// 		pair<int,T> entry=*(st.begin());
	// 		st.erase(entry);

	// 		for(auto it:adjList[entry.second])
	// 		{
	// 			if(dist[entry.second]+it.second<dist[it.first])
	// 			{
	// 				typename set<pair<int,T> >:: iterator  p=st.find(make_pair(dist[it.first],it.first));
	// 				if(p!=st.end())
	// 				{
	// 					st.erase(p);
	// 				}

	// 				st.insert(make_pair(dist[entry.second]+it.second,it.first));
	// 				dist[it.first]=dist[entry.second]+it.second;
	// 				parent[it.first]=entry.second;
	// 			}
	// 		}
	// 	}

	// 	for(auto it:dist)
	// 	{
	// 		cout<<"Distance of "<<it.first<<" from "<<src<<" is "<<it.second<<endl;
	// 	}
	// 	cout<<endl;

	// 	T temp=dest;
	// 	while(temp!=src)
	// 	{
	// 		cout<<temp<<" <- ";
	// 		temp=parent[temp];
	// 	}
	// 	cout<<src<<endl;
	// }
};

int main()
{
	int t;
	cin>>t;
	while(t>0)
	{
		int n,m,s;
		cin>>n>>m;
		Graph<int> g;
		int i=0;
		while(i<m)
		{
			int x,y,r;
			cin>>x>>y>>r;
			g.addEdge(x,y,r);
			i++;
		}
		cin>>s;
		g.ssspDijkstrasAlgo1(s);
		t--;
	}
	return 0;
}