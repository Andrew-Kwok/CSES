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

int main()
{
	fastio;

	int n, m;
	cin >> n >> m;

	vector<int> indegree(n+1, 0);
	vector<vector<int>> adj(n+1);
	vector<int> len(n+1, 1);
	vector<int> par(n+1, -1);

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
	}

	vector<int> vst(n+1, 0);
	{
		queue<int> q;
		for (q.push(1); !q.empty(); q.pop())
		{
			int node = q.front();
			for (int to : adj[node])
			{
				indegree[to]++;
				if (!vst[to])
				{
					vst[to] = true;
					q.push(to);
				}
			}
		}
	}

	queue<int> q;
	for (q.push(1); !q.empty(); q.pop())
	{
		int node = q.front();
		for (int to : adj[node])
		{
			if (len[to] < len[node] + 1)
			{
				len[to] = len[node] + 1;
				par[to] = node;
			}

			indegree[to]--;
			if (indegree[to] == 0)
				q.push(to);
		}
	}

	vector<int> path;
	for (int node = n; node != -1; node = par[node])
	{
		path.pb(node);
		if (node == 1)
		{
			cout << path.size() << '\n';
			for (; !path.empty(); path.pop_back())
				cout << path.back() << " ";
			cout << '\n';

			return 0;
		}
	}
	
	cout << "IMPOSSIBLE\n";
	return 0;
}
