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
			// 	cerr << x << ", ";
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

	inline void backtrack(int K)
	{
		vector<int> path;
		vector<bool> vst(M, false);
		const auto dfs = [&](const auto &self, int node) -> void
		{
			path.pb(node);
			if (node == T)
				return;

			for (auto [to, id] : adj[node]) if (id % 2 == 0 && capacity[id] == 0 && !vst[id])
			{
				vst[id] = true;
				self(self, to);
				return;
			}
		};

		for (int i = 0; i < K; ++i)
		{
			path.clear();
			dfs(dfs, S);

			cout << path.size() << '\n';
			for (int x : path)
				cout << x+1 << " ";
			cout << '\n';
		}
	}
};

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;

	MCMF mcmf(n, 0, n-1);
	while (m--)
	{
		int u, v; cin >> u >> v;
		mcmf.addEdge(u-1, v-1, 1, 1);
	}

	int res = mcmf.solve(k);
	cout << res << '\n';

	if (res == -1)
		return;
	mcmf.backtrack(k);
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
