#include <iostream>

using namespace std;

int checkUnique(int arr[],int n)
{
    int res[64]={0},k=0;
    for(int i=0;i<n;i++)
    {
        int num=arr[i];
        k=0;
        while(num>0)
        {
            res[k]=(num&1);
            k++;
            num>>=1;
        }
    }
    int p=1;
    int num=0;
    for(int i=0;i<64;i++)
    {
        res[i]=res[i]%3;
        num+=res[i]*p;
        p*=2;
    }
    return num;
}

int main()
{
    int arr[100],n;
    cout<<"Enter how many numbers you want to enter: ";
    cin>>n;
    cout<<"Enter nos.: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Unique number is: "<<checkUnique(arr,n);
    return 0;
}
