#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f1 first
#define s2 second

using ii = pair<int, int>;

const int MAX = 1 << 17;

int N, M, K;
vector<int> adj[MAX];

ii dist[MAX][2];

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	memset(dist, -1, sizeof(dist));

	queue<ii> q;

	cin >> N >> M >> K;
	for (int i = 0; i < K; ++i)
	{
		int x; cin >> x;
		dist[x][0] = {0, x};
		q.push({x, 0});
	}

	for (int i = 0; i < M; ++i)
	{
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}

	while (!q.empty()) 
	{
		auto [node, k] = q.front(); q.pop();

		for (int to : adj[node])
		{
			if (dist[to][0].s2 == -1)
			{
				dist[to][0] = {1 + dist[node][k].f1, dist[node][k].s2};
				q.push({to, 0});
			}
			else if (dist[to][1].s2 == -1 && dist[to][0].s2 != dist[node][k].s2)
			{
				dist[to][1] = {1 + dist[node][k].f1, dist[node][k].s2};
				q.push({to, 1});
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		if (dist[i][0].f1 > 0) cout << dist[i][0].f1 << '\n';
		else if (dist[i][1].f1 > 0) cout << dist[i][1].f1 << '\n';
		else cout << -1 << '\n';
	}


	return 0;
}