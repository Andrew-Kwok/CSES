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

int n, k1, k2;
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

	vector<int> pfx(tmp.size());
	for (int i = 0; i < (int)tmp.size(); ++i)
		pfx[i] = tmp[i].s2 + (i ? pfx[i-1] : 0);

	for (int i = 0, j1 = (int)tmp.size() - 1, j2 = (int)tmp.size() - 1;; ++i)
	{
		while (j1 >= 0 && tmp[i].f1 + tmp[j1].f1 >= k1)
			j1--;
		while (j2 >= 0 && tmp[i].f1 + tmp[j2].f1 > k2)
			j2--;
		if (i > j2)
			break;

		if (j1 < i && i <= j2)
			res += 1LL * tmp[i].s2 * (tmp[i].s2-1) / 2;
		res += 1LL * tmp[i].s2 * (pfx[j2] - pfx[max(i, j1)]);
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
			ans += (k1 <= x && x <= k2);
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
	//k1 = 5; k2 = 7;
	//calc({1, 3, 3, 4, 4});
	//return 0;

	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k1 >> k2;
	for (int i = 0; i < n-1; ++i)
	{
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}

	decomp(1);
	cout << ans << '\n';

	return 0;
}