#include <iostream>
#include <vector>
#include <functional>

#define ll long long
#define pb push_back
#define ii pair<int, int>
#define f1 first
#define s2 second
using namespace std;

const int MAX = 2e5 + 7;

int n, k;
int sz[MAX], dead[MAX];
vector<int> adj[MAX];

inline int dfs_sz(int node, int par)
{
	sz[node] = 1;
	for (int to : adj[node])
		if (!dead[to] && to != par)
			sz[node] += dfs_sz(to, node);
	return sz[node];
}

inline int centroid(int node, int par, int _n)
{
	for (int to : adj[node])
		if (!dead[to] && to != par && sz[to] >= _n/2)
			return centroid(to, node, _n);
	return node;
}

ll calc(int *ctr, int &mx)
{
	ll res = 0;
	for (int i = 1; i <= mx && 2*i <= k; ++i)
	{
		int j = k - i;
		if (i == j) res += 1ll * ctr[i] * (ctr[i]-1) / 2;
		else res += 1ll * ctr[i] * ctr[j];
	}
	return res;
}

inline void get(int node, int par, int depth, int *ctr, int &mx)
{
	ctr[depth]++;
	mx = max(mx, depth);
	for (int to : adj[node])
	{
		if (!dead[to] && to != par)
			get(to, node, depth + 1, ctr, mx);
	}
}

ll ans = 0; 
int ctr_all[MAX], mx_all, ctr_cur[MAX], mx_cur;
inline void decomp(int node)
{
	int _n = dfs_sz(node, -1);
	int C = centroid(node, -1, _n);

	mx_all = -1;
	for (int to : adj[C])
		if (!dead[to])
	{
		mx_cur = -1;
		get(to, C, 1, ctr_cur, mx_cur);

		ans -= calc(ctr_cur, mx_cur);
		mx_all = max(mx_all, mx_cur);
		for (int i = 1; i <= mx_cur; ++i)
		{
			ans += (i == k ? ctr_cur[i] : 0);
			ctr_all[i] += ctr_cur[i];
			ctr_cur[i] = 0;
		}
	}
	ans += calc(ctr_all, mx_all);
	for (int i = 1; i <= mx_all; ++i)
		ctr_all[i] = 0;

	dead[C] = true;
	for (int to : adj[C])
		if (!dead[to])
			decomp(to);
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n-1; ++i)
	{
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}

	decomp(1);
	cout << ans << '\n';

	return 0;
}