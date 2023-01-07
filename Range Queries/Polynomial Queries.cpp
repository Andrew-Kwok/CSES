#include <iostream>
using namespace std;

#define mp make_pair
#define ll long long
#define pl pair<ll, ll>
#define f1 first
#define s2 second

const int MAX = 2e5 + 969;
const int BLOCK = 777;

int n;
int ar[MAX], len[4 * MAX];

ll st[4 * MAX];
pl lazy[4 * MAX];

// n/2 (2a + (n-1)b )
inline ll sum(ll _n, ll a, ll b)
{
	return a*_n + b * _n*(_n-1)/2;
}

inline void build(int node = 1, int l = 1, int r = n)
{
	len[node] = r - l + 1;
	if (l == r)
	{
		st[node] = ar[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(node << 1, l, mid);
	build(node << 1 | 1, mid+1, r);

	st[node] = st[node << 1] + st[node << 1 | 1];
	return;
}

inline void propagate(int node, int l, int r)
{
	if (lazy[node] != mp(0LL, 0LL))
	{
		st[node] += sum(len[node], lazy[node].f1, lazy[node].s2);
		if (l < r)
		{
			lazy[node << 1].f1 += lazy[node].f1;
			lazy[node << 1].s2 += lazy[node].s2;
			
			lazy[node << 1 | 1].f1 += lazy[node].f1 + lazy[node].s2 * len[node << 1];
			lazy[node << 1 | 1].s2 += lazy[node].s2;
		}
		lazy[node] = mp(0LL, 0LL);
	}
	return;
}

inline void update(int p, int q, int num = 1, int node = 1, int l = 1, int r = n)
{
	propagate(node, l, r);

	if (l > q || r < p)
		return;
	if (p <= l && r <= q)
	{
		st[node] += sum(len[node], num, 1);
		if (l < r)
		{
			lazy[node << 1].f1 += num;
			lazy[node << 1].s2++;

			lazy[node << 1 | 1].f1 += num + len[node << 1];
			lazy[node << 1 | 1].s2++;
		}
		return;
	}

	int mid = (l + r) >> 1;
	update(p, q, num, node << 1, l, mid);
	update(p, q, num + max(0, min(q, mid) - max(p, l) + 1), node << 1 | 1, mid+1, r);
	st[node] = st[node << 1] + st[node << 1 | 1];
}

inline ll query(int p, int q, int node = 1, int l = 1, int r = n)
{
	propagate(node, l, r);
	if (l > q || r < p)
		return 0;
	if (p <= l && r <= q)
		return st[node];

	int mid = (l + r) >> 1;
	return query(p, q, node << 1, l, mid) + query(p, q, node << 1 | 1, mid+1, r);
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> ar[i];
	build();

	while (q--)
	{
		int ty, l, r;
		cin >> ty >> l >> r;

		if (ty == 1) update(l, r);
		else cout << query(l, r) << '\n';
	}

	return 0;
}