#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define pb push_back

const int MAX = 2e5 + 69;

int n, ds[MAX], C[MAX], res[MAX];
set<int> st[MAX];
vector<int> adj[MAX];

inline int frep(int x) { return ds[x] == x ? x : ds[x] = frep(ds[x]); }
inline void join(int x, int y)
{
	x = frep(x); y = frep(y);
	if (x == y)
		return;

	if (st[x].size() < st[y].size())
		swap(x, y);

	for (int c : st[y])
		st[x].insert(c);
	ds[y] = x;
}

inline void dfs(int node, int par)
{
	for (int to : adj[node])
		if (to != par)
			dfs(to, node), join(to, node);
	st[frep(node)].insert(C[node]);
	res[node] = st[frep(node)].size();
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < MAX; ++i)
		ds[i] = i;

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> C[i];

	for (int i = 0; i < n-1; ++i)
	{
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
	dfs(1, -1);

	for (int i = 1; i <= n; ++i)
		cout << res[i] << " \n"[i == n];

	return 0;
}