//stack

#include <iostream>
#include <vector>
using namespace std;

class stack
{
private:
	vector<int> v;
public:
	void push(int data)
	{
		v.push_back(data);
	}

	int pop()
	{
		if(v.empty())
		{
			cout<<"Stack underflow"<<endl;
			return -1;
		}
		int data=top();
		v.pop_back();
		return data;
	}

	int top()
	{
		if(v.empty())
		{
			cout<<"Stack underflow"<<endl;
			return -1;
		}
		return v[v.size()-1];
	}
};

int main(int argc, char const *argv[])
{
	stack st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	cout<<st.top()<<endl;
	cout<<st.pop()<<endl;
	cout<<st.pop()<<endl;
	cout<<st.pop()<<endl;
	cout<<st.pop()<<endl;
	cout<<st.pop()<<endl;

	return 0;
}