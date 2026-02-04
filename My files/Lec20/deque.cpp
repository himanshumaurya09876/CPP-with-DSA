//deque->double ended queue

#include <iostream>
#include <deque>
using namespace std;

int main(int argc, char const *argv[])
{
	deque<int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);
	d.push_back(5);
	d.push_front(6);
	d.push_front(7);
	d.push_front(8);
	d.push_front(9);

	for(auto it:d)
	{
		cout<<it<<" ";
	}
	cout<<endl;

	cout<<d.front()<<endl;
	d.pop_front();
	cout<<d.front()<<endl;
	d.pop_front();
	cout<<d.front()<<endl;
	cout<<d.back()<<endl;
	d.pop_back();
	cout<<d.back()<<endl;
	d.pop_back();
	cout<<d.back()<<endl;
	d.pop_back();
	cout<<d.back()<<endl;
	d.pop_back();
	cout<<d.back()<<endl;
	d.pop_back();
	cout<<d.back()<<endl;
	d.pop_back();
	cout<<d.back()<<endl;
	d.pop_back();
	cout<<d.back()<<endl;
	d.pop_back();
	cout<<d.back()<<endl;
	d.pop_back();
	cout<<d.back()<<endl;
	return 0;
}