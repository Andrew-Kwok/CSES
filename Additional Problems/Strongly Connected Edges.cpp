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

int N, M;
vector<ii> adj[MAX];

bitset<MAX> vst;
bitset<2*MAX> used;

bool impos = false;
vector<ii> ans;

int disc[MAX], low[MAX];
static int cur_ctr = 0;
void dfs(int node, int par)
{
	vst[node] = true;
	disc[node] = low[node] = cur_ctr++;
	for (auto [to, id] : adj[node])
	{
		if (disc[to] == -1)
		{
			if (!used[id])
				ans.pb({node, to}), used[id] = true;

			dfs(to, node);
			low[node] = min(low[node], low[to]);
			if (low[to] > disc[node])
				impos = true;
		}
		else if (to != par)
		{
			if (!used[id])
				ans.pb({node, to}), used[id] = true;
			low[node] = min(low[node], disc[to]);
		}
	}
}

void solve()
{
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int u, v; cin >> u >> v;
		adj[u].pb({v, i});
		adj[v].pb({u, i});
	}

	memset(disc, -1, sizeof(disc));
	dfs(1, -1);

	for (int i = 1; i <= N; ++i)
		if (disc[i] == -1)
			impos = true;

	if (impos)
	{
		cout << "IMPOSSIBLE\n";
		return;
	}

	for (auto &[u, v] : ans)
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
