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

int const N = 507;
ll const inf = 1e18;

int n, m, q;
ll dist[N][N];
int main()
{
	fastio;

	cin >> n >> m >> q;
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = inf;
		}
	}

	for (int i = 0; i < m; ++i)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		dist[u][v] = dist[v][u] = min(dist[u][v], w);
	}

	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
	{
		if (dist[i][j] > dist[i][k] + dist[k][j])
			dist[i][j] = dist[i][k] + dist[k][j];
	}

	while (q--)
	{
		ll u, v;
		cin >> u >> v;
		cout << (dist[u][v] == inf ? -1 : dist[u][v]) << '\n';
	}

	return 0;
}
