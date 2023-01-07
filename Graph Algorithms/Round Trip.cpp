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

set<int> unused;

bool vst[N];
bool instack[N];
vector<int> st;
vector<int> adj[N];

vector<int> res;

void dfs(int node = 1)
{
	vst[node] = true;
	unused.erase(node);
	
	st.pb(node);
	instack[node] = true;
	for (int to : adj[node])
	{
		if (res.empty() && instack[to] && st.size() >= 3 && st[st.size() - 2] != to)
		{
			res.pb(to);
			while (st.back() != to)
				res.pb(st.back()), st.pop_back();
			res.pb(to);
		}

		if (!res.empty())
			return;

		if (!vst[to])
			dfs(to);
	}

	if (!res.empty())
		return;

	st.pop_back();
	instack[node] = false;
}

int main()
{
	fastio;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].pb(v); adj[v].pb(u);
	}

	for (int i = 1; i <= n; ++i)
		unused.insert(i);

	while (!unused.empty())
	{
		dfs(*unused.begin());
	}

	if (res.empty())
	{
		cout << "IMPOSSIBLE\n";
	}
	else
	{
		cout << res.size() << '\n';
		for (int i = 0; i < res.size(); ++i)
		{
			if (i) cout << " ";
			cout << res[i];
		}
		cout << '\n';
	}

	return 0;
}
