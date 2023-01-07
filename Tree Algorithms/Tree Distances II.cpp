#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << "[" << #x << "] :" << x << '\n';

#define pb push_back
#define ll long long

int const N = 2e5 + 7;

int n;
int child[N];
ll res[N];
vector<int> adj[N];

bool vst[N];
void dfs(int node)
{
	vst[node] = true;
	for (int to : adj[node])
	{
		if (!vst[to])
		{
			dfs(to);

			child[node] += child[to];
			res[node] += res[to] + child[to];
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
			ll tmp = res[node] - res[to] - child[to];
			res[to] += tmp + n - child[to];

			reroot(to);
		}
	}
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n-1; ++i)
	{
		int u, v;
		cin >> u >> v;

		adj[u].pb(v); adj[v].pb(u);
	}

	fill(child, child+N, 1);
	dfs(1);

	fill(vst, vst+N, false);
	reroot(1);

	for (int i = 1; i <= n; ++i)
	{
		if (i > 1) cout << " ";
		cout << res[i];
	}
	cout << '\n';

	return 0;
}