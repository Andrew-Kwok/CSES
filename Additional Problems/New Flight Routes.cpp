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
 
vector<ii> ans;

int N, M;
int ds[MAX], ind[MAX];
vector<int> adj[MAX], adjR[MAX], adjScc[MAX];
 
inline int frep(int x) { return ds[x] == x ? x : ds[x] = frep(ds[x]); }
inline void join(int x, int y) { ds[frep(y)] = frep(x); }
 
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

// straighten the graph into a single in and out
inline ii func(vector<int> nodes)
{
	deque <int> q;
	vector<int> in0, out0;
	for (int x : nodes) if (ind[x] == 0)
		q.pb(x), in0.pb(x);

	while (!q.empty())
	{
		int node = q.front(); q.pop_front();
 
		if (adjScc[node].empty())
			out0.pb(node);
 
		for (int to : adjScc[node])
		{
			ind[to]--;
			if (ind[to] == 0)
				q.push_front(to);
		}
	}
 
	int szin = (int)in0.size(), szout = (int)out0.size();
	for (int i = 1; i < max(szin, szout); ++i)
		ans.pb({out0[(i+1) % szout], in0[i % szin]});
	return { in0[0], out0[1 % szout] };
}
 
void solve()
{
	cin >> N >> M;
 
	vector<ii> edges(M);
	for (auto &[u, v] : edges)
	{
		cin >> u >> v;
		adj[u].pb(v); adjR[v].pb(u);
	}
 
	for (int i = 1; i <= N; ++i) if (!vst[i])
		dfs1(i);
	vst.reset();
	reverse(order.begin(), order.end());
 
	iota(ds, ds + MAX, 0);
	for (int node : order) if (!vst[node])
	{
		comp.clear();
		dfs2(node);
		for (int x : comp)
			join(comp[0], x);
 
		if (N == (int)comp.size())
		{
			cout << 0 << '\n';
			return;
		}
	}
 	
 	cerr << '\n';
	for (auto &[u, v] : edges) if (frep(u) != frep(v))
	{
		cerr << frep(u) << " " << frep(v) << '\n';
		adjScc[frep(u)].pb(frep(v)), ind[frep(v)]++;
	}
	return;

	iota(ds, ds + MAX, 0);
	for (auto &[u, v] : edges)
		join(u, v);

	vector<int> nodes[MAX];
	for (int i = 1; i <= N; ++i)
		nodes[frep(i)].pb(i);

	vector<ii> lines;
	for (int i = 1; i <= N; ++i) if (!nodes[i].empty())
	{
		lines.pb(func(nodes[i]));
	}

	int sz = (int)lines.size();
	for (int i = 0; i < sz; ++i)
		ans.pb({lines[i].s2, lines[(i+1) % sz].f1});

	cout << ans.size() << '\n';
	for (auto [x, y] : ans)
		cout << x << " " << y << '\n';
	return;
}
 
int main()
{
	fastio;
 
	int TC = 1;
	//cin >> TC;
 
	while (TC--)
		solve();
 
	return 0;
}