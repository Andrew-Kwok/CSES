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

	int n;
	cin >> n;

	vector<int> res(n+1, 0);
	vector<int> par(n+1, 0);
	vector<int> indegree(n+1, 0);
	for (int i = 2; i <= n; ++i)
	{
		int p;
		cin >> p;

		par[i] = p;
		indegree[p]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		res[par[node]] += 1 + res[node];
		
		indegree[par[node]]--;
		if (indegree[par[node]] == 0)
			q.push(par[node]);
	}

	for (int i = 1; i <= n; ++i)
	{
		if (i > 1) cout << " ";
		cout << res[i];
	}
	cout << '\n';

	return 0;
}
