#include <bits/stdc++.h>
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
map<ll,ll> m;
map<pair<ll,ll>,ll> don;
int main()
{
	ll i,j,sum=0;

    ll n,w;
    cin>>n>>w;
    
    ll a[n];
    ll b[n];
    vector < pair< double,pair<ll,ll> > >v;
    for(i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        v.pb({a[i]/(b[i]*1.0),{a[i],b[i]}});
    }

    sort(v.begin(), v.end());

    ll cw=0;
    double ans=0;

    for(i=v.size()-1;i>=0;i--)
    {
        if(cw+v[i].second.second<=w)
        {
            ans+=v[i].second.first;
            cw=cw+v[i].second.second;
        }
        else
        {

            ll remain=w-cw;
            ans+=( v[i].second.first * ((double)remain/(double)v[i].second.second));
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}