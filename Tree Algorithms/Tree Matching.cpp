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
int const N = 2e5 + 7;
int const inf = 2e9 + 7;

vector<int> adj[N];
int dp[N][2]; //1: use

bool vst[N];
void dfs(int node)
{
	vst[node] = true;
	
	int mn = inf;
	for (int to : adj[node])
	{
		if (!vst[to])
		{
			dfs(to);
			
			dp[node][0] += max(dp[to][0], dp[to][1]);
	
			if (dp[to][0] >= dp[to][1]) mn = 0;
			else mn = min(mn, dp[to][1]);
		}
	}

	if (mn != inf)
		dp[node][1] = 1 + dp[node][0] - mn;
}

int main()
{
	fastio;

	int n;
	cin >> n;

	for (int i = 0; i < n-1; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1);

	//for (int i = 1; i <= n; ++i)
	//	cout << i << ": " << dp[i][0] << " " << dp[i][1] << '\n';

	cout << max(dp[1][0], dp[1][1]) << '\n';

	return 0;
}
