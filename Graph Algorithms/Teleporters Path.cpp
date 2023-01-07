#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

#define pb push_back

const int MAX = 1e5 + 69;

inline void impos() { cout << "IMPOSSIBLE\n"; exit(0); }

int n, m;
int in[MAX] = {}, out[MAX] = {};
vector<int> adj[MAX];

int ds[MAX];
inline int frep(int x) { return ds[x] == x ? x : ds[x] = frep(ds[x]); }
inline void join(int x, int y) { ds[frep(x)] = frep(y); }

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	iota(ds, ds + MAX, 0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;

		join(u, v);

		out[u]++; in[v]++;
		adj[u].pb(v);
	}

	if (out[1] - in[1] != 1) impos();
	if (in[n] - out[n] != 1) impos();
	for (int i = 2; i < n; ++i)
		if (in[i] != out[i])
			impos();

	for (int i = 1; i <= n; ++i)
	{
		if (!adj[i].empty() && frep(i) != frep(1))
			impos();
	}

	vector<int> path, res;
	path.pb(1);

	while (!path.empty())
	{
		int node = path.back();
		if (!adj[node].empty())
		{
			path.pb(adj[node].back());
			adj[node].pop_back();
		}
		else
		{
			res.pb(node);
			path.pop_back();
		}
	}

	for (auto it = res.rbegin(); it != res.rend(); ++it)
		cout << *it << " ";
	cout << '\n';


	return 0;
}