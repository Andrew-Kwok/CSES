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

const int MAX = 501;

int n, m;
ll speed[MAX][MAX] = {};

vector<int> path;
void bfs()
{
	queue<int> q;
	vector<int> par(n+1, -1);

	q.push(1);
	par[1] = -2;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		//cerr << "node: " << node << '\n';

		if (node == n)
			break;

		for (int i = 1; i <= n; ++i)
		{
			if (par[i] != -1 || node == i || speed[node][i] == 0)
				continue;
			par[i] = node;
			q.push(i);
		}
	}

	path.clear();
	for (int node = n; node >= 1; node = par[node])
		path.pb(node);
	reverse(path.begin(), path.end());
}

int main()
{
	fastio;

	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		speed[u][v] += w;
	}

	ll res = 0;
	for (;;)
	{
		bfs();
		if (path.size() <= 1)
			break;

		ll mn = 1e18;
		for (int i = 0; i+1 < path.size(); ++i)
			mn = min(mn, speed[path[i]][path[i+1]]);
		for (int i = 0; i+1 < path.size(); ++i)
			speed[path[i]][path[i+1]] -= mn, speed[path[i+1]][path[i]] += mn;
		res += mn;

		//cerr << "MN: " << mn << '\n';
	}
	cout << res << '\n';

	return 0;
}
