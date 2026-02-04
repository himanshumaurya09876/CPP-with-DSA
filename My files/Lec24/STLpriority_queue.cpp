//priority_queue <-> heap
#include <iostream>
#include <queue>//header for priority_queue or heap
using namespace std;

int main(){
	priority_queue<int, vector<int>, greater<int> >pqmin;//for min heap
	priority_queue<int > pqmax;//for max heap

	//for min heap
	pqmin.push(5);
	pqmin.push(50);
	pqmin.push(45);
	pqmin.push(52);
	pqmin.push(95);
	pqmin.push(01);
	pqmin.push(55);
	pqmin.push(89);

	cout<<pqmin.top()<<endl;
	pqmin.pop();
	cout<<pqmin.top()<<endl;
	pqmin.pop();
	cout<<pqmin.top()<<endl;
	pqmin.pop();
	cout<<pqmin.top()<<endl;
	pqmin.pop();
	cout<<pqmin.top()<<endl;
	pqmin.pop();
	cout<<pqmin.top()<<endl;
	pqmin.pop();
	cout<<pqmin.top()<<endl;
	pqmin.pop();
	cout<<pqmin.top()<<endl;
	pqmin.pop();
	if(pqmin.empty())
	{
		cout<<"Empty"<<endl;
	}
	else
	{
		cout<<"Non empty"<<endl;
	}

	cout<<pqmin.top()<<endl;
	pqmin.pop();

	if(pqmin.empty())
	{
		cout<<"Empty"<<endl;
	}
	else
	{
		cout<<"Non empty"<<endl;
	}
	cout<<"====================================================="<<endl;
	//for max heap
	pqmax.push(5);
	pqmax.push(50);
	pqmax.push(45);
	pqmax.push(52);
	pqmax.push(95);
	pqmax.push(01);
	pqmax.push(55);
	pqmax.push(89);

	cout<<pqmax.top()<<endl;
	pqmax.pop();
	cout<<pqmax.top()<<endl;
	pqmax.pop();
	cout<<pqmax.top()<<endl;
	pqmax.pop();
	cout<<pqmax.top()<<endl;
	pqmax.pop();
	cout<<pqmax.top()<<endl;
	if(pqmax.empty())
	{
		cout<<"Empty"<<endl;
	}
	else
	{
		cout<<"Non empty"<<endl;
	}

	pqmax.pop();
	cout<<pqmax.top()<<endl;
	pqmax.pop();
	cout<<pqmax.top()<<endl;
	pqmax.pop();
	cout<<pqmax.top()<<endl;
	pqmax.pop();
	if(pqmax.empty())
	{
		cout<<"Empty"<<endl;
	}
	else
	{
		cout<<"Non empty"<<endl;
	}

	cout<<pqmax.top()<<endl;
	pqmax.pop();

	if(pqmax.empty())
	{
		cout<<"Empty"<<endl;
	}
	else
	{
		cout<<"Non empty"<<endl;
	}

	return 0;
}