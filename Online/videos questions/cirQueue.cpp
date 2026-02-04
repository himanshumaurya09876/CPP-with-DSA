#include <iostream>
using namespace std;

template<typename T>
class Queue
{
private:
	T *arr;
	int front;
	int rear;
	int maxsize;
	int currsize;
public:
	Queue(int defsize=5)
	{
		maxsize=defsize;
		currsize=0;
		front=0;
		rear=maxsize-1;
		arr=new T[maxsize];
	}

	bool isFull()
	{
		return currsize==maxsize;
	}

	bool isEmpty()
	{
		return currsize==0;
	}

	void push(T data)
	{
		if(!isFull())
		{
			rear=(rear+1)%maxsize;
			arr[rear]=data;
			currsize++;
		}
	}

	void pop()
	{
		if(!isEmpty())
		{
			front=(front+1)%maxsize;
			currsize--;
		}
	}

	T frontEle()
	{
		T var;
		if(!isEmpty())
		{
			return arr[front];
		}
		return var;
	}
};

int main(int argc, char const *argv[])
{
	Queue<string> q;
	q.push("Ashish");
	q.push("Amit");
	q.push("Himanshu");
	q.push("Maurya");
	q.push("a");
	q.push("b");
	q.push("c");

	while(!q.isEmpty())
	{
		cout<<q.frontEle()<<endl;
		q.pop();
	}
	return 0;
}