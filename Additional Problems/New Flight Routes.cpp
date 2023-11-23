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
int ds[MAX], ind[MAX], outd[MAX];
vector<int> adj[MAX], adjR[MAX];
 
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

struct Dinic {
    struct FlowEdge {
        int v, u;
        long long cap, flow = 0;
        FlowEdge(int V, int U, long long Cap) : v(V), u(U), cap(Cap) {}
    };

    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int N, int S, int T) : n(N), s(S), t(T) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};
 
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
 	
	set<ii> sccEdges;
	Dinic dinic(N+2, 0, N+1);
	for (auto &[u, v] : edges) if (frep(u) != frep(v))
	{
		if (sccEdges.count({frep(u), frep(v)}))
			continue;
		sccEdges.insert({frep(u), frep(v)});
		dinic.add_edge(frep(u), frep(v), 1);

		outd[frep(u)]++;
		ind[frep(v)]++;
	}

	for (int i = 1; i <= N; ++i) if (i == frep(i))
	{
		if (outd[i] == 0) dinic.add_edge(i, N+1, 1);
		if (ind[i] == 0) dinic.add_edge(0, i, 1);
	}

	cout << dinic.flow() << '\n';


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