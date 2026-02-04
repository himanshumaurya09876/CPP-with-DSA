#include <iostream>

using namespace std;

int main()
{
    int n,c=0,i,j,k;
    cout<<"Enter the size of list: ";
    cin>>n;
    int num[100];
    cout<<"Enter the numbers in the list:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>num[i];
    }
    cout<<"The elements are: ";
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(num[j]<num[i])
                break;
        }
        for(k=i+1;k<n;k++)
        {
            if(num[k]>num[i])
                break;
        }
        if(j==i && k==n)
        {
            cout<<num[i]<<" ";
            c++;
        }
    }
    cout<<"\nFinal result is: "<<c<<endl;
    return 0;
}
