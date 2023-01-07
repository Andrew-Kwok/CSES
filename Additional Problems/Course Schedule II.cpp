#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
#define pb push_back
 
const int MAX = 1e5 + 69;
 
int n;
int ind[MAX];
vector<int> adj[MAX];
 
int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int m;
	cin >> n >> m;
 
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		
		adj[v].pb(u); ind[u]++;
	}
 
	priority_queue<int> pq;
	for (int i = 1; i <= n; ++i) if (ind[i] == 0)
		pq.push(i);
 	
 	vector<int> res;
	while (!pq.empty())
	{
		int node = pq.top();
		pq.pop();
 	
 		res.pb(node);
		for (int to : adj[node])
		{
			ind[to]--;
			if (ind[to] == 0)
				pq.push(to);
		}
	}

	for (; !res.empty(); res.pop_back())
		cout << res.back() << " ";
	cout << '\n';
 
	return 0;
}
