#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x) cerr << "[" << #x << "]: " << x << "\n";

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using pl = pair<ll, ll>;

const ld PI = 4*atan((ld)1);
const int MAX = 1e5 + 69;

int ds[MAX], ind[MAX];
vector<int> adj[MAX], comp[MAX];

inline int frep(int x) { return ds[x] == x ? x : ds[x] = frep(ds[x]); }
inline void join(int x, int y) { ds[frep(x)] = frep(y); }

void solve()
{
	iota(ds, ds + MAX, 0);

	int n, m;
	cin >> n >> m;

	while (m--)
	{
		int u, v; cin >> u >> v;
		join(u, v);

		adj[u].pb(v); ind[v]++;
	};

	queue<int> q;
	for (int i = 1; i <= n; ++i) if (ind[i] == 0)
		q.push(i);

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (int to : adj[node])
		{
			ind[to]--;
			if (ind[to] == 0)
				q.push(to);
		}
	}

	for (int i = 1; i <= n; ++i)
		comp[frep(i)].pb(i);

	int res = 0;
	for (int i = 1; i <= n; ++i) if (!comp[i].empty())
	{
		bool cycle = false;
		for (int x : comp[i]) if (ind[x])
			cycle = true;

		if (cycle) res += (int)comp[i].size();
		else res += (int)comp[i].size() - 1;
	}
	cout << res << '\n';
}

int main()
{
	fastio;

	int TC = 1;
	//cin >> TC;

	while (TC--)
		solve();

	return 0;
}
