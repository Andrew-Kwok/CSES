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
int const MAX = 2e5 + 7;
int const LG = ceil(log2(MAX));

vector<int> adj[MAX];
int up[MAX][LG];
int depth[MAX];

bool vst[MAX];
void dfs(int node, int par, int h = 0)
{
	vst[node] = true;
	depth[node] = h;

	up[node][0] = par;
	for (int i = 1; i < LG; ++i)
		up[node][i] = up[up[node][i-1]][i-1];

	for (int to : adj[node])
		if (!vst[to])
			dfs(to, node, h+1);
}

int main()
{
	fastio;

	int n, q;
	cin >> n >> q;

	for (int i = 2; i <= n; ++i)
	{
		int p;
		cin >> p;
		adj[p].pb(i); adj[i].pb(p);
	}

	dfs(1, 1);
	while (q--)
	{
		int node, x;
		cin >> node >> x;

		if (depth[node] < x)
		{
			cout << -1 << '\n';
			continue;
		}

		int res = node;
		for (int i = 0; i < LG; ++i)
		{
			if (x & (1 << i))
				res = up[res][i];
		}
		cout << res << '\n';
	}

	return 0;
}
