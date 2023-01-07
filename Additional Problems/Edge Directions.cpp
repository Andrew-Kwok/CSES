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
int const MAX = 1e5 + 7;

vector<ii> adj[MAX];
bool vst[MAX];
bool used[2 * MAX];

void bfs(int node)
{
	queue<int> q;

	vst[node] = true;
	q.push(node);

	while (!q.empty())
	{
		node = q.front();
		q.pop();

		for (ii to : adj[node])
		{
			if (!used[to.s2])
			{
				cout << node << " " << to.f1 << '\n';
				used[to.s2] = true;
			}
			if (!vst[to.f1])
			{
				vst[to.f1] = true;
				q.push(to.f1);
			}
		}
	}
}

int main()
{
	fastio;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;

		adj[u].pb({v, i});
		adj[v].pb({u, i});
	}

	for (int i = 1; i <= n; ++i)
	{
		if (!vst[i])
			bfs(i);
	}

	return 0;
}
