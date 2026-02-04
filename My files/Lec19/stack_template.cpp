#include <iostream>
#include <vector>
using namespace std;
 
template<typename datatype>
class stack{
private:
	vector<datatype> v;
public:
	void push(datatype data){
		v.push_back(data);
	}
	datatype top(){
		datatype data=v[v.size()-1];
		return data;
	}
	datatype pop()
	{
		datatype data=v[v.size()-1];
		v.pop_back();
		return data;
	}
};
 
int main() {
	// your code goes here
	stack<string> st;
	st.push("mehar");
	st.push("lamba");
	st.push("kumar");
	st.push("sundaram");
	st.push("kunal");
	cout<<st.top()<<endl;
	cout<<st.pop()<<endl;
	cout<<st.pop()<<endl;
	cout<<st.pop()<<endl;
	cout<<st.pop()<<endl;
	cout<<st.pop()<<endl;
	cout<<st.pop()<<endl;
	return 0;
}