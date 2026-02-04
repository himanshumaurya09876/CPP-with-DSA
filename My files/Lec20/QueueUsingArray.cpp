#include <iostream>
using namespace std;

class Queue
{
private:
	int front;
	int rear;
	int size;
	int *arr;
public:
	Queue(int s=10)
	{
		front=0;
		rear=-1;
		size=s;
		arr=new int[size]; 
	}

	bool isEmpty()
	{
		if(front>rear)
		{
			return true;
		}
		return false;
	}

	bool isFull()
	{
		if(rear==size-1)
		{
			return true;
		}
		return false;
	}

	int Front()
	{
		if(isEmpty())
		{
			cout<<"Queue Underflow"<<endl;
			return -1;
		}
		return arr[front];
	}

	int Rear()
	{
		if(isEmpty())
		{
			cout<<"Queue Underflow"<<endl;
			return -1;
		}
		return arr[rear];
	}

	void Dequeue()
	{
		if(isEmpty())
		{
			cout<<"Queue Underflow"<<endl;
			return;
		}
		for(int i=front;i<rear;i++)
		{
			arr[i]=arr[i+1];
		}
		rear--;
	}

	void Enqueue(int data)
	{
		if(isFull())
		{
			cout<<"Queue Overflow"<<endl;
			return;
		}
		arr[++rear]=data;
	}
};

int main(int argc, char const *argv[])
{
	Queue q(5);
	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);
	q.Enqueue(4);
	q.Enqueue(5);
	q.Enqueue(6);

	cout<<q.Front()<<endl;
	q.Dequeue();
	cout<<q.Front()<<endl;
	q.Dequeue();
	cout<<q.Front()<<endl;
	q.Dequeue();
	cout<<q.Front()<<endl;
	q.Dequeue();
	cout<<q.Front()<<endl;
	q.Dequeue();
	cout<<q.Front()<<endl;
	q.Dequeue();
	return 0;
}