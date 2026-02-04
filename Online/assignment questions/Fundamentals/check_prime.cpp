#include<iostream>
using namespace std;
int main() {
    int n,i=2;
    cin>>n;
    while(i*i<=n)
    {
        if(n%i==0)
        {
            cout<<"Not Prime";
            break;
        }
        i++;
    }
    if(i*i>n)
        cout<<"Prime";
	return 0;
}