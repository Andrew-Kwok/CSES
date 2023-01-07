#include <iostream>
#include <vector>
using namespace std;

#define pb push_back

const int MAX = 2e5 + 7;

int n;
int sz[MAX];
vector<int> adj[MAX];

bool vst[MAX];
int dfs(int node)
{
	vst[node] = true;
	sz[node] = 1;
	for (int to : adj[node])
		if (!vst[to])
	{
		sz[node] += dfs(to);
	}
	return sz[node];
}

int getCentroid(int node)
{
	for (int to : adj[node])
	{
		int tmp = sz[to];
		if (sz[to] > sz[node]) tmp = n - sz[node];
		if (tmp > n/2)
			return getCentroid(to);
	}
	return node;
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n-1; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}

	dfs(1);
	cout << getCentroid(1) << '\n';

	return 0;
}