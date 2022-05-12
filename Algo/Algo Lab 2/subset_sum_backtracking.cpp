#include "iostream"
#include "vector"
#include "math.h"
using namespace std;
#define int long long
#define vi vector<int>
#define sz(v) (int)(v.size())
#define pb push_back
#define fk 998244353
#define F first
#define S second
double pi = acos(-1);
const long long inf = 1e18;
int power(int x,int n)
{
    if(n==0)
        return 1;
    if(n%2)
        return (x*power(x,n-1));
    return power(x*x,n/2);
}
int top(int x,int y)
{
    if(x%y)
        return x/y + 1;
    else
        return x/y;
}
int dp[10][100];
void solve()
{
    int n,sum;
    cin>>n>>sum;
    vi a(n);
    for(auto &i:a)
        cin>>i;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(not i)
                dp[i][j]=(a[i]==j);
            else if(not j)
                dp[i][j]=1;
            else if(a[i]<=j)
                dp[i][j]=dp[i-1][j]|dp[i-1][j-a[i]];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    if(not dp[n-1][sum])
        cout<<"No subset found";
    else
    {
        int i=n-1,j=sum,sum1=0;
        vi v;
        while(sum1!=sum)
        {
            if(dp[i][j]==dp[i-1][j])
            {
                i--;
                continue;
            }
            else
            {
                v.pb(a[i]);
                j-=a[i];
                sum1+=a[i];
                i--;
            }
        }
        for(auto i:v)
            cout<<i<<" ";
    }
}
signed main()
{
    int t=1;
        // cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
    return 0;
}