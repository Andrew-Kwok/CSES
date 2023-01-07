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

vector<int> adj[N];
vector<int> adjR[N];
bool vst[N];
int ans[N];

vector<int> order;
vector<int> component;

void dfs1(int node)
{
	vst[node] = true;
	for (int to : adj[node])
	{
		if (!vst[to])
			dfs1(to);
	}
	order.pb(node);
}

void dfs2(int node)
{
	vst[node] = true;
	for (int to : adjR[node])
	{
		if (!vst[to])
			dfs2(to);
	}
	component.pb(node);
}

int main()
{
	fastio;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;

		adj[u].pb(v);
		adjR[v].pb(u);
	}

	for (int i = 1; i <= n; ++i)
	{
		if (!vst[i])
			dfs1(i);
	}

	int sz = 0;

	memset(vst, false, sizeof(vst));
	reverse(order.begin(), order.end());
	for (int node : order)
	{
		if (!vst[node])
		{
			component.clear();
			dfs2(node);
			
			sz++;
			for (int x : component)
				ans[x] = sz;
		}
	}

	cout << sz << '\n';
	for (int i = 1; i <= n; ++i)
		cout << ans[i] << " ";
	cout << '\n';

	return 0;
}
