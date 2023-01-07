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

int main()
{
	fastio;

	ll n;
	cin >> n;

	ll res = 0;
	for (int i = 0; i <= log2(n); ++i)
	{
		ll x = 2LL << i;

		res += (n/x) * (x/2);
		res += max(0LL, n%x - (x/2 - 1));
	}
	cout << res << '\n';

	return 0;
}
