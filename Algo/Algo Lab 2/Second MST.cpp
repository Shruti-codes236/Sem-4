// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define boostIO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define sz(v) (int)(v.size())
#define all(v) v.begin(), v.end()
#define mem0(a) memset(a, 0, sizeof(a))
#define mem1(a) memset(a, -1, sizeof(a))
#define trav(a, x) for (auto &a : x)
#define popcount(x) __builtin_popcountll(x)
#define pb push_back
#define fr first
#define sc second
#define mod 1000000007
#define int long long
#define flp(i,x,y) for( int i=x;i<y;i++)
typedef pair<int, int> pii;
const long long INF = 1e18;
const int N = 2e5 + 5;
void amx(int &x, int y) { x = max(x, y); }

int parent[N], siz[N];
void make(int v) 
{
    parent[v] = v;
    siz[v] = 1;
}
int head(int v)
{
    if (v == parent[v]) return v;
    return parent[v] = head(parent[v]);
}
void combine(int a, int b) {
    a = head(a), b = head(b);
    if (a != b) {
        if (siz[b] < siz[a]) swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
}
struct edge {
	int u, v, wt, id;
	bool operator<(const edge &other) const {
		return wt < other.wt;
	}
};
int n, m, depth[N];
vector<pii> adj[N];
vector<edge> v, unused, used, smst;
int dp[N][18], mx[N][18];

void dfs(int at, int frr, int wt = 0) {
	dp[at][0] = frr;
	mx[at][0] = wt;
	for (auto to : adj[at]) {
		if (to.fr == frr) continue;
		depth[to.fr] = depth[at] + 1;
		dfs(to.fr, at, to.sc);
	}
}
int lca(int x, int y) {
    int i;
    if (depth[x] < depth[y]) swap(x, y);
    for(i=16;i>=0;i--)
     {
        if (depth[dp[x][i]] >= depth[y]) x = dp[x][i];
    }
    if (x == y) return x;
    for(i=16;i>=0;i--) 
    {
        if (dp[x][i] != dp[y][i]) {
            x = dp[x][i], y = dp[y][i];
        }
    }
    return dp[x][0];
} // n -> 1e5
int solve(int x, int y) {
	int z = lca(x, y), res = 0;
	if (x != z) {
        for (int i = 17; i >= 0; i--) {
            if (depth[dp[x][i]] >= depth[z]) {
                amx(res, mx[x][i]);
                x = dp[x][i];
            }
        }
    }
    if (y != z) {
        for (int i = 17; i >= 0; i--) {
            if (depth[dp[y][i]] >= depth[z]) {
                amx(res, mx[y][i]);
                y = dp[y][i];
            }
        }
    }
    return res;
}
signed main() {
   // boostIO;
    cin >> n >> m;
    v.resize(m);
    for (int i = 0; i < m; i++) {
    	cin >> v[i].u >> v[i].v >> v[i].wt;
    	v[i].id = i;
    }
    int i;
    sort(v.begin(), v.end());
    for(i=0;i<=n;i++) make(i);
    int mst = 0;
    for (int i = 0; i < m; i++) 
    {
    	if (head(v[i].u) != head(v[i].v)) 
        {
    		combine(v[i].u, v[i].v);
    		adj[v[i].u].emplace_back(v[i].v, v[i].wt);
    		adj[v[i].v].emplace_back(v[i].u, v[i].wt);
    		mst +=v[i].wt;
    		used.push_back(v[i]);
    	}
        else unused.push_back(v[i]);
    }
  	// precomputations for finding the maximum value between u and v
    dfs(1, 0, 0);
    flp(j,0,17)
    {
     flp(i,0,n)
      {
    	dp[i][j] = dp[dp[i][j - 1]][j - 1]; 
      }
    }
    flp(j,0,17)
    {
     flp(i,0,n)
      {
    	mx[i][j] = max(mx[i][j - 1], mx[dp[i][j - 1]][j - 1]);
      }
    }
    // finding the second best mst
    int wt_dif = INF, f = -1;
    for (int i = 0; i < sz(unused); i++) {
    	int tmp = unused[i].wt - solve(unused[i].u, unused[i].v);
    	if (tmp < wt_dif) f = i;
    	wt_dif = min(wt_dif, tmp);
    }
    if (wt_dif == INF) {
    	// there is no second mst
    	cout << "NO SECOND BEST MST\n";
    	return 0;
    }
    cout << (mst + wt_dif) << endl;
    // fth edge in unused is optimal so we will add that and remove 
    // maximum weight edge between unused[f].u and unused[f].v
    smst.push_back(unused[f]);
    int x = unused[f].u, y = unused[f].v;
    int z = lca(x, y);
    int mxv = unused[f].wt - wt_dif;
    int pu = 0, pv = 0;
    while (x != z and pu == 0) {
    	if (mx[x][0] == mxv) {
    		pu = dp[x][0], pv = x;
    	}
    	x = dp[x][0];
    }
    while (y != z and pu == 0) {
    	if (mx[y][0] == mxv) {
    		pu = dp[y][0], pv = y;
    	}
    	y = dp[y][0];
    }
    if (pu > pv) swap(pu, pv);
    for (int i = 0; i < sz(used); i++) 
    {
    	if (used[i].u > used[i].v) swap(used[i].u, used[i].v);
    	if (pu == used[i].u and pv == used[i].v) {
    	} else {
    		smst.push_back(used[i]);
    	}
    }
    // represents the edges in second best mst
    for (auto it : smst) {
    	cout << it.u << " " << it.v << " " << it.wt << endl;
    }
    return 0;
}
// O(m log n + m log m)
// 