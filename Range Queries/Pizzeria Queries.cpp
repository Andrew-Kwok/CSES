#include <iostream>
#include <vector>
using namespace std;

struct segtree
{
	int n;
	vector<int> st;

	segtree(int N) : n(N)
	{
		st.assign(2*n, 0);
	};

	inline void modify(int p, int val)
	{
		for (st[p += n] = val; p > 0; p >>= 1)
			st[p >> 1] = min(st[p], st[p ^ 1]);
	}

	inline int query(int l, int r)
	{
		int res = 1e9;
		for (l += n, r += n+1; l < r; l >>= 1, r >>= 1)
		{
			if (l & 1) res = min(res, st[l++]);
			if (r & 1) res = min(res, st[--r]);
		}
		return res;
	}
};

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	segtree lt(n), rt(n);
	for (int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		lt.modify(i, x - i);
		rt.modify(i, x + i);
	}

	while (q--)
	{
		int ty, p, x;
		cin >> ty >> p; p--;

		if (ty == 1)
		{
			cin >> x;
			lt.modify(p, x - p);
			rt.modify(p, x + p);
		}
		else
		{
			int r1 = lt.query(0, p);
			int r2 = rt.query(p, n-1);

			cout << min(r1 + p, r2 - p) << '\n';
		}
	}

	return 0;
}