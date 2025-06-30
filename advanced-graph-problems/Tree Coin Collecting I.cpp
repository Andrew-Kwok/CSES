#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAX = 1 << 18;

int N, Q;
vector<int> adj[MAX];
bitset<MAX> coin;
int coin_dist[MAX];

int par[MAX], head[MAX], pos[MAX], heavy[MAX], sz[MAX], depth[MAX];
void dfs_sz(int node)
{
	int sz_mx = 0;
	sz[node] = 1;
	for (int to : adj[node]) if (to != par[node])
	{
		par[to] = node; depth[to] = 1 + depth[node];
		dfs_sz(to);
		sz[node] += sz[to];
		if (sz[to] > sz_mx)
			sz_mx = sz[to], heavy[node] = to;
	}
}


static int cur_pos = 1;
void dfs_hld(int node, int h)
{
	pos[node] = cur_pos++; head[node] = h;
	if (heavy[node] != -1)
		dfs_hld(heavy[node], h);
	for (int to : adj[node]) if (to != par[node] && to != heavy[node])
		dfs_hld(to, to);
}

int st[2 * MAX];
inline int rmq(int l, int r)
{
	int Z = MAX;
	for (l += MAX, r += MAX+1; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1) Z = min(Z, st[l++]);
		if (r & 1) Z = min(Z, st[--r]);
	}
	return Z;
}

inline int lca(int u, int v)
{
	for (; head[u] != head[v]; u = par[head[u]])
	{
		if (depth[head[u]] < depth[head[v]])
			swap(u, v);
	}
	return depth[u] < depth[v] ? u : v;
}

inline int query_lc(int u, int lc)
{
	int Z = MAX;
	for (; head[u] != head[lc]; u = par[head[u]])
	{
		Z = min(Z, rmq(pos[head[u]], pos[u]));
	}
	Z = min(Z, rmq(pos[lc], pos[u]));
	return Z;
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> Q;
	for (int i = 1; i <= N; ++i)
	{
		int x; cin >> x;
		if (x) coin[i] = 1;
	}

	for (int i = 0; i < N-1; ++i)
	{
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}

	memset(coin_dist, -1, sizeof coin_dist);
	queue<int> q;
	for (int i = 1; i <= N; ++i) if (coin[i])
		coin_dist[i] = 0, q.push(i);

	while (!q.empty())
	{
		int node = q.front(); q.pop();
		for (int to : adj[node]) if (coin_dist[to] == -1)
			coin_dist[to] = 1 + coin_dist[node], q.push(to);
	}

	memset(heavy, -1, sizeof(heavy));
	dfs_sz(1);
	dfs_hld(1, 1);

	memset(st, 0x3f, sizeof st);
	for (int i = 1; i <= N; ++i)
		st[pos[i] + MAX] = coin_dist[i];
	for (int i = MAX-1; i >= 0; --i)
		st[i] = min(st[i << 1], st[i << 1 | 1]);

	while (Q--)
	{
		int u, v;
		cin >> u >> v;

		int lc = lca(u, v);
		
		int dist = depth[u] + depth[v] - 2 * depth[lc];
		int min_dist = min(query_lc(u, lc), query_lc(v, lc));
		cout << dist + 2 * min_dist << '\n';
	}

	return 0;
}