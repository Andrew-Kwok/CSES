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

ll ds[MAX];
ll res[MAX];
int ind[MAX] = {};

vector<int> adj[MAX];
vector<int> adjR[MAX];
vector<int> adjScc[MAX];

inline int frep(int x) { return ds[x] < 0 ? x : (int)(ds[x] = frep((int)ds[x])); }
inline void join(int x, int y)
{
	x = frep(x); y = frep(y);
	if (x == y)
		return;
	ds[x] += ds[y];
	ds[y] = x;
}

bool vst[MAX];
vector<int> order, component;
inline void dfs1(int node)
{
	vst[node] = true;
	for (int to : adj[node])
		if (!vst[to])
			dfs1(to);
	order.pb(node);
}

inline void dfs2(int node)
{
	vst[node] = true;
	component.pb(node);

	for (int to : adjR[node])
		if (!vst[to])
			dfs2(to);
}

int main()
{
	fastio;

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		int c; cin >> c;
		ds[i] = -c;
	}

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adjR[v].pb(u);
	}

	memset(vst, false, sizeof(vst));
	for (int i = 1; i <= n; ++i)
		if (!vst[i])
			dfs1(i);

	memset(vst, false, sizeof(vst));
	reverse(order.begin(), order.end());

	for (int node : order)
	{
		if (!vst[node])
		{
			component.clear();
			dfs2(node);

			for (int i = 0; i+1 < (int)component.size(); ++i)
				join(component[i], component[i+1]);
		}
	}


	for (int i = 1; i <= n; ++i)
	{
		for (int to : adj[i])
		{
			if (frep(i) != frep(to))
			{
				adjScc[frep(i)].pb(frep(to));
				ind[frep(to)]++;
			}
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		if (ds[i] < 0 && ind[i] == 0)
		{
			q.push(i);
		}
	}

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		res[node] -= ds[node];
		for (int to : adjScc[node])
		{
			ind[to]--;
			res[to] = max(res[to], res[node]);
			if (ind[to] == 0)
				q.push(to);
		}
	}
	cout << *max_element(res, res + MAX) << '\n';

	return 0;
}
