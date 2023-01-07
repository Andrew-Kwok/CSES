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
ll const mod = 1e9 + 7;

inline ll add(ll x, ll y)
{
	return (x + y) % mod;
}

inline ll sub(ll x, ll y)
{
	return (x - y + mod) % mod;
}

inline ll mul(ll x, ll y)
{
	return (x * y) % mod;
}

struct matrix
{
	int sz;
	vector<vector<int>> v;

	matrix(int n, bool identity = false)
	{
		sz = n;
		v.resize(n, vector<int>(n));
		
		for (int i = 0; i < n; ++i)
			v[i][i] = identity;
	}

	matrix operator* (matrix const &other) const
	{
		matrix res(sz);
		for (int i = 0; i < sz; ++i)
			for (int j = 0; j < sz; ++j)
				for (int k = 0; k < sz; ++k)
					res.v[i][k] = add(res.v[i][k], mul(v[i][j], other.v[j][k]));
		return res;
	}
};

matrix fpow(matrix x, ll y)
{
	matrix res(x.sz, true);
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
	fastio;

	int n, m, k;
	cin >> n >> m >> k;

	matrix base(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		base.v[--a][--b]++;
	}

	base = fpow(base, k);
	cout << base.v[0][n-1] << '\n';
	return 0;
}
