#include <iostream>
#include <vector>
using namespace std;

#define pb push_back
#define ii pair<int, int>
#define f1 first
#define s2 second

const int MAX = 1e5 + 7;

vector<int> adj[MAX];
vector<ii> bridge;
int disc[MAX], low[MAX];

static int ctr = 1;
void dfs(int node, int par)
{
	disc[node] = low[node] = ctr++;
	for (int to : adj[node])
	{
		if (disc[to] == -1)
		{
			dfs(to, node);
			if (low[to] > disc[node])
				bridge.pb({node, to});

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
		disc[i] = low[i] = -1;
	dfs(1, -1);

	cout << bridge.size() << '\n';
	for (auto [u, v] : bridge)
		cout << u << " " << v << '\n';

	return 0;
}