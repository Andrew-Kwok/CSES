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
const int MAX = 2569;
const int inf = 1e9 + 69;

static int ans = inf;

int N, M;
vector<int> adj[MAX];

int pos[MAX];
vector<int> sk;
bitset<MAX> vst;
void dfs(int node)
{
	vst[node] = true;
	pos[node] = (int)sk.size();
	sk.pb(node);

	for (int to : adj[node])
	{
		if (!vst[to])
		{
			dfs(to);
		}
		else if (pos[to] != -1)
		{
			if (sk.size() >= 2 && sk[(int)sk.size() - 2] == to)
				continue;

			ans = min(ans, (int)sk.size() - pos[to]);
		}
	}

	pos[node] = -1;
	sk.pop_back();
}

void solve()
{
	cin >> N >> M;
	while (M--)
	{
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}

	for (int i = 1; i <= N; ++i)
	{
		vst.reset();
		memset(pos, -1, sizeof(pos));
		dfs(i);
	}

	cout << (ans == inf ? -1 : ans) << '\n';
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
