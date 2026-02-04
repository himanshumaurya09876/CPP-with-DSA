//inbuilt stack
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
 int main(int argc, char const *argv[])
 {
 	stack<pair<int, string> > st;//stack<pair<int, string>> st ->it will not work because of >>
 	pair<int, string> p;
 	p=make_pair(1,"Amit");
 	st.push(p);
 	p=make_pair(2,"Ashish");
 	st.push(p);
 	p=make_pair(3,"Himanshu");
 	st.push(p);
 	p=make_pair(4,"Puchchi");
 	st.push(p);
 	p=make_pair(5,"Sumit");
 	st.push(p);
 	cout<<st.top().first<<" "<<st.top().second<<endl;
 	st.pop();
 	cout<<st.top().first<<" "<<st.top().second<<endl;
 	st.pop();
 	cout<<st.top().first<<" "<<st.top().second<<endl;
 	st.pop();
 	cout<<st.top().first<<" "<<st.top().second<<endl;
 	st.pop();
 	cout<<st.top().first<<" "<<st.top().second<<endl;
 	st.pop();
 	cout<<st.top().first<<" "<<st.top().second<<endl;//it will give you an error->segmentation fault or permission denied
 	st.pop();
 	return 0;
 }