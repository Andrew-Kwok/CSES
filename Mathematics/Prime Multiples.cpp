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
int const MAX = (1 << 20) + 7;

ll dp[MAX];
int main()
{
	fastio;

	ll n, k;
	cin >> n >> k;

	vector<ll> v(k);
	for (ll &x : v)
		cin >> x;

	ll res = 0;

	dp[0] = 1;
	for (int mask = 1; mask < (1 << k); ++mask)
	{
		int bit = log2(mask & -mask);
		int prev_mask = mask ^ (mask & -mask);
		dp[mask] = dp[prev_mask] / __gcd(dp[prev_mask], v[bit]);

		if (dp[mask] > n / v[bit])
			dp[mask] = n + 1;
		else dp[mask] *= v[bit];

		if (__builtin_popcount(mask) & 1) res += n / dp[mask];
		else res -= n / dp[mask];
	}	
	cout << res << '\n';

	return 0;
}
