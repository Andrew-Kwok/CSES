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

const int MAX = 69;

int n;
int row[MAX], col[MAX];
char mat[MAX][MAX];

void solve()
{
	cin >> n;
	
	int rsum = 0, csum = 0;;
	for (int i = 1; i <= n; ++i)
		cin >> row[i], rsum += row[i];
	for (int i = 1; i <= n; ++i)
		cin >> col[i], csum += col[i];

	if (rsum != csum)
	{
		cout << -1 << '\n';
		return;
	}

	Dinic D(2*n+2, 0, 2*n+1);
	for (int i = 1; i <= n; ++i)
		D.add_edge(0, i, row[i]);
	for (int i = 1; i <= n; ++i)
		D.add_edge(n+i, 2*n+1, col[i]);
	for (int i = 1; i <= n; ++i)
		for (int j = n+1; j <= 2*n; ++j)
			D.add_edge(i, j, 1);

	ll flow = D.flow();
	if (flow != rsum)
	{
		cout << -1 << '\n';
		return;
	}

	for (auto E : D.edges)
	{
		if (1 <= E.v && E.v <= n && n+1 <= E.u && E.u <= 2*n)
			mat[E.v][E.u - n] = ".X"[E.cap == E.flow];
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
			cout << mat[i][j];
		cout << '\n';
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
