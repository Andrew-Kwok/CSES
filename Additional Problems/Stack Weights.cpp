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
const int MAX = 2e5 + 69;

int n;
int lz[2 * MAX] = {};
ii st[2 * MAX] = {};

#define lg(node) node + 1
#define rg(node) node + 2 * (mid - l + 1)

inline ii merge(ii x, ii y)
{
	return { min(x.f1, y.f1), max(x.s2, y.s2) };
}

inline void propagate(int node, int l, int r)
{
	if (lz[node])
	{
		st[node].f1 += lz[node], st[node].s2 += lz[node];
		if (l < r)
		{
			int mid = (l + r) >> 1;
			lz[lg(node)] += lz[node];
			lz[rg(node)] += lz[node]; 
		}
		lz[node] = 0;
	}
}

inline void update(int p, int q, int val, int node = 1, int l = 1, int r = n)
{
	propagate(node, l, r);
	if (l > q || r < p)
		return;
	if (p <= l && r <= q)
	{
		lz[node] += val;
		propagate(node, l, r);
		return;
	}

	int mid = (l + r) >> 1;
	update(p, q, val, lg(node), l, mid);
	update(p, q, val, rg(node), mid+1, r);
	st[node] = merge(st[lg(node)], st[rg(node)]);
}

inline ii query(int p, int q, int node = 1, int l = 1, int r = n)
{
	propagate(node, l, r);
	if (l > q || r < p)
		return {1e9, -1e9};
	if (p <= l && r <= q)
		return st[node];
	int mid = (l + r) >> 1;
	return merge(query(p, q, lg(node), l, mid), query(p, q, rg(node), mid+1, r));
}

void solve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		int x, ty;
		cin >> x >> ty;

		update(1, x, ty == 1 ? 1 : -1);
		auto [mn, mx] = query(1, n);

		if (mn >= 0) cout << ">\n";
		else if (mx <= 0) cout << "<\n";
		else cout << "?\n";
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
