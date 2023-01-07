#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x...) cerr << "[" << #x << "]: " << x << "\n";

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using pl = pair<ll, ll>;

ld const PI = 4*atan((ld)1);
int const MAX = 2e5 + 7;

ll ar[MAX];
ll sum[4 * MAX];
ll pfx[4 * MAX];

void build(int node, int l, int r)
{
	if (l == r)
	{
		sum[node] = ar[l];
		pfx[node] = max(0LL, ar[l]);
		return;
	}

	int mid = (l + r) / 2;
	build(node << 1, l, mid);
	build(node << 1 | 1, mid+1, r);

	sum[node] = sum[node << 1] + sum[node << 1 | 1];
	pfx[node] = max(pfx[node << 1], sum[node << 1] + pfx[node << 1 | 1]);
}

void modify(int node, int l, int r, int p, ll val)
{
	if (r < p || l > p)
		return;

	if (p == l && p == r)
	{
		ar[p] = val;
		sum[node] = val;
		pfx[node] = max(0LL, val);
		return;
	}

	int mid = (l + r) / 2;
	modify(node << 1, l, mid, p, val);
	modify(node << 1 | 1, mid+1, r, p, val);

	sum[node] = sum[node << 1] + sum[node << 1 | 1];
	pfx[node] = max(pfx[node << 1], sum[node << 1] + pfx[node << 1 | 1]);
}

pl query(int node, int l, int r, int p, int q) //returns maximum prefix sum, subarray [l,r] sum 
{
	if (r < p || l > q)
		return {0, 0};

	if (p <= l && r <= q)
		return {pfx[node], sum[node]};

	int mid = (l + r) / 2;

	pl a = query(node << 1, l, mid, p, q);
	pl b = query(node << 1 | 1, mid+1, r, p, q);

	return {max(a.f1, a.s2 + b.f1), a.s2 + b.s2};
}

int main()
{
	fastio;

	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; ++i)
		cin >> ar[i];

	build(1, 1, n);
	while (q--)
	{
		int t, a, b;
		cin >> t >> a >> b;

		if (t == 1) modify(1, 1, n, a, b);
		else cout << query(1, 1, n, a, b).f1 << '\n';
	}

	return 0;
}
