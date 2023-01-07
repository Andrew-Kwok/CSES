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

struct MCMF
{
    static constexpr int inf = 1e9 + 69;

    int N, M, S, T;
    vector<vector<ii>> adj;
    vector<int> capacity, cost;

    MCMF(int n, int s, int t) : N(n), M(0), S(s), T(t)
    {
        adj.assign(N, vector<ii>());
        capacity.clear();
        cost.clear();
    }

    // from, to, cost, capacity
    inline void addEdge(int u, int v, int w, int cap)
    {
        adj[u].pb({v, M}); adj[v].pb({u, M^1});
        cost.pb(w); cost.pb(-w);
        capacity.pb(cap); capacity.pb(0);
        M += 2;
    }

    // dist: cost to each node
    // par: parent 
    inline void shortest_paths(vector<int> &dist, vector<ii> &par)
    {
        dist.assign(N, inf); par.assign(N, {-1,- 1});
        dist[S] = 0;
        
        queue<int> q;
        vector<bool> inq(N, false);

        q.push(S); inq[S] = true;
        while (!q.empty())
        {
            int node = q.front();
            q.pop(); inq[node] = false;

            for (auto [to, id] : adj[node]) if (capacity[id] > 0 && dist[to] > dist[node] + cost[id])
            {
                dist[to] = dist[node] + cost[id];
                par[to] = {node, id};
                if (!inq[to])
                    q.push(to), inq[to] = true;
            }
        }
    }

    inline int solve(int K)
    {
        int flow = 0, sum = 0;
        vector<int> dist;
        vector<ii> par;

        while (flow < K)
        {
            shortest_paths(dist, par);
            if (dist[T] == inf)
                break;

            // finding max flow path
            int f = K - flow;
            vector<int> path;
            for (int cur = T; cur != S; cur = par[cur].f1)
                f = min(f, capacity[par[cur].s2]), path.pb(cur);

            // path.pb(S);
            // reverse(path.begin(), path.end());
            // for (int x : path)
            //  cerr << x << ", ";
            // cerr << '\n';

            flow += f;
            sum += f * dist[T];
            for (int cur = T; cur != S; cur = par[cur].f1)
            {   
                capacity[par[cur].s2] -= f;
                capacity[par[cur].s2 ^ 1] += f;
            }
        }

        if (flow < K)
            return -1;
        return sum;
    }
};

const int MAX = 69;

int n;
int row[MAX], col[MAX], val[MAX][MAX];

char mat[MAX][MAX];

void solve()
{
	cin >> n;
	
	int sum = 0;
	for (int i = 1; i <= n; ++i)
		cin >> row[i], sum += row[i];
	for (int i = 1; i <= n; ++i)
        cin >> col[i];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cin >> val[i][j];
    }

	MCMF mcmf(2*n+2, 0, 2*n+1);
	for (int i = 1; i <= n; ++i)
		mcmf.addEdge(0, i, 0, row[i]);
	for (int i = 1; i <= n; ++i)
		mcmf.addEdge(n+i, 2*n+1, 0, col[i]);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
            mcmf.addEdge(i, j+n, -val[i][j], 1);

    ll cost = mcmf.solve(sum);
	if (cost == -1)
	{
		cout << -1 << '\n';
		return;
	}

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            mat[i][j] = '.';

    for (int node = 1; node <= n; ++node)
    {
        for (auto [to, id] : mcmf.adj[node])
        {
            if (id % 2 == 0 && mcmf.capacity[id] == 0)
                mat[node][to - n] = 'X';
        }
    }

    cout << -cost << '\n';
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
