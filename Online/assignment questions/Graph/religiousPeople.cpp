// RELIGIOUS PEOPLE
// All the people living in our imaginary world Bitworld are very religious.
// There are N cities in Bitworld numbered from 1 to N.
// Due to a storm, every road in Bitworld was destroyed and now no temples are left.
// There are 2 types of operations :

// You can construct a temple by giving away A dollars in ith city.
// You can repair an already existing road by giving away B dollars.

// Your goal is to make temples such that people of every city have access to some temple.
// People of the ith city can visit the temple only if :
// A temple exists in that city.
// OR
// There is a path from that city to a city which contains a temple. ( the path should consist of repaired roads only )
// You have to minimize the total cost such that people in every city can go to a temple and output this minimum cost.

// NOTE : You can only repair the roads which existed and not build on your own.

// Input Format:
// The first line consists of number of test cases T. Each test case consists of 4 llegers N,M,A,B. which denote number of cities, number of roads which existed , cost to build a temple , cost to repair a road. Next M lines contains M pairs denoted by U V which indicates a road existed between U and V.

// Constralls:
// 1 <= T <= 10. 1 <= N <= 100000. 0 <= M <= 100000. 1 <= A,B <= 1000000000. 1 <= U,V <= N. Each road connects 2 distinct cities.

// Output Format
// Total minimum cost in dollars.

// Sample Input
// 2
// 3 3 2 1
// 1 2
// 3 1
// 2 3
// 6 6 2 5
// 1 3
// 3 4
// 2 4
// 1 2
// 2 3
// 5 6
// Sample Output
// 4
// 12


#include <iostream>
#include <list>
#define ll long long int 
using namespace std;

class Graph
{
	list<ll> *adjList;
	ll v,e;
public:
	Graph(ll v,ll e)
	{
		this->v=v;
		this->e=e;
		adjList=new list<ll>[v];
	}

	void addEdge(ll u,ll v,bool biDir=true)
	{
		adjList[u].push_back(v);
		if(biDir)
		{
			adjList[v].push_back(u);
		}
	}

	ll dfsHelper(ll src,bool isVisited[])
	{
		isVisited[src]=true;
		ll myChild=0;

		for(auto it:adjList[src])
		{
			if(!isVisited[it])
			{
				myChild+=dfsHelper(it,isVisited);
			}
		}

		return myChild+1;
	}

	ll dfsRec(ll a,ll b)
	{
		if(a<=b)
		{
			return a*v;
		}

		bool *isVisited=new bool[v];
		for(ll i=0;i<v;i++)
		{
			isVisited[i]=false;
		}
		ll ans=0;
		for(ll i=0;i<v;i++)
		{
			if(!isVisited[i])
			{
				ll count=dfsHelper(i,isVisited);
				// cout<<count<<endl;
				ans+=a+b*(count-1);
			}
		}

		return ans;
	}
};

int main()
{
	ll t;
	cin>>t;
	while(t>0)
	{
		ll n,m,a,b;
		cin>>n>>m>>a>>b;
		Graph g(n,m);
		for(ll i=0;i<m;i++)
		{
			ll x,y;
			cin>>x>>y;
			x--;
			y--;
			g.addEdge(x,y);
		}
		cout<<g.dfsRec(a,b)<<endl;
		t--;
	}
	return 0;
}