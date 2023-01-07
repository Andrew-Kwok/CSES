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

inline ll add(ll x, ll y, ll m = mod)
{
	return (x + y) % m;
}

inline ll sub(ll x, ll y, ll m = mod)
{
	return (x - y + m) % m;
}

inline ll mul(ll x, ll y, ll m = mod)
{
	return (x * y) % m;
}

inline ll fpow(ll x, ll y, ll m = mod)
{
	ll res = 1;
	while (y)
	{
		if (y & 1) res = mul(res, x, m);
		x = mul(x, x, m);
		y >>= 1;
	}
	return res;
}

int n;
vector<pl> v;
ll getNumber()
{
	ll res = 1;
	for (pl x : v)
		res = mul(res, add(x.s2, 1));

	return res;
}

ll getSum()
{
	ll res = 1;
	for (pl x : v)
	{
		ll a = sub(fpow(x.f1, x.s2+1), 1); //x^(k+1) - 1
		ll b = fpow(sub(x.f1, 1), mod - 2); // 1 / (x-1)
		res = mul(res, mul(a, b));
	}

	return res;
}

ll getProduct()
{
	ll res = 1;
	ll no_of_divisor = 1;

	for (pl &x : v)
	{
		res = fpow(res, x.s2 + 1);

		ll tmp = (x.s2 * (x.s2 + 1) / 2) % (mod - 1);
		tmp = mul(tmp, no_of_divisor, mod - 1);
		res = mul(res, fpow(x.f1, tmp));

		no_of_divisor = mul(no_of_divisor, x.s2 + 1, mod - 1);
	}

	return res;
}

int main()
{
	fastio;

	cin >> n;

	v.resize(n);
	for (pl &x : v)
		cin >> x.f1 >> x.s2;

	cout << getNumber() << " " << getSum() << " " << getProduct() << '\n';
	return 0;
}
