#include <bits/stdc++.h>
using namespace std;

#define ll long long

int const MAX = 2e5 + 69;

int n;
ll ar[MAX], st[4*MAX], lazy[4*MAX];
bool ty[4*MAX]; //true: set, false: add

void build(int node = 1, int l = 1, int r = n)
{
	if (l == r)
	{
		st[node] = ar[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(node << 1, l, mid);
	build(node << 1 | 1, mid+1, r);

	st[node] = st[node << 1] + st[node << 1 | 1];
}

void propagate(int node, int l, int r)
{
	if (lazy[node])
	{
		if (ty[node])
		{
			st[node] = (r - l + 1) * lazy[node];
			if (l < r)
			{
				lazy[node << 1] = lazy[node << 1 | 1] = lazy[node];
				ty[node << 1] = ty[node << 1 | 1] = true;
			}
			lazy[node] = ty[node] = 0;
		}
		else
		{
			st[node] += (r - l + 1) * lazy[node];
			if (l < r)
			{
				lazy[node << 1] += lazy[node];
				lazy[node << 1 | 1] += lazy[node];
			}
			lazy[node] = 0;
		}
	}
}

void add(int p, int q, ll val, int node = 1, int l = 1, int r = n)
{
	propagate(node, l, r);
	if (l > q || r < p)
		return;

	if (p <= l && r <= q)
	{
		st[node] += (r - l + 1) * val;
		if (l < r)
		{
			lazy[node << 1] += val;
			lazy[node << 1 | 1] += val;
		}
		return;
	}

	int mid = (l + r) >> 1;
	add(p, q, val, node << 1, l, mid);
	add(p, q, val, node << 1 | 1, mid+1, r);

	st[node] = st[node << 1] + st[node << 1 | 1];
}

void modify(int p, int q, ll val, int node = 1, int l = 1, int r = n)
{
	propagate(node, l, r);
	if (l > q || r < p)
		return;
	
	if (p <= l && r <= q)
	{
		st[node] = (r - l + 1) * val;
		if (l < r)
		{
			lazy[node << 1] = lazy[node << 1 | 1] = val;
			ty[node << 1] = ty[node << 1 | 1] = true;
		}
		return;
	}

	int mid = (l + r) >> 1;
	modify(p, q, val, node << 1, l, mid);
	modify(p, q, val, node << 1 | 1, mid+1, r);

	st[node] = st[node << 1] + st[node << 1 | 1];
}


ll sum(int p, int q, int node = 1, int l = 1, int r = n)
{
	propagate(node, l, r);
	if (l > q || r < p)
		return 0;
	if (p <= l && r <= q)
		return st[node];

	int mid = (l + r) >> 1;
	return sum(p, q, node << 1, l, mid) + sum(p, q, node << 1 | 1, mid+1, r);
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
		int t, a, b, c;
		cin >> t >> a >> b;
		if (t < 3) cin >> c;

		if (t == 1) add(a, b, c);
		else if (t == 2) modify(a, b, c);
		else cout << sum(a, b) << '\n';
	}

	return 0;
}