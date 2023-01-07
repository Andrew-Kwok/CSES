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
const int MAX = 269;

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
	int N;
	cin >> N;

	char s[MAX];
    set<int> adj2[MAX];

	Dinic D(2*N+2, 0, 2*N+1);
	for (int i = 1; i <= N; ++i)
		D.add_edge(0, i, 1);
	for (int i = N+1; i <= 2*N; ++i)
		D.add_edge(i, 2*N+1, 1);

	for (int i = 1; i <= N; ++i)
	{
		cin >> (s+1);
		for (int j = 1; j <= N; ++j)
		{
			if (s[j] == 'o')
            {
				D.add_edge(i, N+j, 1);
                adj2[i].insert(N+j);
            }
		}
	}

    int res = (int)D.flow();
	cout << res << '\n';

    set<int> st;
    for (int i = 1; i <= N; ++i)
    {
        st.insert(i);
        for (int id : D.adj[i])
        {
            if (id % 2 == 0 && D.edges[id].cap == D.edges[id].flow)
            {
                adj2[i].erase(D.edges[id].u);
                adj2[D.edges[id].u].insert(i);
                st.erase(i);
            }
        }
    }

    vector<bool> vst(MAX, false);
    const auto dfs = [&](const auto &self, int node) -> void
    {
        vst[node] = true;
        for (int to : adj2[node])  if (!vst[to])
            self(self, to);
    };

    for (int node : st)
        if (!vst[node])
            dfs(dfs, node);

    for (int i = 1; i <= N; ++i)
    {
        if (!vst[i]) cout << 1 << " " << i << '\n';
        if (vst[i+N]) cout << 2 << " " << i << '\n';
    }
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
