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
ll sieve[N];

inline ll factor(ll x)
{
	vector<int> v;
	while (x > 1)
		v.pb(sieve[x]), x /= sieve[x];
	sort(v.begin(), v.end());
	v.pb(-1);

	ll res = 1;
	int ctr = 1;
	for (int i = 1; i < v.size(); ++i)
	{
		if (v[i-1] != v[i])
			res *= (ctr + 1), ctr = 0;
		ctr++;
	}
	return res;
}

int main()
{
	fastio;

	for (int i = 1; i < N; ++i)
		sieve[i] = i;
	for (ll i = 2; i*i < N; ++i)
	{
		if (sieve[i] == i)
		{
			for (ll j = i*i; j < N; j += i)
				sieve[j] = i;
		}
	}

	int q;
	cin >> q;
	while (q--)
	{
		ll x;
		cin >> x;
		cout << factor(x) << '\n';
	}

	return 0;
}
