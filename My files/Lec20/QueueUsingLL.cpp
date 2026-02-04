#include <iostream>
using namespace std;

class queue
{
private:
	class node
	{
	public:
		int data;
		node* next;

		node(int d)
		{
			data=d;
			next=NULL;
		}
	};
	node* front1;
	node* rear;
public:
	queue()
	{
		front1=NULL;
		rear=NULL;
	}

	bool isempty()
	{
		if(front1==NULL)
		{
			return true;
		}
		return false;
	}

	void push(int data)
	{
		if(isempty())
		{
			front1=new node(data);
			rear=front1;
		}
		else
		{
			rear->next=new node(data);
			rear=rear->next;
		}
	}

	void pop()
	{
		if(isempty())
		{
			cout<<"Queue underflow"<<endl;
			return;
		}
		node* temp=front1->next;
		delete front1;
		front1=temp;
	}

	int front()
	{
		if(isempty())
		{
			cout<<"Queue underflow"<<endl;
			return -1;
		}
		return front1->data;
	}
};

int main(int argc, char const *argv[])
{
	queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	cout<<q.front()<<endl;
	q.pop();
	cout<<q.front()<<endl;
	q.pop();
	cout<<q.front()<<endl;
	q.pop();
	cout<<q.front()<<endl;
	q.pop();
	cout<<q.front()<<endl;
	q.pop();
	cout<<q.front()<<endl;
	return 0;
}