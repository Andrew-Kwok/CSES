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
int const N = 1e6 + 7;

ll const prime = 991;
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

inline ll fpow(ll x, ll y)
{
	ll res = 1;
	while (y)
	{
		if (y & 1) res = mul(res, x);
		x = mul(x, x); y >>= 1;
	}
	return res;
}

int slen, tlen;
char s[N], t[N];

ll pwr[N], repwr[N];
ll shash[N];

int main()
{
	fastio;

	pwr[0] = 1;
	for (int i = 1; i < N; ++i)
		pwr[i] = mul(pwr[i-1], prime);

	repwr[N-1] = fpow(prime, mod - N);
	for (int i = N-2; i >= 0; --i)
		repwr[i] = mul(repwr[i+1], prime);

	cin >> s;
	cin >> t;

	slen = strlen(s);
	tlen = strlen(t);

	shash[0] = s[0];
	for (int i = 1; i < slen; ++i)
		shash[i] = add(shash[i-1], mul(s[i], pwr[i]));

	ll thash = 0;
	for (int i = 0; i < tlen; ++i)
		thash = add(thash, mul(t[i], pwr[i]));

	int res = 0;
	for (int i = 0; i <= slen - tlen; ++i)
	{
		ll tmp = sub(shash[i + tlen - 1], i > 0 ? shash[i-1] : 0);
		tmp = mul(tmp, repwr[i]);

		if (thash == tmp)
			res++;
	}
	cout << res << '\n';

	return 0;
}
