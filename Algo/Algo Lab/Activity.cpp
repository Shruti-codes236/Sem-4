#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define M (ll)1000000007
#define pi 3.1415926536
#define all(a) a.begin(),a.end()
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define flp(i,x,y) for( int i=x;i<y;i++)
#define flpl(i,x,y) for(long long int i=x;i<y;i++)
#define forp(i,x,y) for(long long int i=x;i*i<=y;i++)
#define ll long long int 	
#define MOD (long long int)(998244353)
#define pb push_back
#define lop(i,n) for(ll i=0;i<n;i++)
#define lop1(i,n) for(ll i=1;i<=n;i++)
#define lopr(i,n) for(ll i=n-1;i>=0;i--)
#define fr         first
#define sc         second
#define pii        pair<int,int>
#define len(s)     s.length()
#define meme(a,val) memset(a,val,sizeof(a));
#define sz(v) v.size()
#define endl "\n" 
#define inf 1e18
#define pai pair<int,int>
#define itr vector<int> :: iterator
int main()
{
	int n,i,st,en;
	cin>>n;
	vector <pair<pair<int,int>,int>> v;
	for(i=0;i<n;i++)
	{
		cin>>st>>en;
		v.push_back({{en,st},i});//storing ending time first in pair
	}
	sort(v.begin(),v.end());//sorting according to ending time
	int ans=0,tm=0;
	for(i=0;i<n;i++)
	{
		if(v[i].fr.sc>=tm)
		{
			ans++;
			tm=v[i].fr.fr;
			cout<<"Activity "<<v[i].sc+1<<" is selected "<<", current time is "<<tm<<endl;

		}
	}
	cout<<"Maximum number of non-conflicting activities= "<<ans<<endl;
return 0;
}