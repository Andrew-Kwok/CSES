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

vector<int> adj[2][MAX];
map<vector<int>, int> memo;

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
	int n;
	cin >> n;

    memo.clear();
    for (int j = 0; j < 2; ++j)
    {
        for (int i = 1; i <= n; ++i)
            adj[j][i].clear();
    }

	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < n-1; ++i)
		{
			int u, v; cin >> u >> v;
            adj[j][u].pb(v);
            adj[j][v].pb(u);
		}
	}

	cout << (dfs(0, 1, -1) == dfs(1, 1, -1) ? "YES\n" : "NO\n");
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
