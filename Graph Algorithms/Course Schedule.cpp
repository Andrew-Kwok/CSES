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

int main()
{
	fastio;

	int n, m;
	cin >> n >> m;

	vector<int> indegree (n+1, 0);
	vector<vector<int>> adj (n+1);

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].pb(v); indegree[v]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		if (indegree[i] == 0)
			q.push(i);
	}

	vector<int> answer;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		answer.pb(node);
		for (int to : adj[node])
		{
			indegree[to]--;
			if (indegree[to] == 0)
				q.push(to);
		}
	}

	if (answer.size() < n)
	{
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	for (int i = 0; i < answer.size(); ++i)
	{
		if (i) cout << " ";
		cout << answer[i];
	}
	cout << '\n';

	return 0;
}
