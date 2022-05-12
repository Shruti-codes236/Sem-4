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
		if(ar[j]<pv)
		{
			i++;
			swap(ar[i],ar[j]);
		}
	}
	swap(ar[i+1],ar[h]);
	return (i+1);
}
void quicksort(int ar[],int l,int h)
{
	if(l<h)
	{
		int p=partition(ar,l,h);
		quicksort(ar,l,p-1);
		quicksort(ar,p+1,h);
	}
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
	quicksort(ar,0,n-1);
	cout<<"Sorted array\n";
	for(i=0;i<n;i++) cout<<ar[i]<<" ";
		cout<<endl;
}