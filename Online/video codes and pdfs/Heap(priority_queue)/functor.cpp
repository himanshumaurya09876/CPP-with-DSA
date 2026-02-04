#include <iostream>
using namespace std;

//functional objects are called functors
//these are objects which seems to be acting like a function
class functor
{
public:
	//let us see how to overload () operator
	void operator()(string name,int age)
	{
		if(age<18)
		{
			cout<<"Hi! "<<name<<", you are a child"<<endl;
		}
		else if(age<35)
		{
			cout<<"Hi! "<<name<<", you are young"<<endl;
		}
		else if(age<50)
		{
			cout<<"Hi! "<<name<<", you are old"<<endl;
		}
		else
		{
			cout<<"Hi! "<<name<<", you are too old"<<endl;
		}
	}
};

int main(int argc, char const *argv[])
{
	string name;
	int age;
	cin>>name>>age;
	functor f;
	f(name,age);//it seems to be a function call but it is actually an object
	return 0;
}