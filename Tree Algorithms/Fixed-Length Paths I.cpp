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

ll calc(vector<int> v)
{
	sort(v.begin(), v.end());
	vector<ii> tmp;
	for (int x : v)
	{
		if (!tmp.empty() && tmp.back().f1 == x) tmp.back().s2++;
		else tmp.pb({x, 1});
	}

	ll res = 0;
	for (int i = 0, j = (int)tmp.size() - 1; i <= j; ++i)
	{
		while (j >= 0 && tmp[i].f1 + tmp[j].f1 > k)
			j--;
		if (i > j)
			break;

		if (tmp[i].f1 + tmp[j].f1 == k)
		{
			if (i == j) res += 1LL * tmp[i].s2 * (tmp[i].s2-1) / 2;
			else res += 1LL * tmp[i].s2 * tmp[j].s2;
		}
	}

	return res;
}

inline void get(int node, int par, int depth, vector<int> &v)
{
	v.pb(depth);
	for (int to : adj[node])
	{
		if (!dead[to] && to != par)
			get(to, node, depth + 1, v);
	}
}

ll ans = 0;
inline void decomp(int node)
{
	int _n = dfs_sz(node, -1);
	int C = centroid(node, -1, _n);

	vector<int> all;
	for (int to : adj[C])
		if (!dead[to])
	{
		vector<int> v;
		get(to, C, 1, v);

		ans -= calc(v);
		for (int x : v)
		{
			ans += (x == k);
			all.pb(x);
		}
	}
	ans += calc(all);

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