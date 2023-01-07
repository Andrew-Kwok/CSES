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

inline ll mul(ll x, ll y)
{
	return (x * y) % mod;
}

inline ll sub(ll x, ll y)
{
	return (x - y + mod) % mod;
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
ll shash[MAX];
ll pwr[MAX];
ll inv_pwr[MAX];

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

	cin >> s;

	shash[0] = s[0];
	for (int i = 1; i < s.size(); ++i)
		shash[i] = add(shash[i-1], mul(s[i], pwr[i]));

	for (int i = 0; i < s.size(); ++i)
	{
		int period_hash = getHash(0, i);
		int len = i+1;

		bool valid = true;
		for (int j = i+1; j < s.size() && valid; j += len)
		{
			if (j + len - 1 < s.size())
			{
				if (getHash(j, j+len-1) != period_hash)
					valid = false;
			}
			else //excess part
			{
				if (getHash(j, s.size() - 1) != getHash(0, s.size() - 1 - j))
					valid = false;
			}
		}

		if (valid)
			cout << i+1 << " ";
	}
	cout << '\n';

	return 0;
}
