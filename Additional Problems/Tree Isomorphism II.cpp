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

int n;
vector<int> adj[2][MAX];
map<vector<int>, int> memo;

inline vector<int> centroid(int i)
{
	int sz[MAX] = {};
	vector<int> res;
	const auto dfs = [&](const auto &self, int node, int par) -> void
	{
		sz[node] = 1;
		bool ok = true;
		for (int to : adj[i][node]) if (to != par)
		{
			self(self, to, node);
			sz[node] += sz[to];
			if (sz[to] > n/2)
				ok = false;
		}
		if (n - sz[node] > n/2) ok = false;
		if (ok) res.pb(node);
	};
	dfs(dfs, 1, -1);

	return res;
}

static int ctr = 0;
inline int dfs(int i, int node, int par)
{
    vector<int> child;
    for (int to : adj[i][node]) if (to != par)
        child.pb(dfs(i, to, node));
    sort(child.begin(), child.end());

    if (!memo.count(child))
        memo[child] = ctr++;
    return memo[child];
}

void solve()
{
	cin >> n;

    memo.clear();
    for (int j = 0; j < 2; ++j)
    {
        for (int i = 1; i <= n; ++i)
            adj[j][i].clear();
    }

    vector<int> C[2];
	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < n-1; ++i)
		{
			int u, v; cin >> u >> v;
            adj[j][u].pb(v);
            adj[j][v].pb(u);
		}
		C[j] = centroid(j);
	}

	if (C[0].size() != C[1].size())
	{
		cout << "NO\n";
		return;
	}
	else if (C[0].size() == 1)
	{
		cout << (dfs(0, C[0][0], -1) == dfs(1, C[1][0], -1) ? "YES\n" : "NO\n");
	}
	else
	{
		cout << (dfs(0, C[0][0], -1) == dfs(1, C[1][0], -1) || dfs(0, C[0][0], -1) == dfs(1, C[1][1], -1) ? "YES\n" : "NO\n");
	}
}

int main()
{
	fastio;

	int TC = 1;
	cin >> TC;

	while (TC--)
		solve();

	return 0;
}
