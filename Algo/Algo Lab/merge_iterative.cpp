#include <bits/stdc++.h>
using namespace std;

void merge(int ar[],int l,int mid,int r)
{
	int k,i,j;
	int nl=mid-l+1;
	int nr=r-mid;
	int lf[nl],rt[nr];// temporary left array and right array
	for(i=0;i<nl;i++) lf[i]=ar[i+l];
	for(j=0;j<nr;j++) rt[j]=ar[mid+1+j];
	i=0,j=0;
	k=l;
	while(i<nl&&j<nr)//Merging left and right arrays
	{
		if(lf[i]<=rt[j])
		{
			ar[k]=lf[i];
			i++;
		}
		else
		{
			ar[k]=rt[j];
			j++;
		}
		k++;
	}
	while(i<nl)
	{
		ar[k]=lf[i];
		i++;
		k++;
	}
	while(j<nr)
	{
		ar[k]=rt[j];
		j++;
		k++;
	}


}
int main()
{
	int i,j;
	int n;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++) cin>>a[i];
	cout<<"Unsorted array\n";
	for(i=0;i<n;i++) cout<<a[i]<<" ";
	cout<<endl;
	for(i=1;i<=n-1;i=2*i)
	{
		for(j=0;j<n-1;j+=2*i)
		{
			int mid=min(i+j-1,n-1);
			int rht=min(j+2*i-1,n-1);
			merge(a,j,mid,rht);
		}
	}
	cout<<"Sorted Array\n";
	for(i=0;i<10;i++) cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
//Merge sort is a divide and Conquer Algorithm. It divides it into 2 halves , calls itself for the 2 halves and then merges the two halves.
//Time Complexity is same as recurisve technique O(nlogn).It divides the arrays into two halves and takes linear time to merge them.
//Modifications : Errors on accessing correct indexes value at required point of time when creating left right array
//Space Complexity:The recursive technique takes more space than normal iterative technique as it uses the function call stack to store intermediate values.But, the iterative technique does it through iterations.
//The Iterative merge sort doesn't require explicit auxillary stack.