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

constexpr ld PI = 4*atan((ld)1);
constexpr int MAX = 2e5 + 69;

int n;
int ds[MAX];
inline int frep(int x) { return ds[x] == x ? x : ds[x] = frep(ds[x]); }
inline void join(int x, int y) { ds[frep(x)] = frep(y); }

int val[MAX], par[MAX], depth[MAX], head[MAX], pos[MAX], sz[MAX], heavy[MAX], st[2 * MAX];
bitset<MAX> vst;
vector<ii> adj[MAX];

void dfs_sz(int node)
{
	vst[node] = true;
	sz[node] = 1;

	int sz_mx = 0;
	for (auto [to, w] : adj[node])
	{
		if (to != par[node])
		{
			par[to] = node; depth[to] = depth[node] + 1; val[to] = w;
			dfs_sz(to);

			sz[node] += sz[to];
			if (sz[to] > sz_mx)
				sz_mx = sz[to], heavy[node] = to;
		}
	}
}

static int cur_pos = 0;
void dfs_hld(int node, int h)
{
	vst[node] = true;
	pos[node] = cur_pos++; head[node] = h;
	if (heavy[node] != -1)
		dfs_hld(heavy[node], h);
	for (auto [to, w] : adj[node])
		if (to != heavy[node] && to != par[node])
			dfs_hld(to, to);
}

void build()
{
	for (int i = 1; i <= n; ++i)
		st[pos[i] + n] = val[i];
	for (int i = n-1; i > 0; --i)
		st[i] = max(st[i << 1], st[i << 1 | 1]);
}

int rmq(int l, int r)
{
	int res = 0;
	for (l += n, r += n+1; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1) res = max(res, st[l++]);
		if (r & 1) res = max(res, st[--r]);
	}
	return res;
}

int lca(int u, int v)
{
	for (; head[u] != head[v]; u = par[head[u]])
	{
		if (depth[head[u]] < depth[head[v]])
			swap(u, v);
	}
	return depth[u] < depth[v] ? u : v;
}

int query(int u, int lc)
{
	int res = 0;
	for (; head[u] != head[lc]; u = par[head[u]])
		res = max(res, rmq(pos[head[u]], pos[u]));
	return max(res, rmq(pos[lc] + 1, pos[u]));
}

int main()
{
	fastio;

	iota(ds, ds + MAX, 0);

	int m, q;
	cin >> n >> m >> q;

	for (int i = 1; i <= m; ++i)
	{
		int u, v;
		cin >> u >> v;

		if (frep(u) == frep(v))
			continue;
		join(u, v);
		
		adj[u].pb({v, i});
		adj[v].pb({u, i});
	}

	memset(heavy, -1, sizeof(heavy));
	for (int i = 1; i <= n; ++i)
		if (!vst[i])
			dfs_sz(i);

	vst.reset();
	for (int i = 1; i <= n; ++i)
		if (!vst[i])
			dfs_hld(i, i);

	build();

	for (int i = 0; i < q; ++i)
	{
		int u, v;
		cin >> u >> v;

		if (frep(u) == frep(v))
		{
			int lc = lca(u, v);
			cout << max(query(u, lc), query(v, lc)) << '\n';
		}
		else cout << -1 << '\n';
	}

	return 0;
}
