#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

#define ll long long
#define pb push_back
#define ii pair<int, int>
#define f1 first
#define s2 second

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int V, int U, long long Cap) : v(V), u(U), cap(Cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int N, int S, int T) : n(N), s(S), t(T) {
        adj.resize(n+1);
        level.resize(n+1);
        ptr.resize(n+1);
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

    long long maxflow() {
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

    void solve()
    {
        ll mf = maxflow();
        cout << mf << '\n';

        for (int rep = 0; rep < mf; ++rep)
        {       
            vector<ii> par(n+1, {-1, -1});
            vector<bool> vst(n+1, false);
            while (!q.empty()) q.pop();

            q.push(s);
            vst[s] = true;

            const auto bfs = [&]() -> void
            {
                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    for (int id : adj[node])
                    {
                        int to = edges[id].u;
                        if (!vst[to] && edges[id].flow)
                        {
                            par[to] = {node, id};
                            
                            if (to == t)
                                return;
                            else if (!vst[to])
                            {
                                par[to] = {node, id};
                                vst[to] = true;
                                q.push(to);
                            }
                        }
                    }
                }
            };
            bfs();

            vector<int> sk;
            for (int cur = t; cur != s; cur = par[cur].f1)
            {
                sk.pb(par[cur].f1);
                edges[par[cur].s2].flow--;
            }

            cout << sk.size() + 1<< '\n';
            while (!sk.empty())
                cout << sk.back() << " ", sk.pop_back();
            cout << t << '\n';
        }


    }
};


int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	Dinic dinic(n, 1, n);
	for (int i = 0; i < m; ++i)
	{
		int u, v; cin >> u >> v;
		dinic.add_edge(u, v, 1);
	}

    dinic.solve();

	return 0;
}