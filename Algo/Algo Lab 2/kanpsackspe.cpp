Shaswat X1, [15.11.20 22:38]
#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int>  vi;
typedef vector<ll>  vl;
typedef vector<pii>  vpii;
typedef vector<pl>  vpl;
typedef vector<vi>  vvi;
typedef vector<vl>  vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
 uniform_int_distribution<int> uid(0,lim-1);
 return uid(rang);
}
int mpow(int base, int exp); 
void ipgraph(int n, int m);
void dfs(int u, int par);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];

vector <ll> SieveOfEratosthenes(ll n) 
  { 
      vector<ll> ans;
      bool prime[n+1]; 
      memset(prime, true, sizeof(prime)); 
    
      for (int p=2; p*p<=n; p++) 
      if (prime[p] == true) 
      for (int i=p*p; i<=n; i += p) 
      prime[i] = false; 
          
      for (int p=2; p<=n; p++) 
      if (prime[p]) 
      ans.push_back(p);
    return ans;
  }
bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true;
  
    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 
  
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
string lcs( string X, string Y, int m, int n ) 
{ 
   int L[m+1][n+1]; 
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (int i=0; i<=m; i++) 
   { 
     for (int j=0; j<=n; j++) 
     { 
       if (i == 0 || j == 0) 
         L[i][j] = 0; 
       else if (X[i-1] == Y[j-1]) 
         L[i][j] = L[i-1][j-1] + 1; 
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]); 
     } 
   } 
  
   // Following code is used to print LCS 
   int index = L[m][n]; 
  
   // Create a character array to store the lcs string 
   char lcs[index+1]; 
   lcs[index] = '\0'; // Set the terminating character 
  
   // Start from the right-most-bottom-most corner and 
   // one by one store characters in lcs[] 
   int i = m, j = n; 
   while (i > 0 && j > 0) 
   { 
      // If current character in X[] and Y are same, then 
      // current character is part of LCS 
      if (X[i-1] == Y[j-1]) 
      { 
          lcs[index-1] = X[i-1]; // Put current character in result 
          i--; j--; index--;     // reduce values of i, j and index 
      } 
  
      // If not same, then find the larger of two and 
      // go in the direction of larger value 
      else if (L[i-1][j] > L[i][j-1]) 
         i--; 
      else
         j--; 
   } 
  cout<<lcs<<endl;
   // Print the lcs
   
   string s=""; 
   while(lcs[i]!='\0'){
       s=s+lcs[i];
       i++;
   }
   return s;
} 
  

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int i,n,m,count=0;
    cin>>n>>m;
    string a,b,lc,a1,b1;
    cin>>a>>b;
    lc= lcs( a, b, m, n );
    fo(i,n){
        if(a[i]==lc[0]){
            a1+=lc[0];
            break;
        }
    }
    i++;
    while(count<lc.length()){
        if(a[i]==lc[count]){
            count++;
        }
        a1=a1+a[i];
        i++;
    }
    count=0;
    f

Shaswat X1, [15.11.20 22:38]
o(i,m){
        if(b[i]==lc[0]){
            b1+=lc[0];
            break;
        }
    }
    i++;
    while(count<lc.length()){
        if(b[i]==lc[count]){
            count++;
        }
        b1=b1+b[i];
        i++;
    }
    int score=4*lc.length()-a1.length()-b1.length();
    cout<<a1<<" "<<b1<<" "<<lc<<endl;
    cout<<score<<endl;
    return 0;
}

int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

void ipgraph(int n, int m){
 int i, u, v;
 while(m--){
  cin>>u>>v;
    u--, v--;
  g[u].pb(v);
  g[v].pb(u);
 }
}

void dfs(int u, int par){
 for(int v:g[u]){
  if (v == par) continue;
  dfs(v, u);
 }
}