#include <bits/stdc++.h>
using namespace std;

#define ll long long

int const N = 2e6 + 7;
ll const mod = 1e9 + 7;

ll fact[N];
ll inv_fact[N];

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

inline ll choose(ll n, ll k)
{
	return mul(fact[n], mul(inv_fact[k], inv_fact[n-k]));
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	fact[0] = 1;
	for (int i = 1; i < N; ++i)
		fact[i] = mul(i, fact[i-1]);

	inv_fact[N-1] = fpow(fact[N-1], mod - 2);
	for (int i = N-2; i >= 0; --i)
		inv_fact[i] = mul(i+1, inv_fact[i+1]);

	int n, m;
	cin >> n >> m;
	cout << choose(n+m-1, n-1) << '\n';

	return 0;
}