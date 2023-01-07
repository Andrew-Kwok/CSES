#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int const N = 2e5 + 7;

int st[4*N];
int idx[N];
int height[N];
vector<int> euler;
vector<int> adj[N];

int par[N];
int indegree[N];

int ctr[N][2]; //0: before, 1: after
int res[N];

bool vst[N];
void dfs(int node, int h = 0)
{
	vst[node] = true;

	idx[node] = euler.size();
	height[node] = h;
	euler.pb(node);
	for (int to : adj[node])
	{
		if (!vst[to])
		{
			par[to] = node;
			indegree[node]++;

			dfs(to, h+1);
			euler.pb(node);
		}
	}
}

int combine(int u, int v)
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

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n-1; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1);
	build();

	while (m--)
	{
		int u, v;
		cin >> u >> v;

		int x = lca(u, v);

		ctr[u][0]++; ctr[v][0]++;
		ctr[x][0]--; ctr[x][1]--;
	}

	queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		res[node] = ctr[node][0];

		if (node != 1)
		{
			ctr[par[node]][0] += ctr[node][0] + ctr[node][1];
			indegree[par[node]]--;
			if (indegree[par[node]] == 0)
				q.push(par[node]);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (i > 1) cout << " ";
		cout << res[i];
	}
	cout << '\n';	

	return 0;
}