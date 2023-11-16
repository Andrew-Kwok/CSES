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
const int MAX = 2569;
const int inf = 1e9 + 69;
 
int N, M;
vector<int> adj[MAX];
 
int dist[MAX];
int bfs(int node)
{
	queue<int> q;
	dist[node] = 0;
	q.push(node);
 
	int res = inf;
	while (!q.empty())
	{
		node = q.front(); q.pop();
		for (int to : adj[node])
		{
			if (dist[to] == -1)
			{
				dist[to] = dist[node] + 1;
				q.push(to);
			}
			else if (dist[to] >= dist[node])
				res = min(res, dist[node] + dist[to] + 1);
		}
	}
	return res;
}
 
void solve()
{
	cin >> N >> M;
	while (M--)
	{
		int u, v; cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}
 
	int res = inf;
	for (int i = 1; i <= N; ++i)
	{
		memset(dist, -1, sizeof(dist));
		res = min(res, bfs(i));
	}
 
	cout << (res == inf ? -1 : res) << '\n';
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