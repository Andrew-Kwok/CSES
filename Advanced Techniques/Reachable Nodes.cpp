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

ld const PI = 4*atan((ld)1);
const int MAX = 5e4 + 7;

int n, m;
int ind[MAX];
bitset<MAX> res[MAX];
vector<int> adj[MAX];

int main()
{
	fastio;

	cin >> n >> m;
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		adj[v].pb(u); ind[u]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; ++i)
		if (ind[i] == 0)
			q.push(i);

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		res[node][node] = 1;
		for (int to : adj[node])
		{
			res[to] |= res[node];
			if (--ind[to] == 0)
				q.push(to);
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << res[i].count() << " \n"[i == n];

	return 0;
}
