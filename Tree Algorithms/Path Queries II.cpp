#include <iostream>
#include <vector>
using namespace std;

#define pb push_back

const int MAX = 2e5 + 7;

int n;
int ar[MAX], sz[MAX], pos[MAX], heavy[MAX], par[MAX], head[MAX], depth[MAX], st[2 * MAX];
vector<int> adj[MAX];

inline void dfs_sz(int node)
{
	sz[node] = 1;
	int sz_max = 0;
	for (int to : adj[node])
	{
		if (to != par[node])
		{
			par[to] = node; depth[to] = depth[node] + 1;
			dfs_sz(to);

			sz[node] += sz[to];
			if (sz[to] > sz_max)
				sz_max = sz[to], heavy[node] = to;
		}
	}
}

static int cur_pos = 0;
inline void dfs_hld(int node, int h)
{
	head[node] = h; pos[node] = cur_pos++;
	if (heavy[node] != -1)
		dfs_hld(heavy[node], h);
	for (int to : adj[node])
		if (to != heavy[node] && to != par[node])
			dfs_hld(to, to);
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

inline void build()
{
	for (int i = 1; i <= n; ++i)
		st[n + pos[i]] = ar[i];
	for (int i = n-1; i > 0; --i)
		st[i] = max(st[i << 1], st[i << 1 | 1]);
}

inline void modify(int p, int val)
{
	for (st[p += n] = val; p > 1; p >>= 1)
		st[p >> 1] = max(st[p], st[p^1]);
}

inline int rmq(int l, int r)
{
	int res = 0;
	for (l += n, r += n+1; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1) res = max(res, st[l++]);
		if (r & 1) res = max(res, st[--r]);
	}
	return res;
}

inline int get(int u, int lc)
{
	int res = 0;
	for (; head[u] != head[lc]; u = par[head[u]])
		res = max(res, rmq(pos[head[u]], pos[u]));
	res = max(res, rmq(pos[lc], pos[u]));
	return res;
}

inline int ask(int u, int v)
{
	int lc = lca(u, v);
	return max(get(u, lc), get(v, lc));
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int q;
	cin >> n >> q;

	for (int i = 1; i <= n; ++i)
		cin >> ar[i];
	for (int i = 1; i <= n-1; ++i)
	{
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}

	for (int i = 1; i <= n; ++i)
		heavy[i] = -1;
	depth[1] = 0;

	dfs_sz(1);
	dfs_hld(1, 1);
	build();

	while (q--)
	{
		int ty, a, b;
		cin >> ty >> a >> b;

		if (ty == 1) modify(pos[a], b);
		else cout << ask(a, b) << '\n';
	}

	return 0;
}