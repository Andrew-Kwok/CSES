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
int const N = 2e5 + 7;

int n;
vector<int> adj[N];

ii bfs(int node)
{

	queue<int> q;
	vector<int> dist(n+1, -1);

	dist[node] = 0;
	q.push(node);

	ii best = {0, node};
	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (int to : adj[node])
		{
			if (dist[to] == -1)
			{
				dist[to] = dist[node] + 1;			
				q.push(to);

				best = max(best, {dist[to], to});
			}
		}
	}

	return best;
}

int main()
{
	fastio;

	cin >> n;
	for (int i = 0; i < n-1; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}

	ii d1 = bfs(1);
	ii d2 = bfs(d1.s2);

	cout << d2.f1 << '\n';
	return 0;
}
