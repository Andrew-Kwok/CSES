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
vector<int> order;
vector<int> component;

bool vst[N];
int res[N];

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

bool reachable(int node, int target)
{
	bool res = false;

	vst[node] = true;
	if (node == target)
		return true;

	for (int to : adj[node])
	{
		if (!vst[to])
		{
			res = res || reachable(to, target);
		}
	}
	return res;
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

		adj[u].pb(v); adjR[v].pb(u);
	}

	for (int i = 1; i <= n; ++i)
	{
		if (!vst[i])
			dfs1(i);
	}

	memset(vst, false, sizeof(vst));
	reverse(order.begin(), order.end());
	for (int node : order)
	{
		if (!vst[node])
		{
			if (component.empty())
			{
				dfs2(node);
				continue;
			}

			int u = component[0], v = node;

			cout << "NO\n";

			memset(vst, false, sizeof(vst));
			if (reachable(u, v)) cout << v << " " << u << '\n';
			else cout << u << " " << v << '\n';
			return 0;
		}
	}

	cout << "YES\n";
	return 0;
}
