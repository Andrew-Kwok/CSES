#include <bits/stdc++.h>
using namespace std;

#define pb push_back

using ii = pair<int, int>;

const int MAX = 2e5 + 69;

int N, Q, D[MAX], F[MAX];
vector<int> adj[MAX], B[MAX];

map<ii, int> dist; // could use unordered_map with hash function for constant complexity

struct dsu {
	int par, val;
} uf[MAX];

int Find(int x) { return uf[x].par == x ? x : uf[x].par = Find(uf[x].par); }
void Union(int x, int y) { uf[Find(x)].par = Find(y); }  // could have used union-by-rank for better complexity

static int f = 0;
void dfs(int node, int par) 
{
	for (int to : adj[node]) if (to != par)
	{
		D[to] = D[node] + 1; // can be changed to w(node, to)
		dfs(to, node);
	}
	F[node] = f++;
}

void traverse(int node, int par)
{
	uf[node] = { node, node };
	for (int to : adj[node]) if (to != par)
	{
		traverse(to, node);
		Union(to, node);
		uf[Find(node)].val = node;
	}

	for (int to : B[node]) 
		if (F[to] < F[node])
	{
		int lca = uf[Find(to)].val;
		dist[{node, to}] = dist[{to, node}] = D[node] + D[to] - 2 * D[lca];
	}
}

int main() 
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> Q;
	for (int i = 0, u, v; i < N-1; ++i)
	{
		cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}

	vector<ii> P(Q);
	for (auto &[u, v] : P)
	{
		cin >> u >> v;
		B[u].pb(v); B[v].pb(u);
	}

	dfs(1, -1);
	traverse(1, -1);

	for (auto &[u, v] : P)
	{
		cout << dist[{u, v}] << '\n';
	}
}