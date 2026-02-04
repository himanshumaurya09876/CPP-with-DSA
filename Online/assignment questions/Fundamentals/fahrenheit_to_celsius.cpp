#include<iostream>
using namespace std;
int main() {
    int fmin,fmax,step;
    cin>>fmin>>fmax>>step;
    while(fmin<=fmax)
    {
        int c;
        c=5*(fmin-32)/9;
        cout<<fmin<<" "<<c<<endl;
        fmin=fmin+step;
    }
	return 0;
}