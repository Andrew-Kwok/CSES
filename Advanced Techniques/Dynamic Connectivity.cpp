#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ii pair<int, int>
#define f1 first
#define s2 second
#define mp make_pair

const int MAX = 1e5 + 69;

struct dsu_rollback
{
	int cc, ds[MAX], sz[MAX];
	vector<ii> history;

	dsu_rollback(int n = 0) { cc = n, iota(ds+1, ds+n+1, 1); fill(sz, sz+n+1, 1); }

	inline int frep(int x) { return ds[x] == x ? x : frep(ds[x]); }
	inline void join(int x, int y)
	{
		x = frep(x); y = frep(y);
		if (x == y)
		{
			history.pb({-1, -1});
			return;
		}

		if (sz[x] < sz[y])
			swap(x, y);

		ds[y] = x;
		sz[x] += sz[y];
		cc--;
		history.pb({x, y});
	}

	inline void rollback()
	{
		assert(!history.empty());
		if (history.back().f1 != -1)
		{
			auto &[x, y] = history.back();
			ds[y] = y;
			sz[x] -= sz[y];
			cc++;
		}
		history.pop_back();
	}
} dsu;

int n, m, k;
vector<ii> st[2 * MAX];
inline void add(int p, int q, ii x, int node = 1, int l = 0, int r = k)
{
	if (l > q || r < p)
		return;
	if (p <= l && r <= q)
	{
		st[node].pb(x);
		return;
	}

	int mid = (l + r) >> 1;
	add(p, q, x, node + 1, l, mid);
	add(p, q, x, node + 2 * (mid - l + 1), mid+1, r);
}

inline void solve(int node = 1, int l = 0, int r = k)
{
	for (auto &[a, b] : st[node])
		dsu.join(a, b);

	if (l == r) 
		cout << dsu.cc << " ";

	if (l < r)
	{
		int mid = (l + r) >> 1;
		solve(node + 1, l, mid);
		solve(node + 2 * (mid - l + 1), mid + 1, r);
	}

	for (int i = 0; i < (int)st[node].size(); ++i)
		dsu.rollback();
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	vector<array<int, 3>> v;
	while (m--)
	{
		int a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		v.pb({a, b, 0});
	}

	for (int i = 1; i <= k; ++i)
	{
		int ty, a, b; cin >> ty >> a >> b;
		if (a > b) swap(a, b);
		v.pb({a, b, i});
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < (int)v.size(); ++i)
	{
		if (i+1 < (int)v.size() && mp(v[i][0], v[i][1]) == mp(v[i+1][0], v[i+1][1]))
		{
			add(v[i][2], v[i+1][2] - 1, mp(v[i][0], v[i][1]));
			i++;
		}
		else add(v[i][2], k, mp(v[i][0], v[i][1]));
	}

	dsu = dsu_rollback(n);
	solve();
	cout << '\n';

	return 0;
}