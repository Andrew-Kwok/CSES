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
const int MAXN = 1e5 + 69;
const int MAXE = 4e5 + 69;
const int flow_inf = 0x3f3f3f3f;

int source = MAX-2, sink = MAX-1;
int cc_head[MAX], ind[MAX], outd[MAX], match[MAX];
 
struct Dinic {

	int from[MAXE] = {}, to[MAXE] = {}, cap[MAXE] = {}, prv[MAXE] = {}, head[MAXN] = {}, pt[MAXN] = {}, ec = 0;
	void add_edge(int u, int v, int uv, int vu = 0){
		// cerr << "add edge: " << u << " -> " << v << " " << uv << '\n';
 
		from[ec] = u, to[ec] = v, cap[ec] = uv, prv[ec] = head[u], head[u] = ec++;
		from[ec] = v, to[ec] = u, cap[ec] = vu, prv[ec] = head[v], head[v] = ec++;
	}
 
 
	int lv[MAXN], q[MAXN];
	bool bfs() {
		memset(lv, 63, sizeof(lv));
		int h = 0, t = 0;
		lv[source] = 0;
		q[t++] = source;
		while (t-h) {
			int v = q[h++];
			for (int e = head[v]; ~e; e = prv[e]) {
				if (cap[e] && lv[v] + 1 < lv[to[e]]) {
					lv[to[e]] = lv[v] + 1;
					q[t++] = to[e];
				}
			}
		}
		// cerr << lv[sink] << '\n';

		return lv[sink] < 1e8;
	}
 
	int dfs(int v, vector<int> &path, int f = 1e9) {
		if (v == sink || f == 0)
			return f;
		for (int &e = pt[v]; ~e; e = prv[e]) {
			if (lv[v]+1 == lv[to[e]]) {
				int tr = min(f, dfs(to[e], path, min(f, cap[e])));
				if (tr == 0) continue;

				path.pb(to[e]);
				cap[e] -= tr;
				cap[e^1] += tr;
				return tr;
			}
		}
		return 0;
	}
 
	int flow() { 
		int ret = 0;
		vector<int> path;
		while (bfs()) { 
			memcpy(pt, head, sizeof(head));
			while (int f = dfs(source, path)) {
				ret += f;
			
				path.pb(source);
				reverse(path.begin(), path.end());
 	
 				// cerr << "flow: " << f << '\n';
	            // cerr << "SZ: " << path.size() << '\n';
	            // cerr << "path: ";
	            // for (int x : path)
	            // 	cerr << x << ", ";
	            // cerr << '\n';
 
	            assert(path.size() >= 3);
	            assert(path[0] == source);
	            assert(path.back() == sink);
 
	            int p = -1;
	            for (int u : path) 
	            {
	            	if (u == source || u == sink)
	            		continue;

	            	if (ind[u] == 0) {
	            		if (p != -1) match[p] = match[u];
	            		p = u;
	            	} 
	            	if (outd[u] == 0) {
	            		assert(p != -1);
	            		match[p] = u;
	            	}

	            }
	            // match[p] = path[(int)path.size() - 2];
	            path.clear();
			}
		}
		return ret;
	}



    // struct FlowEdge {
    //     int v, u;
    //     int cap, flow = 0;
    //     FlowEdge(int V, int U, int Cap) : v(V), u(U), cap(Cap) {}
    // };
 
    // vector<FlowEdge> edges;
    // vector<int> adj[MAX];
    // int n, m = 0;
    // int s, t;
    // vector<int> level, ptr;
    // queue<int> q;
 
    // Dinic(int N, int S, int T) : n(N), s(S), t(T) {
    //     level.resize(n);
    //     ptr.resize(n);
    // }
 
    // void add_edge(int v, int u, int cap) {
    //     edges.emplace_back(v, u, cap);
    //     edges.emplace_back(u, v, 0);
    //     adj[v].push_back(m);
    //     adj[u].push_back(m + 1);
    //     m += 2;
    // }
 
    // bool bfs() {
    //     while (!q.empty()) {
    //         int v = q.front();
    //         q.pop();
    //         for (int id : adj[v]) {
    //             if (edges[id].cap - edges[id].flow < 1)
    //                 continue;
    //             if (level[edges[id].u] != -1)
    //                 continue;
    //             level[edges[id].u] = level[v] + 1;
    //             q.push(edges[id].u);
    //         }
    //     }
    //     return level[t] != -1;
    // }
 
    // int dfs(int v, int pushed, vector<int> &path) {
    //     if (pushed == 0)
    //         return 0;
    //     if (v == t) {
    //         return pushed;
    //     }
    //     for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
    //         int id = adj[v][cid];
    //         int u = edges[id].u;

    //         if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
    //             continue;
    //         int tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow), path);
    //         if (tr == 0)
    //             continue;
    //         path.pb(u);
    //         edges[id].flow += tr;
    //         edges[id ^ 1].flow -= tr;
    //         return tr;
    //     }
    //     return 0;
    // }
 
    // int flow() {
    //     int f = 0;
	// 	const auto isIn = [&](int u) -> bool
    //     {
    //     	if (u == s || u == t)
    //     		return false;
 
    //     	return ind[u] == 0;
    //     };
 
    //     // const auto isOut = [&](int u) -> bool
    //     // {
    //     // 	if (u == s || u == t)
    //     // 		return false;
    //     // 	return u == frep(u) && outd[u] == 0;
    //     // };
 
    //     while (true) {
    //         fill(level.begin(), level.end(), -1);
    //         level[s] = 0;
    //         q.push(s);
    //         if (!bfs())
    //             break;
    //         fill(ptr.begin(), ptr.end(), 0);
 
    //         vector<int> path;
    //         while (int pushed = dfs(s, flow_inf, path)) {
    //             f += pushed;
    //             path.pb(s);
    //             reverse(path.begin(), path.end());
 
    //             if (pushed) {
	// 	            // cerr << "SZ: " << path.size() << '\n';
	// 	            // cerr << "path: ";
	// 	            // for (int x : path)
	// 	            // 	cerr << x << ", ";
	// 	            // cerr << '\n';
 
	// 	            assert(path.size() >= 3);
	// 	            assert(path[0] == 0);
	// 	            assert(path.back() == MAX-1);
 
	// 	            int prv = -1;
	// 	            for (int u : path)
	// 	            {
	// 	            	if (isIn(u)) {
	// 	            		if (prv == -1) prv = u;
	// 	            		else 
	// 	            		{
	// 	            			match[prv] = match[u];
	// 	            			prv = u;
	// 	            		}
	// 	            	}
 	// 	            }
	// 	            match[prv] = path[(int)path.size() - 2];
 
	//                 path.clear();
    //             }
 
    //         }
    //     }
    //     return f;
    // }
} dinic;
 
 
vector<int> adj[MAX], adjR[MAX];

bitset<MAX> vst;
vector<int> order;
inline void dfs1(int node)
{
	vst[node] = true;
	for (int to : adj[node])
		if (!vst[to])
			dfs1(to);
	order.pb(node);
}
 
inline void dfs2(int node, int h)
{
	vst[node] = true;
	for (int to : adjR[node])
		if (!vst[to])
			dfs2(to, h);
	cc_head[node] = h;
}

int dfs(int node)
{
	vst[node] = true;
	if (adj[node].empty())
		return node;
	for (int to : adj[node]) if (!vst[to])
	{
		int res = dfs(to);
		if (~res)
			return res;
	}
	return -1;
}
 
void solve()
{
	memset(dinic.head, -1, sizeof(dinic.head));
	memset(match, -1, sizeof(match));

	int N, M;
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
 
	int cc_count = 0;
	for (int node : order) if (!vst[node])
	{
		dfs2(node, node);
		cc_count++;
	}
	if (cc_count == 1) 
	{
		cout << 0 << '\n';
		return;
	}
	
 	for (auto &[u, v] : edges) {
 		u = cc_head[u], v = cc_head[v];
 	}
 	sort(edges.begin(), edges.end());
 	edges.resize(unique(edges.begin(), edges.end()) - edges.begin());

 	if (N <= 30069) {
		for (auto &[u, v] : edges) if (u != v)
		{
			outd[u]++; ind[v]++;
			dinic.add_edge(u, v, flow_inf);
		}
	 
		for (int i = 1; i <= N; ++i) if (i == cc_head[i])
		{
			if (ind[i] == 0) dinic.add_edge(source, i, 1);
			if (outd[i] == 0) dinic.add_edge(i, sink, 1);
		}
	 	memset(match, -1, sizeof(match));
		dinic.flow();
 	} else {
 		for (int i = 1; i <= N; ++i) adj[i].clear();
 		for (auto &[u, v] : edges) if (u != v) {
 			outd[u]++; ind[v]++;
 			adj[u].pb(v);
 		}

 		vst.reset();
		for (int i = 1; i <= N; ++i) if (i == cc_head[i] && ind[i] == 0)
		{
			match[i] = dfs(i);
			if (match[i] != -1)
				match[match[i]] = i;
		}
 	}

  
	vector<int> I, O; vst.reset();
	for (int i = 1; i <= N; ++i) if (i == cc_head[i] && ind[i] == 0)
	{
		if (match[i] == -1) continue;
		I.pb(i); O.pb(match[i]);
		vst[i] = true; vst[match[i]] = true;
	}
	
	for (int i = 1; i <= N; ++i) if (i == cc_head[i])
	{
		if (vst[i]) continue;
		if (ind[i] == 0) I.pb(i);
		if (outd[i] == 0) O.pb(i);
	}
 
	// cerr << I.size() << '\n';
	// for (int x : I) cerr << x << ", ";
	// cerr << '\n';
	// cerr << O.size() << '\n';
	// for (int x : O) cerr << x << ", ";
	// cerr << '\n';
 
	while (I.size() < O.size()) I.pb(I[0]);
	while (O.size() < I.size()) O.pb(O[0]);
	cout << I.size() << '\n';
	for (int i = 0; i+1 < (int)I.size(); ++i)
		cout << O[i+1] << " " << I[i] << '\n';
	cout << O[0] << " " << I.back() << '\n';
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