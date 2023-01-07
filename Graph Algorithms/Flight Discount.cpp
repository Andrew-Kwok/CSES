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
ll const inf = 1e18;
int const N = 1e5 + 7;

ll dist[N][2];
vector<pl> adj[N];

struct info
{
	ll cost, node;
	bool ticket;

	bool operator()(info const &x, info const &y)
	{
		return x.cost > y.cost;
	}
};
priority_queue<info, vector<info>, info> pq;
int main()
{
	fastio;

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		dist[i][0] = dist[i][1] = inf;

	for (int i = 0; i < m; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({v, w});
	}

	dist[1][1] = 0;
	pq.push({0, 1, true});

	while (!pq.empty())
	{
		ll cost = pq.top().cost;
		ll node = pq.top().node;
		bool ticket = pq.top().ticket;
		pq.pop();

		if (dist[node][ticket] < cost)
			continue;

		for (pl to : adj[node])
		{
			if (dist[to.f1][ticket] > cost + to.s2)
			{
				dist[to.f1][ticket] = cost + to.s2;
				pq.push({dist[to.f1][ticket], to.f1, ticket});
			}
			if (ticket && dist[to.f1][0] > cost + to.s2 / 2)
			{
				dist[to.f1][0] = cost + to.s2 / 2;
				pq.push({dist[to.f1][0], to.f1, 0});
			}
		}
	}

	cout << dist[n][0] << '\n';

	return 0;
}
