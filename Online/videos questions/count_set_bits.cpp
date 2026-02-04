#include <iostream>
///in O(no. of bits)
using namespace std;

int countSetBits(int n)
{
    int count=0;
    while(n>0)
    {
        count++;
        n=n&(n-1);
    }
    return count;
}

int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"Total set bits are: "<<countSetBits(n);
    return 0;
}
