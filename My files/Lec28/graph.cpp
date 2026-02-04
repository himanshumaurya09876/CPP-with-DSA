#include <iostream>
#include <list>//this stl is for linked list in stl it is implemented as doubly linked list
#include <unordered_map>
using namespace std;

template <typename T,typename W>
class Graph
{
private:
	unordered_map<T,list<pair<T,W> > >adjList;
public:
	void addNode(T src,T dst,bool bidir=true,W wt="")
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
};

int main(int argc, char const *argv[])
{
	Graph <int,string> g;
	g.addNode(1,2,false,"a");
	g.addNode(1,3,false,"b");
	g.addNode(1,4,false,"c");
	g.addNode(2,1,false,"d");
	g.addNode(2,5,false,"e");
	g.addNode(4,5,false,"f");
	g.addNode(5,3,false);

	g.printGraph();
	return 0;
}