#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

int const N = 2e5 + 7;

int Start[N];
int Finish[N];
vector<int> euler;
vector<int> adj[N];

bool vst[N];
void dfs(int node)
{
	vst[node] = true;

	Start[node] = Finish[node] = euler.size();
	euler.pb(node);
	for (int to : adj[node])
	{
		if (!vst[to])
		{
			dfs(to);

			Finish[node] = euler.size();
			euler.pb(node);
		}
	}
}

ll ar[N];
ll bit[2*N];
void add(int x, ll val)
{
	while (x < 2*N)
		bit[x] += val, x += (x & -x);
}

ll sum(ll x)
{
	ll res = 0;
	while (x)
		res += bit[x], x -= (x & -x);
	return res;
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; ++i)
		cin >> ar[i];

	for (int i = 0; i < n-1; ++i)
	{
		int u, v;
		cin >> u >> v;

		adj[u].pb(v); adj[v].pb(u);
	}

	euler.pb(-1);
	dfs(1);

	for (int i = 1; i <= n; ++i)
	{
		add(Start[i], ar[i]);
	}

	while (q--)
	{
		int t;
		cin >> t;

		if (t == 1)
		{
			int s, x;
			cin >> s >> x;

			add(Start[s], x - ar[s]);

			ar[s] = x;
		}
		else
		{
			int s;
			cin >> s;

			cout << sum(Finish[s]) - sum(Start[s] - 1) << '\n';
		}
	}

	return 0;
}