#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define pb push_back

const int MAX = 2e5 + 69;

bool ans[MAX];
vector<int> adj[MAX];
vector<int> adjR[MAX];

bool used[MAX];
int component[MAX];
vector<int> order;
inline void dfs1(int node)
{
	used[node] = true;
	for (int to : adj[node])
		if (!used[to])
			dfs1(to);
	order.pb(node);
}

inline void dfs2(int node, int h)
{
	used[node] = true;
	component[node] = h;
	for (int to : adjR[node])
		if (!used[to])
			dfs2(to, h);
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		char t1, t2;
		int a, b;
		cin >> t1 >> a >> t2 >> b;
		a--; b--;

		a <<= 1, b <<= 1;
		if (t1 == '-') a |= 1;
		if (t2 == '-') b |= 1;

		adj[a ^ 1].pb(b); adjR[b].pb(a ^ 1);
		adj[b ^ 1].pb(a); adjR[a].pb(b ^ 1);
	}

	memset(used, false, sizeof(used));
	for (int i = 0; i < 2*m; ++i)
		if (!used[i])
			dfs1(i);

	memset(used, false, sizeof(used));
	reverse(order.begin(), order.end());
	for (int i = 0, j = 0; i < 2*m; ++i)
	{
		if (!used[ order[i] ])
			dfs2(order[i], j++);
	}

	for (int i = 0; i < 2*m; i += 2)
	{
		if (component[i] == component[i+1])
		{
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		ans[i/2] = component[i] > component[i+1];
	}

	for (int i = 0; i < m; ++i)
		cout << "-+"[ ans[i] ] << " ";
	cout << '\n';

	return 0;
}