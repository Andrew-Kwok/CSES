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

int const N = 2507;
ll const inf = 1e18;

struct edge
{
	ll u, v, w;
};

ll dist[N] = {};
vector<edge> edges;

vector<int> adj[N];
bool from1[N] = {}, fromN[N] = {};
bool vst[N] = {};

int main()
{
	fastio;

	for (int i = 0; i < N; ++i)
		dist[i] = -inf;
	dist[1] = 0;

	int n, m;
	cin >> n >> m;

	edges.resize(m);
	for (auto &x : edges)
		cin >> x.u >> x.v >> x.w;

	//possible from 1
	for (int i = 1; i <= n; ++i)
		adj[i].clear(), vst[i] = false;
	for (auto &x : edges)
		adj[x.u].pb(x.v);

	from1[1] = true;
	queue<int> q;
	q.push(1);

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (int to : adj[node])
			if (!vst[to])
		{
			vst[to] = true;
			from1[to] = true;
			q.push(to);
		}
	}

	//possible from n
	for (int i = 1; i <= n; ++i)
		adj[i].clear(), vst[i] = false;
	for (auto &x : edges)
		adj[x.v].pb(x.u);

	fromN[n] = true;
	q.push(n);

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (int to : adj[node])
			if (!vst[to])
		{
			vst[to] = true;
			fromN[to] = true;
			q.push(to);
		}
	}


	for (int i = 0; i < n-1; ++i)
		for (auto x : edges)
			if (from1[x.u] && fromN[x.u] && from1[x.v] && fromN[x.v])
				dist[x.v] = max(dist[x.v], dist[x.u] + x.w);

	for (auto x : edges)
		if (from1[x.u] && fromN[x.u] && from1[x.v] && fromN[x.v])
	{
		if (dist[x.v] < dist[x.u] + x.w)
		{
			cout << -1 << '\n';
			return 0;
		}
	}

	cout << dist[n] << '\n';
	return 0;
}
