#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x...) cerr << "[" << #x << "]: " << x << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;

ld const PI = 4*atan((ld)1);

int const N = 1e5 + 7;
ll const inf = 1e18;

ll dst[N];
vector<pl> adj[N];
priority_queue<pl, vector<pl>, greater<pl>> pq;

int main()
{
	fastio;

	for (int i = 0; i < N; ++i)
		dst[i] = inf;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({v, w}); //adj[v].pb({u, w});
	}

	dst[1] = 0;
	pq.push({0, 1});
	while (!pq.empty())
	{
		int node = pq.top().s2;
		ll cost = pq.top().f1;
		pq.pop();

		if (cost != dst[node])
			continue;

		for (auto to : adj[node])
			if (dst[to.f1] > dst[node] + to.s2)
		{
			dst[to.f1] = dst[node] + to.s2;
			pq.push({dst[to.f1], to.f1});
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (i > 1) cout << " ";
		cout << dst[i];
	}
	cout << '\n';

	return 0;
}
