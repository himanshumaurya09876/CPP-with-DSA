#include <iostream>
#include <vector>
using namespace std;

class Stack
{
private:
	vector<int> v;
	int curr_min;
public:
	Stack()
	{
		curr_min=INT_MAX;
	}
	void insert(int data)
	{
		if(data<curr_min)
		{
			v.push_back(2*data-curr_min);
			curr_min=data;
		}
		else
		{
			v.push_back(data);
		}
	}
	void pop()
	{
		if(v[v.size()-1]<curr_min)
		{
			curr_min=2*curr_min-v[v.size()-1];
			v.pop_back();
		}
		else
		{
			v.pop_back();
		}
	}
	int getmin()
	{
		return curr_min;
	}
};

int main(int argc, char const *argv[])
{
	Stack s1;
	s1.insert(5);
	s1.insert(3);
	s1.insert(7);
	s1.insert(2);
	s1.insert(9);
	s1.insert(1);
	s1.insert(0);

	cout<<s1.getmin()<<endl;
	s1.pop();
	cout<<s1.getmin()<<endl;
	s1.pop();
	cout<<s1.getmin()<<endl;
	s1.pop();
	cout<<s1.getmin()<<endl;
	s1.pop();
	cout<<s1.getmin()<<endl;
	s1.pop();
	cout<<s1.getmin()<<endl;
	s1.pop();
	cout<<s1.getmin()<<endl;
	s1.pop();
	cout<<s1.getmin()<<endl;
	s1.pop();
	return 0;
}