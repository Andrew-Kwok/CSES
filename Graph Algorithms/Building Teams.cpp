#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x...) cerr << "[" << #x << "]: " << x << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;

ld const PI = 4*atan((ld)1);

int const N = 1e5 + 7;

int res[N] = {};
vector<int> adj[N];

int main()
{
	fastio;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	set<int> st;
	for (int i = 1; i <= n; ++i)
		st.insert(i);

	while (!st.empty())
	{
		int node = *st.begin(); st.erase(node);
		res[node] = 1;

		queue<int> q;
		q.push(node);
		while (!q.empty())
		{
			node = q.front();
			q.pop();

			for (int to : adj[node])
			{
				if (res[to])
				{
					if (res[to] == res[node])
					{
						cout << "IMPOSSIBLE\n";
						return 0;
					}
				}
				else
				{
					res[to] = 3 - res[node];
					st.erase(to);
					q.push(to);
				}
			}
		}
	}
	
	for (int i = 1; i <= n; ++i)
	{
		if (i > 1) cout << " ";
		cout << res[i];
	}
	cout << '\n';

	return 0;
}
