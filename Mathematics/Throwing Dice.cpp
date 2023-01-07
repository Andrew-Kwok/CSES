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

inline ll fpow(ll x, ll y)
{
	ll res = 1;
	while (y)
	{
		if (y & 1) res = mul(res, x);
		x = mul(x, x);
		y >>= 1;
	}
	return res;
}

struct Mtx
{
	int sz;
	vector<vector<int>> v;

	Mtx (int n, bool identity = false)
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

inline Mtx matrix_fpow(Mtx x, ll y)
{
	Mtx res = Mtx(x.sz, true);
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

	ll n;
	cin >> n;

	Mtx ratio(6);
	ratio.v = {
		{1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0},
		{0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 1, 0}
	};

	ratio = matrix_fpow(ratio, n - 1);

	ll base[6] = {32, 16, 8, 4, 2, 1};
	ll ans = 0;
	for (int i = 0; i < 6; ++i)
		ans = add(ans, mul(ratio.v[5][i], base[i]));
	cout << ans << '\n';
	return 0;
}