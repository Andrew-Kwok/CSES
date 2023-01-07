#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x...) cerr << "[" << #x << "]: " << x << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;

ld const PI = 4*atan((ld)1);
ll const mod = 1e9 + 7;

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
		y = (y >> 1);
	}
	return res;
}

int const N = 1e5 + 7;
ll dp[N] = {};

int main()
{
	fastio;

	int n;
	cin >> n;

	if ((n * (n+1) / 2) % 2 == 1)
	{
		cout << 0 << '\n';
		return 0;
	}

	dp[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = n * (n+1) / 4; j >= i; --j)
		{
			dp[j] = add(dp[j], dp[j-i]);
		}
	}

	cout << mul(dp[n * (n+1) / 4], fpow(2, mod - 2)) << '\n';
	return 0;
}
