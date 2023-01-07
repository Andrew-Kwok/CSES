#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define pb push_back
#define ii pair<int, int>

const int MAX = 1e5 + 69;

int n, m;
int ctr[MAX] = {};
bool used[2 * MAX];
vector<ii> adj[MAX];

int ds[MAX];
inline int frep(int x) { return ds[x] < 0 ? x : ds[x] = frep(ds[x]); }
inline void join(int x, int y)
{
	x = frep(x); y = frep(y);
	if (x == y)
		return;
	ds[x] += ds[y];
	ds[y] = x;
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(ds, -1, sizeof(ds));

	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;

		join(u, v);

		ctr[u]++; ctr[v]++;
		adj[u].pb({v, i}); adj[v].pb({u, i});
	}

	for (int i = 1; i <= n; ++i)
	{
		if (!adj[i].empty() && frep(i) != frep(1))
		{
			cout << "IMPOSSIBLE\n";
			return 0;	
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		if (ctr[i] & 1)
		{
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}

	vector<int> path, res;
	path.pb(1);
	while (!path.empty())
	{
		int node = path.back();
		if (!adj[node].empty())
		{
			auto [to, id] = adj[node].back();
			if (!used[id])
			{
				used[id] = true;
				path.pb(to);
			}
			adj[node].pop_back();
		}
		else
		{
			res.pb(node);
			path.pop_back();
		}
	}

	for (int x : res)
		cout << x << " ";
	cout << '\n';

	return 0;
}