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

int n;
int const N = 2e5 + 7;
int const inf = 1e9 + 7;

int st[2*N];

void build()
{
	for (int i = n-1; i > 0; --i)
		st[i] = min(st[i << 1], st[i << 1 | 1]);
}

void modify(int p, int val)
{
	for (st[p += n] = val; p > 1; p >>= 1)
		st[p >> 1] = min(st[p], st[p ^ 1]);
}

int query(int l, int r) // [l, r)
{
	int res = inf;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1) res = min(res, st[l++]);
		if (r & 1) res = min(res, st[--r]);
	}
	return res;
}

int main()
{
	fastio;

	fill(st, st + 2*N, inf);

	int q;
	cin >> n >> q;
	for (int i = 0; i < n; ++i)
		cin >> st[i + n];

	build();
	while (q--)
	{
		int t, a, b;
		cin >> t >> a >> b;

		if (t == 1) modify(--a, b);
		else cout << query(--a, b) << '\n';
	}

	return 0;
}
