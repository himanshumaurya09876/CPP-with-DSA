#include <iostream>

using namespace std;

int main()
{
    int r,c;
    cout<<"Enter the no. of rows and columns: ";
    cin>>r>>c;
    int **arr=new int*[r];
    for(int i=0;i<r;i++)
    {
        arr[i]=new int[c];
    }
    cout<<"Enter the data"<<endl;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"Printed in different order: "<<endl;
    for(int i=0;i<r;i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<c;j++)
            {
                cout<<arr[i][j]<<" ";
            }
        }
        else
        {
            for(int j=c-1;j>=0;j--)
            {
                cout<<arr[i][j]<<" ";
            }
        }
    }
    ///delete the memory
    for(int i=0;i<r;i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
