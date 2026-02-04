// #include <iostream>
// #include <queue>
// #include <stack>
// #include <unordered_map>
// #include <list>
// using namespace std;

// class Graph
// {
// private:
// 	unordered_map<int,list<int> > adjList;
// public:
// 	void addEdge(int u,int v,bool biDir=true)
// 	{
// 		adjList[u].push_back(v);
// 		if(biDir)
// 		{
// 			adjList[v].push_back(u);
// 		}
// 	}

// 	void printGraph()
// 	{
// 		for(auto i:adjList)
// 		{
// 			cout<<i.first<<" -> ";
// 			for(auto it:i.second)
// 			{
// 				cout<<it<<", ";
// 			}
// 			cout<<endl;
// 		}
// 	}

// 	int sssp(int n)
// 	{
// 		int src=1;
// 		queue<int> q;
// 		unordered_map<int,bool> isVisited;
// 		unordered_map<int,int> dist;
// 		unordered_map<int,int> parent;
// 		for(int i=1;i<=36;i++)
// 		{
// 			dist[i]=INT_MAX;
//			isVisited[i]=false;
// 		}
// 		isVisited[src]=true;
// 		dist[src]=0;
// 		q.push(src);
// 		while(!q.empty())
// 		{
// 			int entry=q.front();
// 			q.pop();
// 			for(auto it:adjList[entry])
// 			{
// 				if(!isVisited[it])
// 				{
// 					q.push(it);
// 					isVisited[it]=true;
// 					dist[it]=dist[entry]+1;
// 					parent[it]=entry;
// 				}
// 			}
// 		}
// 		cout<<endl;

// 		// for(auto it:dist)
// 		// {
// 		// 	cout<<"Distance of "<<it.first<<" from "<<src<<" is "<<it.second<<endl;
// 		// }

// 		int temp=n;
// 		while(temp!=src)
// 		{
// 			cout<<temp<<" <--  ";
// 			temp=parent[temp];
// 		}
// 		cout<<src<<endl;
// 		return dist[n];
// 	}
// };

// int main(int argc, char const *argv[])
// {
// 	int n=36;
// 	int *jumps=new int[n+1];
// 	for(int i=0;i<=n;i++)
// 	{
// 		jumps[i]=0;
// 	}

// 	jumps[2]=13;
// 	jumps[5]=2;
// 	jumps[17]=-13;
// 	jumps[18]=11;
// 	jumps[24]=-8;
// 	jumps[25]=10;
// 	jumps[32]=-2;
// 	jumps[34]=-22;
// 	jumps[20]=-14;
// 	jumps[9]=18;

// 	Graph ludo;
// 	for(int i=1;i<=36;i++)
// 	{
// 		for(int j=1;j<=6 && i+j<=36;j++)
// 		{
// 			ludo.addEdge(i,i+j+jumps[i+j],false);
// 		}
// 	}

// 	int moves=ludo.sssp(n);
// 	cout<<"Minimum number of moves is "<<moves<<endl;

// 	return 0;
// }
// //shortest path is 1->15->29->30->36 with 4 moves

#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <list>
using namespace std;

int sssp(int jumps[],int n)
{
	int src=1;
	queue<int> q;
	unordered_map<int,bool> isVisited;
	unordered_map<int,int> dist;
	unordered_map<int,int> parent;
	for(int i=1;i<=36;i++)
	{
		dist[i]=INT_MAX;
		isVisited[i]=false;
	}
	isVisited[src]=true;
	dist[src]=0;
	q.push(src);
	while(!q.empty())
	{
		int entry=q.front();
		q.pop();
		for(int it=entry+1;it<=entry+6 && it<=n;it++)
		{
			if(!isVisited[it+jumps[it]])
			{
				q.push(it+jumps[it]);
				isVisited[it+jumps[it]]=true;
				dist[it+jumps[it]]=dist[entry]+1;
				parent[it+jumps[it]]=entry;
			}
		}
	}
	cout<<endl;

	for(auto it:dist)
	{
		cout<<"Distance of "<<it.first<<" from "<<src<<" is "<<it.second<<endl;
	}

	int temp=n;
	while(temp!=src)
	{
		cout<<temp<<" <--  ";
		temp=parent[temp];
	}
	cout<<src<<endl;
	return dist[n];
}

int main(int argc, char const *argv[])
{
	int n=36;
	int *jumps=new int[n+1];
	fill(jumps,jumps+n+1,0);

	jumps[2]=13;
	jumps[5]=2;
	jumps[17]=-13;
	jumps[18]=11;
	jumps[24]=-8;
	jumps[25]=10;
	jumps[32]=-2;
	jumps[34]=-22;
	jumps[20]=-14;
	jumps[9]=18;

	int moves=sssp(jumps,n);
	cout<<"Minimum number of moves is "<<moves<<endl;

	return 0;
}