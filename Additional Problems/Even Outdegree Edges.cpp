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

bool even[MAX];
vector<ii> adj[MAX];

bitset<MAX> vst;
bitset<2 * MAX> used;
vector<ii> res;

int ctr = 0;
inline void dfs(int node)
{
	vst[node] = true;
	for (auto [to, id] : adj[node]) if (!used[id])
	{
		ctr++;
		used[id] = true;
		if (!vst[to])
			dfs(to);
	
		if (!even[to])
		{
			even[to] ^= 1;
			res.pb({to, node});
		}
		else
		{
			even[node] ^= 1;
			res.pb({node, to});
		}
	}
}

void solve()
{
	int n, m;
	cin >> n >> m;

	while (m--)
	{
		int u, v; cin >> u >> v;
		adj[u].pb({v, m}); adj[v].pb({u, m});
	}

	fill(even, even + MAX, true);
	for (int i = 1; i <= n; ++i) if (!vst[i])
		dfs(i);

	for (int i = 1; i <= n; ++i) if (!even[i])
	{
		cout << "IMPOSSIBLE\n";
		return;
	}

	for (auto &[u, v] : res)
		cout << u << " " << v << '\n';
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
