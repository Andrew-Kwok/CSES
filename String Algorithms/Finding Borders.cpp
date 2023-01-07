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
int const MAX = 1e6 + 7;
ll const p = 911;
ll const mod = 1e9 + 9;

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
		x = mul(x, x);
		y >>= 1;
	}
	return res;
}

string s;
int shash[MAX];
int pwr[MAX];
int inv_pwr[MAX];

int getHash(int l, int r)
{
	return mul(sub(shash[r], l > 0 ? shash[l-1] : 0), inv_pwr[l]);
}

int main()
{
	fastio;

	pwr[0] = 1;
	for (int i = 1; i < MAX; ++i)
		pwr[i] = mul(p, pwr[i-1]);

	inv_pwr[MAX-1] = fpow(pwr[MAX-1], mod-2);
	for (int i = MAX-2; i >= 0; --i)
		inv_pwr[i] = mul(p, inv_pwr[i+1]);

	string s;
	cin >> s;

	shash[0] = s[0];
	for (int i = 1; i < s.size(); ++i)
		shash[i] = add(shash[i-1], mul(s[i], pwr[i]));

	for (int i = 0; i+1 < s.size(); ++i)
	{
		if (getHash(0, i) == getHash(s.size() - 1 - i, s.size() - 1))
			cout << i+1 << " ";
	}

	cout << '\n';
	return 0;
}
