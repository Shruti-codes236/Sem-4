#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int partition(int ar[],int l,int h)
{
	int pv=ar[h];
	int i=l-1,j;
	for(j=l;j<h;j++)
	{
		if(ar[j]<=pv)
		{
			i++;
			swap(ar[i],ar[j]);
		}
	}
	swap(ar[i+1],ar[h]);
	return (i+1);
}
int main()
{
	int n;
	cin>>n;
	int ar[n],i;
	for(i=0;i<n;i++) cin>>ar[i];
		cout<<"Unsorted array\n";
	for(i=0;i<n;i++) cout<<ar[i]<<" ";
		cout<<endl;
	//quicksort(ar,0,n-1);
	int l=0;
	int h=n-1;
	int st[h-l+1];
	int top=-1;
	st[++top]=l; 
	st[++top]=h;
	while(top>=0)
	{
		h=st[top--];
		l=st[top--];
		int p=partition(ar,l,h);
		if(p-1>l)
		{
			st[++top]=l;
			st[++top]=p-1;
		}
		if(p+1<h)
		{
			st[++top]=p+1;
			st[++top]=h;
		}
	}
	cout<<"Sorted array\n";
	for(i=0;i<n;i++) cout<<ar[i]<<" ";
		cout<<endl;
}
//Time complexity 