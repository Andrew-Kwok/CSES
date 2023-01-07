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
ll const mod = 1e9 + 7;
ll const inf = 1e18;
int const N = 1e5 + 7;

inline ll add(ll x, ll y)
{
	return (x + y) % mod;
}

ll dist[N];
ll ways[N];
ll minn[N];
ll maxx[N];
vector<pl> adj[N];

priority_queue<pl, vector<pl>, greater<pl>> pq;
int main()
{
	fastio;

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		dist[i] = inf, ways[i] = 0, minn[i] = inf, maxx[i] = 0;

	for (int i = 0; i < m; ++i)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({v, w});
	}

	pq.push({0, 1});
	dist[1] = 0; ways[1] = 1; minn[1] = 0, maxx[1] = 0;
	while (!pq.empty())
	{
		ll cost = pq.top().f1;
		int node = pq.top().s2;
		pq.pop();

		for (pl to : adj[node])
		{
			if (cost + to.s2 < dist[to.f1])
			{
				dist[to.f1] = cost + to.s2;
				ways[to.f1] = ways[node];
				minn[to.f1] = 1 + minn[node];
				maxx[to.f1] = 1 + maxx[node];
				pq.push({dist[to.f1], to.f1});
			}
			else if (cost + to.s2 == dist[to.f1])
			{
				ways[to.f1] = add(ways[to.f1], ways[node]);
				minn[to.f1] = min(minn[to.f1], 1 + minn[node]);
				maxx[to.f1] = max(maxx[to.f1], 1 + maxx[node]);
			}
		}
	}

	cout << dist[n] << " " << ways[n] << " " << minn[n] << " " << maxx[n] << '\n';
	return 0;
}
