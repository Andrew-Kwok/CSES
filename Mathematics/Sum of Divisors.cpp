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
	return (x%mod + y%mod) % mod;
}

inline ll sub(ll x, ll y)
{
	return (x%mod - y%mod + mod) % mod;
}

inline ll mul(ll x, ll y)
{
	return ((x%mod) * (y%mod)) % mod;
}

inline ll triangle(ll n)
{
	if (n & 1)
		return mul(n, (n+1)/2);
	return mul(n/2, n+1);
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
	fastio;

	ll n;
	cin >> n;

	ll res = 0;
	for (ll i = 1; i*i <= n; ++i)
	{
		res = add(res, mul((n/i - i + 1), i));
		res = add(res, sub(triangle(n/i), triangle(i)));
	}

	cout << res << '\n';
	return 0;
}
