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
const ll inf = 1e18 + 69;
 
int N, M;
vector<int> adj[MAX];
 
vector<int> par[MAX];
ll dist[MAX];
 
void solve()
{
	cin >> N >> M;
	while (M--)
	{
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
	}	
 
	fill(dist, dist + MAX, inf);
	dist[1] = 0;
	queue<int> q;

	q.push(1);
	while (!q.empty())
	{
		int node = q.front(); q.pop();
		for (int to : adj[node])
		{
			if (dist[to] > dist[node] + 1)
			{
				dist[to] = dist[node] + 1;
				par[to] = { node };
				q.push(to);
			}
			else par[to].pb(node);
		}
	}
 
	vector<int> res;
	
	struct Item
	{
		int node;
		Item(int _node = 0) : node(_node) {} 
		bool operator< (const Item& rhs) const { return dist[node] < dist[rhs.node]; }
	};

	bitset<MAX> vst;
	priority_queue<Item> pq;
	
	vst[N] = true;
	pq.push(Item(N));

	while (!pq.empty())
	{
		int node = pq.top().node;
		pq.pop();

		if (pq.empty())
			res.pb(node);

		for (int to : par[node]) if (!vst[to])
			vst[to] = true, pq.push(to);
	}
 
	sort(res.begin(), res.end());
	cout << res.size() << '\n';
	for (int x : res)
		cout << x << " ";
	cout << '\n';
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
