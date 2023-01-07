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
constexpr int MAX = 5e4 + 7;
const string ans[2] = {"NO", "YES"};

int n, m, Q;
int ind[MAX], ds[MAX];
bitset<MAX> res[MAX];
vector<int> adj[MAX], adjR[MAX],adjScc[MAX];

inline int frep(int x) { return ds[x] == x ? x : ds[x] = frep(ds[x]); }
inline void join(int a, int b) { ds[frep(b)] = frep(a); }

bitset<MAX> vst;
vector<int> order, comp;
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
	for (int to : adjR[node])
		if (!vst[to])
			dfs2(to);
	comp.pb(node);
}

int main()
{
	fastio;

	iota(ds, ds+MAX, 0);

	cin >> n >> m >> Q;
	vector<ii> e(m);
	for (auto &[u, v] : e)
	{
		cin >> u >> v;
		adj[v].pb(u); 
		adjR[u].pb(v);
	}

	for (int i = 1; i <= n; ++i)
		if (!vst[i])
			dfs1(i);

	vst.reset();
	reverse(order.begin(), order.end());
	for (int node : order)
		if (!vst[node])
	{
		comp.clear();
		dfs2(node);
			
		for (int x : comp)
			join(x, comp[0]);
	}

	for (auto [u, v] : e)
	{
		if (frep(u) == frep(v))
			continue;
		adjScc[frep(v)].pb(frep(u));
		ind[frep(u)]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; ++i)
		if (i == frep(i) && ind[i] == 0)
			q.push(i);

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		res[node][node] = 1;
		for (int to : adjScc[node])
		{
			res[to] |= res[node];
			if (--ind[to] == 0)
				q.push(to);
		}
	}

	while (Q--)
	{
		int u, v;
		cin >> u >> v;

		cout << ans[res[frep(u)][frep(v)]] << '\n';
	}

	return 0;
}
