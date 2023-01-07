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

const int MAX = 2e5 + 7;

int ds[MAX];
int sz[MAX];
int frep(int x)
{
	return ds[x] == x ? x : ds[x] = frep(ds[x]);
}

void join(int x, int y)
{
	x = frep(x); y = frep(y);
	if (x == y)
		return;
	ds[x] = y;
	sz[y] += sz[x];
}

int par[MAX];
int indegree[MAX];
int res[MAX];

int main()
{
	fastio;

	for (int i = 0; i < MAX; ++i)
		ds[i] = i, sz[i] = 1;

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> par[i];

	for (int i = 1; i <= n; ++i)
		indegree[par[i]]++;

	queue<int> q;
	vector<int> acyclic;
	vector<bool> in_acyclic(n+1, false);
	for (int i = 1; i <= n; ++i)
		if (indegree[i] == 0)
			q.push(i);

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		acyclic.pb(node);
		in_acyclic[node] = true;

		indegree[par[node]]--;
		if (indegree[par[node]] == 0)
			q.push(par[node]);
	}

	for (int i = 1; i <= n; ++i)
		if (!in_acyclic[i])
			join(i, par[i]);

	for (int i = 1; i <= n; ++i)
		if (!in_acyclic[i])
			res[i] = sz[frep(i)];

	while (!acyclic.empty())
	{
		int node = acyclic.back();
		acyclic.pop_back();

		res[node] = res[par[node]] + 1;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (i > 1) cout << " ";
		cout << res[i];
	}
	cout << '\n';

	return 0;
}
