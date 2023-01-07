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
const int MAX = 2e5 + 69;

int n, m, id[MAX];
bitset<MAX> arti; // articulation point
vector<int> adj[MAX], tree[MAX];
vector<ii> edges;

// build block cut tree
void build_bct()
{	
	int disc[MAX], low[MAX];
	vector<vector<int>> comps;

	int ctr = 1;
	vector<int> sk;
	const auto dfs = [&](const auto &self, int node, int par) -> void
	{
		disc[node] = low[node] = ctr++;
		sk.pb(node);

		for (int to : adj[node]) if (to != par)
		{
			if (disc[to] == -1)
			{
				self(self, to, node);
				low[node] = min(low[node], low[to]);
				if (low[to] >= disc[node])
				{
					arti[node] = (disc[node] > 1 || disc[to] > 2);
					
					comps.pb({node});
					for (; comps.back().back() != to; sk.pop_back())
						comps.back().pb(sk.back());
				}
			}
			else low[node] = min(low[node], disc[to]);
		}
	};

	memset(disc, -1, sizeof(disc));
	memset(low, -1, sizeof(low));
	comps.clear();
	ctr = 1;
	dfs(dfs, 1, -1);

	// build tree
	ctr = 1;
	for (int i = 1; i <= n; ++i)
	{
		if (arti[i])
			id[i] = ctr++;
	}

	for (auto &comp : comps)
	{
		for (int node : comp)
		{
			if (!arti[node]) id[node] = ctr;
			else 
			{
				tree[ctr].pb(id[node]);
				tree[id[node]].pb(ctr);
			}
		}
		ctr++;
	}
}

int pos[MAX], head[MAX], heavy[MAX], sz[MAX], par[MAX], depth[MAX];
void dfs_sz(int node)
{
    sz[node] = 1;
    int sz_mx = 0;
    for (int to : tree[node])
    {
        if (to != par[node])
        {
            par[to] = node;
            depth[to] = depth[node] + 1;
            dfs_sz(to);

            sz[node] += sz[to];
            if (sz[to] > sz_mx)
                sz_mx = sz[to], heavy[node] = to;
        }
    }
}

static int cur_pos = 1; // first index of hld
void dfs_hld(int node, int h)
{
    head[node] = h; pos[node] = cur_pos++;
    if (heavy[node] != -1)
        dfs_hld(heavy[node], h);
    for (int to : tree[node])
        if (to != par[node] && to != heavy[node])
            dfs_hld(to, to);
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

// c lies between the path from 'a' to 'b'
inline bool onpath(int a, int b, int c)
{
	int lc = lca(a, b);
	if (lca(a, c) == c && lca(c, lc) == lc)
		return true;
	if (lca(b, c) == c && lca(c, lc) == lc)
		return true;
	return false;
}

void solve()
{
	int q;
	cin >> n >> m >> q;

	for (int i = 0; i < m; ++i)
	{
		int u, v; cin >> u >> v;
		edges.pb({u, v});
		adj[u].pb(v); adj[v].pb(u);
	}

	build_bct();

	memset(heavy, -1, sizeof(heavy));
	dfs_sz(1);
	dfs_hld(1, 1);

	while (q--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == c || b == c) cout << "NO\n";
		else if (arti[c] && onpath(id[a], id[b], id[c])) cout << "NO\n";
		else cout << "YES\n";
	}
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
