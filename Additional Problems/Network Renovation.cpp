#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second
 
#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x) cerr << "[" << #x << "]: " << x << "\n";
 
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using pl = pair<ll, ll>;
 
const ld PI = 4*atan((ld)1);
const int MAX = 1e5 + 69;
 
int N;
int fq[MAX], sz[MAX];
vector<int> adj[MAX];
 
vector<int> order;
inline int dfs_sz(int node, int par)
{
	sz[node] = fq[node] == 1;
	for (int to : adj[node]) if (to != par)
		sz[node] += dfs_sz(to, node);
	return sz[node];
}
 
inline void dfs_order(int node, int par)
{
	if (fq[node] == 1)
		order.pb(node);
	for (int to : adj[node])
		if (to != par)
			dfs_order(to, node);
}
 
 
void solve()
{
	cin >> N;
	for (int i = 1; i <= N-1; ++i)
	{
		int u, v; cin >> u >> v;
		fq[u]++; fq[v]++;
		adj[u].pb(v); adj[v].pb(u);
	}
 
	dfs_sz(1, -1);
	for (int i = 1; i <= N; ++i)
	{
		sort(adj[i].begin(), adj[i].end(), [](const int &x, const int &y){
			return sz[x] > sz[y]; 
		});
	}
 
	dfs_order(1, -1);
 	
 	int len = (int)order.size();
	cout << (len + 1) / 2 << '\n';
	for (int i = 0; i < (len + 1) / 2; ++i)
		cout << order[i] << " " << order[len/2 + i] << '\n';
}
 
int main()
{
	fastio;
 
	int TC = 1;
	//cin >> TC;
 
	while (TC--)
		solve();
 
	return 0;
}
