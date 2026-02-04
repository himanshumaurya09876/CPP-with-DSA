/*#include <iostream>

using namespace std;

int main()
{
    bool var=5;
    int i=5;
    int j=++i++;
    cout<<j;
    //cout << var << endl;
    return 0;
}
*/
/*#include<iostream>
using namespace std;
int main() {
    int n,r=0;
    cin>>n;
    while(n>0)
    {
        r=r*10+n%10;
        n=n/10;
    }
    cout<<r;
	return 0;
}*/
/*#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
    int n,i,l=0,k;
    cin>>n;
    for(i=0; i<n; i++)
    {
        char arr[17];
        int ans=0;
        fflush(stdin);
        gets(arr);
        l=strlen(arr);
        for(int j=0; j<l; j++)
        {
            k=l-1-j;
            if(arr[j]=='1')
            {
                ans=ans+pow(2,k);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int main() {
    int n,i,l=0,ans=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        char arr[17];
        cin>>arr[l];
        l++;
        while(arr[l]!='\n')
        {
            cin>>arr[l];
            l++;
        }
        for(int j=0;j<l;j++)
        {
            if(arr[j]=='1')
                ans=ans+pow(2,l-1-j);
        }
        cout<<ans<<endl;
    }
	return 0;
}

#include<iostream>
using namespace std;
int main() {
    int n,i;
    char tag1='y',tag2='y';
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    i=0;
    while(i<n)
    {
        tag1=tag2='y';
        for(int j=1;j<=i;j++)
        {
            if(arr[j]>=arr[j-1])
            {
               tag1='n';
               break;
            }
        }
        for(int j=i+1;j<n;j++)
        {
            if(arr[j+1]<=arr[j])
            {
               tag2='n';
               break;
            }
        }
        if(tag1=='y' && tag2=='y')
        {
            cout<<"true";
            break;
        }
        i++;
    }
    if(i>=n)
        cout<<"false";
	return 0;
}
#include<iostream>
using namespace std;
int main() {
    char ch;
    cin>>ch;
    while(ch !='X' && ch !='x')
    {
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%')
        {
            int n1,n2;
            cin>>n1>>n2;
            if(ch=='+')
                cout<<n1+n2<<endl;
            else if(ch=='-')
                cout<<n1-n2<<endl;
            else if(ch=='*')
                cout<<n1*n2<<endl;
            else if(ch=='/')
                cout<<n1/n2<<endl;
            else
                cout<<n1%n2<<endl;
        }
        else
            cout<<"Invalid operation. Try again."<<endl;
        cin>>ch;
    }
	return 0;
}
#include<iostream>
using namespace std;
int main() {
    int p,b,h;
    cin>>p;
    if(p%2==0)
    {
        b=(p*p-4)/4;
        h=(p*p+4)/4;
    }
    else
    {
        b=(p*p-1)/2;
        h=(p*p+1)/2;
    }
    if(p>0 && b>0 && h>0)
        cout<<b<<" "<<h;
    else
        cout<<"-1";
	return 0;
}
#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if((i==1 && j>1 && j<=n/2) || (1<i && i<=n/2 && (j>n/2+1 || (j>1 && j<=n/2))) || (i>n/2+1 && i<n && (j<=n/2 || (j>n/2+1 && j<n))) || (i==n && j>n/2+1 && j<n))
                cout<<" ";
            else
                cout<<"*";
        }
        cout<<endl;
    }
	return 0;
}

#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int row=1;
    int nst=n/2+1;
    int nsp=-1;
    while(row<=n)
    {
        int cst=1;
        int csp=1;
        while(cst<=nst)
        {
            cout<<"* ";
            cst++;
        }
        while(csp<=nsp)
        {
            cout<<"  ";
            csp++;
        }
        cst=1;
        if(row==1 || row==n)
            cst=2;
        while(cst<=nst)
        {
            cout<<"* ";
            cst++;
        }
        cout<<endl;
        if(row<=n/2)
        {
            nst--;
            nsp+=2;
        }
        else
        {
            nst++;
            nsp-=2;
        }
        row++;
    }
	return 0;
}

#include<iostream>
using namespace std;
void sort(int arr[],int n)
{
    int min;
    for(int i=0;i<n;i++)
    {
        min=arr[i];
        for(int j=i;j<n;j++)
        {
            if(min>arr[j])
            {
                min=arr[j];
                arr[j]=arr[i];
                arr[i]=min;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void fun(int arr[],int n,int t)
{
    int *l=&arr[0],*r=&arr[n-1];
    while(*l<*r)
    {
        if(*l + *r==t)
        {
            cout<<*l<<" and "<<*r<<endl;
            l++;
            r--;
        }
        else if(*l + *r <t)
        {
            l++;
        }
        else
        {
            r--;
        }
    }
}
int main() {
    int n,t;
    int arr[1000];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cin>>t;
    sort(arr,n);
    fun(arr,n,t);
	return 0;
}
*/
#include<iostream>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t>0)
	{
		int n,i,j;
		int A[1000],sum=0;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>A[i];
		}
		for(i=0;i<n;i++)
		{
			int res=A[i];
			for(j=i+1;j!=i;j++)
			{
                if(j==n)
                    j=0;
                res=res+A[j];
				if(sum<res)
					sum=res;
                if(j==n-1)
                    j=-1;
			}
		}
		cout<<sum<<endl;
		t--;
	}
	return 0;
}
