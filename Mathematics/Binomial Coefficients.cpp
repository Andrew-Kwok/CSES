#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll const mod = 1e9 + 7;
int const N = 1e6 + 7;

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

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;

		cout << mul(fact[a], mul(inv_fact[b], inv_fact[a-b])) << '\n';
	}

	return 0;
}