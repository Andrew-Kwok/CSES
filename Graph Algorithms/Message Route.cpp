#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x...) cerr << "[" << #x << "]: " << x << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;

ld const PI = 4*atan((ld)1);

int const N = 1e5 + 7;

int par[N];
bool vst[N];
vector<int> adj[N];

int main()
{
	fastio;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}

	for (int i = 1; i <= n; ++i)
		par[i] = i;

	int node = 1;
	vst[node] = true;

	queue<int> q;
	q.push(node);

	while (!q.empty())
	{
		node = q.front();
		q.pop();

		for (int to : adj[node])
			if (!vst[to])
		{
			vst[to] = true;
			par[to] = node;
			q.push(to);

			if (to == n)
			{
				while (!q.empty())
					q.pop();
			}
		}
	}

	if (par[n] == n)
	{
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	vector<int> res;

	node = n;
	for (; par[node] != node; node = par[node])
		res.pb(node);
	reverse(res.begin(), res.end());

	cout << res.size() + 1 << '\n' << 1;
	for (auto x : res)
		cout << " " << x;
	cout << '\n';

	return 0;
}
