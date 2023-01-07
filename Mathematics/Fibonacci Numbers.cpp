#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll const mod = 1e9 + 7;

inline ll add(ll x, ll y)
{
	return (x + y) % mod;
}

inline ll mul(ll x, ll y)
{
	return (x * y) % mod;
}

struct Mtx
{
	int sz;
	vector<vector<int>> v;

	Mtx(int n, bool identity = false)
	{
		sz = n;
		v.resize(n, vector<int> (n));
		for (int i = 0; i < n; ++i)
			v[i][i] = identity;
	}

	Mtx operator * (const Mtx &other) const
	{
		Mtx res(sz);
		for (int i = 0; i < sz; ++i)
			for (int j = 0; j < sz; ++j)
				for (int k = 0; k < sz; ++k)
					res.v[i][k] = add(res.v[i][k], mul(v[i][j], other.v[j][k]));
		return res;
	};
};

Mtx matrix_fpow(Mtx x, ll y)
{
	Mtx res(x.sz, true);

	while (y)
	{
		if (y & 1) res = res * x;
		x = x * x;
		y >>= 1;
	}
	return res;
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Mtx ratio(2);
	ratio.v = {{1, 1}, {1, 0}};

	ll n;
	cin >> n;

	ratio = matrix_fpow(ratio, n);
	cout << ratio.v[1][0] << '\n';

	return 0;
}