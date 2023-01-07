#include <iostream>
#include <vector>
using namespace std;

#define pb push_back
#define ii pair<int, int>
#define f1 first
#define s2 second

const int MAX = 1e5 + 7;

vector<int> adj[MAX];
bool arti[MAX];
int disc[MAX], low[MAX], child[MAX];

static int ctr = 1;
void dfs(int node, int par)
{
	disc[node] = low[node] = ctr++;
	for (int to : adj[node])
	{
		if (disc[to] == -1)
		{
			dfs(to, node);
			child[node]++;
			if (low[to] >= disc[node])
				arti[node] = true;

			low[node] = min(low[node], low[to]);
		}
		else if (to != par)
			low[node] = min(low[node], disc[to]);
	}
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}

	for (int i = 1; i <= n; ++i)
		disc[i] = low[i] = -1, child[i] = 0;
	dfs(1, -1);

	if (child[1] >= 2) arti[1] = true;
	else arti[1] = false;

	int sz = 0;
	for (int i = 1; i <= n; ++i)
		sz += arti[i];

	cout << sz << '\n';
	for (int i = 1; i <= n; ++i)
		if (arti[i])
			cout << i << '\n';

	return 0;
}