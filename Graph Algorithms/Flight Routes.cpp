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

vector<pl> adj[N];
vector<ll> dist[N];

priority_queue<pl, vector<pl>, greater<pl>> pq; 
int main()
{
	fastio;

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < m; ++i)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({v, w});
	}

	pq.push({0, 1});
	while (!pq.empty())
	{
		int node = pq.top().s2;
		ll cost = pq.top().f1;
		pq.pop();

		if (dist[node].size() < k)
		{
			dist[node].pb(cost);
			for (pl to : adj[node])
				pq.push({cost + to.s2, to.f1});
		}
	}


	for (int i = 0; i < k; ++i)
	{
		if (i) cout << " ";
		cout << dist[n][i];
	}
	cout << '\n';

	return 0;
}
