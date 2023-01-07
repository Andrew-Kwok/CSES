#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x...) cerr << "[" << #x << "]: " << x << "\n";

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using pl = pair<ll, ll>;

ld const PI = 4*atan((ld)1);
int const N = 1e5 + 7;

vector<int> adj[N];

int main()
{
	fastio;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
	}

	int root = 1;

	vector<int> visited(n+1, false);
	vector<int> path;
	vector<int> position(n+1, -1);
	function<void (int)> dfs = [&](int node)
	{
		visited[node] = true;
		while (root <= n&& visited[root])
			root++;
		
		position[node] = path.size();
		path.pb(node);
		for (int to : adj[node])
		{
			if (position[to] != -1)
			{
				path.erase(path.begin(), path.begin() + position[to]);

				cout << path.size() + 1 << '\n';
				for (int x : path)
					cout << x << " ";
				cout << to << '\n';

				exit(0);
			}

			if (!visited[to])
				dfs(to);
		}
		position[node] = -1;
		path.pop_back();
	};

	while (root <= n)
		dfs(root);
	
	cout << "IMPOSSIBLE\n";
	return 0;
}
