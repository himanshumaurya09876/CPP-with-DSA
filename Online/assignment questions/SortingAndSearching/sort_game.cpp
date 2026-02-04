//SORT GAME
// Sanju needs your help! He gets a list of employees with their salary. The maximum salary is 100.

// Sanju is supposed to arrange the list in such a manner that the list is sorted in decreasing order of salary. And if two employees have the same salary, they should be arranged in lexicographical manner such that the list contains only names of those employees having salary greater than or equal to a given number x.

// Help Sanju prepare the same!

// Input Format:
// On the first line of the standard input, there is an integer x. The next line contans integer N, denoting the number of employees. N lines follow, which contain a string and an integer, denoting the name of the employee and his salary.

// Constraints:
// 1 <= N <= 10^5 1 <= | Length of the name | <= 100 1 <= x, salary <= 100

// Output Format
// You must print the required list.

// Sample Input
// 79
// 4
// Eve 78
// Bob 99
// Suzy 86
// Alice 86
// Sample Output
// Bob 99
// Alice 86
// Suzy 86


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
                if(name[j-1][k]!='\0' && tag=='e')
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
    int sal[100000];
    string name[100000];
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