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

int main()
{
	fastio;

	int n;

	ll sum = 0;
	ll mn = 0;
	ll res = -1e18;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		ll x; cin >> x;
		sum += x;

		res = max(res, sum - mn);
		mn = min(mn, sum);
	}
	cout << res << '\n';

	return 0;
}
