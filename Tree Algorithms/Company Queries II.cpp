#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int const N = 2e5 + 7;

int idx[N];
int height[N];
vector<int> euler;
vector<int> adj[N];

int st[4*N];

bool vst[N];
void dfs(int node, int h = 0)
{
	vst[node] = true;
	
	height[node] = h;
	idx[node] = euler.size();
	euler.pb(node);
	for (int to : adj[node])
	{
		if (!vst[to])
		{
			dfs(to, h+1);
			euler.pb(node);
		}
	}
}

inline int combine(int u, int v)
{
	return height[u] < height[v] ? u : v;
}

void build()
{
	for (int i = 0; i < euler.size(); ++i)
		st[i + euler.size()] = euler[i];

	for (int i = (int)euler.size() - 1; i > 0; --i)
		st[i] = combine(st[i << 1], st[i << 1 | 1]);
}

int lca(int u, int v)
{
	int l = idx[u], r = idx[v];
	if (l > r) swap(l, r);
	r++;

	int res = u;
	for (l += euler.size(), r += euler.size(); l < r; l >>= 1, r >>= 1)
	{
		if (l & 1) res = combine(res, st[l++]);
		if (r & 1) res = combine(res, st[--r]);
	}
	return res;
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	for (int i = 2; i <= n; ++i)
	{
		int p;
		cin >> p;

		adj[i].pb(p); adj[p].pb(i);
	}

	dfs(1);
	build();

	while (q--)
	{
		int u, v;
		cin >> u >> v;

		cout << lca(u, v) << '\n';
	}

	return 0;
}