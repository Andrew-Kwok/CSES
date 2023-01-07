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

vector<int> adj[N];
ii res[N];

inline ii combine(ii x, int y)
{
	int a = max(x.f1, y);
	int b = x.f1 + x.s2 + y - a - min(x.s2, y);

	return mp(a, b);
}

bool vst[N];
void dfs(int node)
{
	vst[node] = true;
	for (int to : adj[node])
	{
		if (!vst[to])
		{
			dfs(to);
			res[node] = combine(res[node], 1 + res[to].f1);
		}
	}
}

void reroot(int node)
{
	vst[node] = true;
	for (int to : adj[node])
	{
		if (!vst[to])
		{
			if (res[node].f1 == 1 + res[to].f1)
				res[to] = combine(res[to], 1 + res[node].s2);
			else res[to] = combine(res[to], 1 + res[node].f1);

			reroot(to);
		}
	}
}

int main()
{
	fastio;

	int n;
	cin >> n;

	for (int i = 0; i < n-1; ++i)
	{
		int u, v;
		cin >> u >> v;

		adj[u].pb(v); adj[v].pb(u);
	}

	fill(res, res+N, mp(0, 0));
	dfs(1);

	fill(vst, vst+N, false);
	reroot(1);

	for (int i = 1; i <= n; ++i)
	{
		if (i > 1) cout << " ";
		cout << res[i].f1;
	}
	cout << '\n';

	return 0;
}
