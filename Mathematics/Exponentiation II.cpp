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

inline ll mul(ll x, ll y, ll mod)
{
	return (x * y) % mod;
}

inline ll fpow(ll x, ll y, ll mod)
{
	ll res = 1;
	while (y)
	{
		if (y & 1) res = mul(res, x, mod);
		x = mul(x, x, mod); y >>= 1;
	}
	return res;
}

int main()
{
	fastio;

	int q;
	cin >> q;

	ll const x = 1e9 + 7;
	while (q--)
	{
		ll a, b, c;
		cin >> a >> b >> c;

		ll v = fpow(b, c, x - 1);
		cout << fpow(a, v, x) << '\n';
	}

	return 0;
}
