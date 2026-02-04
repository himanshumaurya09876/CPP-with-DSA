#include <iostream>
#include <string>

using namespace std;

void toh(int n,string src,string helper,string dest)
{
    if(n==0)
    {
        return;
    }
    toh(n-1,src,dest,helper);
    cout<<"Disk no.-"<<n<<" move from "<<src<<" to "<<dest<<endl;
    toh(n-1,helper,src,dest);
}

int main()
{
    int n;
    cout<<"Enter number of disks: ";
    cin>>n;
    toh(n,"A","B","C");
    return 0;
}
