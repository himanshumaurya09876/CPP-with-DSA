/*
#include<iostream>

using namespace std;

int main()
{
    int t;
    cout<<"Enter t: ";
    cin>>t;
    while(t>0)
    {
        int n,i,j,s=0,maxsize=0;
        int A[1000];
        cin>>n;
        for(i=0; i<n; i++)
        {
            cin>>A[i];
        }
        for(int i=0; i<n; i++)
        {
            s=1;
            for(j=i; j>0; j--)
            {
                if(A[j-1]<A[j])
                    s++;
                else
                    break;
            }
            for(j=i; j<n-1; j++)
            {
                if(A[j]>A[j+1])
                    s++;
                else
                    break;
            }
            if(maxsize<s)
            {
                maxsize=s;
            }
        }
        cout<<maxsize<<endl;
        t--;
    }
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    while(n>0)
    {
        int a,b,c=0,root;
        cin>>a>>b;
        if(a<2)
            a=2;
        for(int i=a;i<=b;i++)
        {
            int j=0;
            root=sqrt(i);
            for(j=2;j<=root;j++)
            {
                if(i%j==0)
                {
                    break;
                }
            }
            if(j>root)
            {
                c++;
            }
        }
        cout<<c<<endl;
        n--;
    }
	return 0;
}
*/
/*
#include<iostream>
using namespace std;
int main() {
    int n,m,x,i,j;
    cin>>n>>m;
    int A[30][30];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>A[i][j];
        }
    }
    cin>>x;
    for(j=0;j<m;j++)
    {
        if(x>=A[0][j] && x<=A[n-1][j])
        {
            for(i=0;i<n;i++)
            {
                if(x==A[i][j])
                {
                    cout<<"1";
                    return 0;
                }
            }
        }
    }
    cout<<"0";
	return 0;
}
*/
/*
#include<iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t>0)
    {
        int a,b,count=0;
        cin>>a>>b;
        for(int i=a;i<=b;i++)
        {
            int j=i;
            while(j!=0)
            {
                if(j&1)
                {
                    count++;
                }
                j>>=1;
            }
        }
        cout<<count<<endl;
        t--;
    }
	return 0;
}
*/
/*
#include<iostream>
using namespace std;
int main() {
    int n,arr[100000],num[2];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k=0;
    for(int i=0;i<n;i++)
    {
        char flag='y';
        for(int j=0;j<n;j++)
        {
            if(!(arr[i]^arr[j]) && i!=j)
            {
                flag='n';
                break;
            }
        }
        if(flag=='y')
        {
            num[k]=arr[i];
            k++;
            if(k==2)
            {
                break;
            }
        }
    }
    cout<<num[0]<<" "<<num[1];
	return 0;
}
*/
/*
#include<iostream>
using namespace std;

void insertionSort(int arr[100],int n)
{
	for(int i=1;i<n;i++)
    {
		for(int j=i;j>0;j--)
        {
            if(arr[j]<arr[j-1])
            {
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
}

int main() {
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    insertionSort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
	return 0;
}
*/
/*
#include<iostream>
using namespace std;
int main() {
	int n,arr[100];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int low=0,mid=0,high=n-1;
	while(mid<=high)
	{
		int temp;
		if(arr[mid]==2)
		{
			temp=arr[mid];
			arr[mid]=arr[high];
			arr[high]=temp;
			high--;
		}
		else if(arr[mid]==0)
		{
			temp=arr[mid];
			arr[mid]=arr[low];
			arr[low]=temp;
			mid++;
			low++;
		}
		else
			mid++;
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
	return 0;
}
*/
/*
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s[1000];
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>s[i];
    }
    for(int i=1; i<n; i++)
    {
        for(int j=i; j>0; j--)
        {
            int k=0,l1=s[j].length(),l2=s[j-1].length();
            char tag='n';
            while(k<l1 && k<l2)
            {
                if(int(s[j-1][k])>int(s[j][k]))
                {
                    string temp=s[j];
                    s[j]=s[j-1];
                    s[j-1]=temp;
                    tag='n';
                    break;
                }
                else if(int(s[j-1][k])<int(s[j][k]))
                {
                    tag='n';
                    break;
                }
                else
                {
                    tag='e';
                }
                k++;
            }
            if(s[j][k]!='\0' && tag=='e')
            {
                string temp=s[j];
                s[j]=s[j-1];
                s[j-1]=temp;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<s[i]<<endl;
    }
    return 0;
}
*/
/*
#include<iostream>
#include<string>

using namespace std;

void insertionSort(int arr[100000],int n,string name[100000])
{
	for(int i=1;i<n;i++)
    {
		for(int j=i;j>0;j--)
        {
            if(arr[j]>arr[j-1])
            {
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
                string temp1=name[j];
                name[j]=name[j-1];
                name[j-1]=temp1;
            }
            else if(arr[j]==arr[j-1])
            {
                int k=0,l1=name[j].length(),l2=name[j-1].length();
                char tag='n';
                while(k<l1 && k<l2)
                {
                    if(int(name[j-1][k])>int(name[j][k]))
                    {
                        string temp2=name[j];
                        name[j]=name[j-1];
                        name[j-1]=temp2;
                        int temp3=arr[j];
                        arr[j]=arr[j-1];
                        arr[j-1]=temp3;
                        tag='n';
                        break;
                    }
                    else if(int(name[j-1][k])<int(name[j][k]))
                    {
                        tag='n';
                        break;
                    }
                    else
                    {
                        tag='e';
                    }
                    k++;
                }
                if(name[j][k]!='\0' && tag=='e')
                {
                    string temp4=name[j];
                    name[j]=name[j-1];
                    name[j-1]=temp4;
                    int temp5=arr[j];
                    arr[j]=arr[j-1];
                    arr[j-1]=temp5;
                }
            }
        }
    }
}

int main() {
    int sal[100];
    string name[100];
    int n,x;
    cin>>x>>n;
    for(int i=0;i<n;i++)
    {
        cin>>name[i]>>sal[i];
    }
    insertionSort(sal,n,name);
    for(int i=0;i<n;i++)
    {
        if(sal[i]>=x)
        {
            cout<<name[i]<<" "<<sal[i]<<endl;
        }
    }
	return 0;
}
*/
#include<iostream>
using namespace std;

int binarysearch(int arr[],int first,int last,int num)
{
    while(first<=last)
    {
        int mid=(first+last)/2;
        if(num>arr[mid])
        {
            first=mid+1;
        }
        else if(num<arr[mid])
        {
            last=mid-1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main() {
    int arr[100],n,num,i;
    cin>>n;
    char flag='n';
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>num;
    i=-1;
    do
    {
        i++;
        if(arr[i]==num)
        {
            cout<<i;
            flag='f';
            break;
        }
    }while(arr[i]<arr[i+1]);
    if(flag!='f')
    {
        int res=binarysearch(arr,i+1,n-1,num);
        cout<<res;
    }
    return 0;
}