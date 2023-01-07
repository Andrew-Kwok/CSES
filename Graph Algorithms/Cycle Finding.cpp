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
int const N = 2507;

int par[N];
ll dist[N];

struct edge
{
	int from, to;
	ll cost;
};
edge ar[2*N];

int main()
{
	fastio;

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		dist[i] = inf;

	for (int i = 1; i <= m; ++i)
		cin >> ar[i].from >> ar[i].to >> ar[i].cost;

	dist[1] = 0;
	for (int i = 1; i < n; ++i)
	{
		for (int i = 1; i <= m; ++i)
		{
			if (dist[ar[i].to] > dist[ar[i].from] + ar[i].cost)
			{
				dist[ar[i].to] = dist[ar[i].from] + ar[i].cost;
				par[ar[i].to] = ar[i].from;
			}
		}
	}

	int node = -1;
	for (int i = 1; i <= m; ++i)
	{
		if (dist[ar[i].to] > dist[ar[i].from] + ar[i].cost)
		{
			dist[ar[i].to] = dist[ar[i].from] + ar[i].cost;
			par[ar[i].to] = ar[i].from;
			node = ar[i].to;
		}
	}

	if (node == -1)
	{
		cout << "NO\n";
		return 0;
	}

	vector<int> path;
	vector<int> vst (n+1, -1);

	int ctr = 0;
	for (;; node = par[node])
	{
		path.pb(node);
		if (vst[node] != -1)
		{
			path.erase(path.begin(), path.begin() + vst[node]);
			break;
		}
		vst[node] = ctr++;
	}
	reverse(path.begin(), path.end());
	
	cout << "YES\n";
	for (int i = 0; i < path.size(); ++i)
	{
		if (i) cout << " ";
		cout << path[i];
	}
	cout << '\n';

	return 0;
}
