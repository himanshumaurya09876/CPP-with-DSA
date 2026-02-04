//let us solve a problem to find first k cars closest to origin(my location)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Car
{
public:
	int x;
	int y;
	int id;

	Car(int x,int y,int id)
	{
		this->x=x;
		this->y=y;
		this->id=id;
	}

	int distFromOrigin()
	{
		return x*x+y*y;//we have not taken square root because we are not interested in exact dist it is relative dist, to be noted
	}
};

class CarCompare
{
public:
	bool operator()(Car a,Car b)
	{
		return a.distFromOrigin()>b.distFromOrigin();//beacause it should return true for minHeap -> to swap a and b
		// here it will return true and then a and b will be swaped and we will have minimum at first or at top
	}
};

int main(int argc, char const *argv[])
{
	int x[10]={4,5,1,98,-7,35,0,62,4,0};
	int y[10]={1,0,1,4,58,69,23,0,12,1};
	int k=3;

	priority_queue<Car,vector<Car>,CarCompare> pq;//here we are using functor -> CarCompare to compare userdefined datatype
	for(int i=0;i<10;i++)
	{
		Car c(x[i],y[i],i);
		pq.push(c);
	}

	while(!pq.empty() && k>0)
	{
		Car entry=pq.top();
		cout<<"ID : "<<entry.id<<"  and  Location : ("<<entry.x<<", "<<entry.y<<")"<<endl;
		pq.pop();
		k--;
	}
	return 0;
}