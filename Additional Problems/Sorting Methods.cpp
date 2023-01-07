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

ll swap_adjacent(vector<int> v)
{
	struct fenwick
	{
		int bit[MAX] = {};
		inline void add(int x, int val)
		{
			for (int i = x; i < MAX; i += (i & -i))
				bit[i] += val;
		}

		inline int sum(int x)
		{
			int res = 0;
			for (int i = x; i > 0; i -= (i & -i))
				res += bit[i];
			return res;
		}
	} bit;

	ll res = 0, ctr = 0;
	for (int x : v)
	{
		res += ctr++ - bit.sum(x);
		bit.add(x, 1);
	}
	return res;
}

ll swap_two_elements(vector<int> v)
{
	struct dsu
	{
		int ds[MAX];
		dsu() { memset(ds, -1, sizeof(ds)); }

		inline int frep(int x) { return ds[x] < 0 ? x : ds[x] = frep(ds[x]); }
		inline void join(int x, int y)
		{
			x = frep(x); y = frep(y);
			if (x == y)
				return;

			ds[x] += ds[y];
			ds[y] = x;
		}
	} ds;

	int n = (int)v.size();
	for (int i = 0; i < n; ++i)
		ds.join(v[i], i+1);

	ll res = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (i == ds.frep(i))
			res += -ds.ds[i] - 1;
	}

	return res;
}

ll move_element(vector<int> v)
{
	struct segtree
	{
		int st[2*MAX] = {};
		inline void modify(int p, int val)
		{
			for (st[p += MAX] = val; p > 1; p >>= 1)
				st[p >> 1] = max(st[p], st[p^1]);
		}

		inline int query(int l, int r)
		{
			int res = 0;
			for (l += MAX, r += MAX; l < r; l >>= 1, r >>= 1)
			{
				if (l & 1) res = max(res, st[l++]);
				if (r & 1) res = max(res, st[--r]);
			}
			return res;
		}
	} st;

	for (int x : v)
		st.modify(x, 1 + st.query(1, x));

	int n = (int)v.size();
	return n - st.query(1, n+1);
}

ll move_to_front(vector<int> v)
{
	int n = (int)v.size(), ctr = 0;
	for (int i = n-1; i >= 0; --i)
	{
		if (v[i] == n - ctr)
			ctr++;
	}
	return n - ctr;
}


void solve()
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (int &x : v)
		cin >> x;

	cout << swap_adjacent(v) << " " << swap_two_elements(v) << " " << move_element(v) << " " << move_to_front(v) << '\n';
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
