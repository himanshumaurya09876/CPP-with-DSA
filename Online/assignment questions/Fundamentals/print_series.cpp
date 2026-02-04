#include<iostream>
using namespace std;
int main() {
    int i=1,j=1,n1,n2,t;
    cin>>n1>>n2;
    while(i<=n1)
    {
        t=(3*j+2);
        if(t % n2 != 0)
        {
            cout<<t<<endl;
            i++;
        }
        j++;
    }
	return 0;
}