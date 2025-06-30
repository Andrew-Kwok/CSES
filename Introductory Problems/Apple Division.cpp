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

ll p[25];
int main()
{
	fastio;

	int n;
	cin >> n;

	ll sum = 0;
	for (int i = 0; i < n; ++i)
		cin >> p[i], sum += p[i];

	ll res = 1e18;
	for (int mask = 0; mask < (1 << n); ++mask)
	{
		ll ctr = 0;
		for (int i = 0; i < n; ++i)
			if (mask & (1 << i))
		{
			ctr += p[i];
		}

		res = min(res, abs(sum - 2*ctr));
	}

	cout << res << '\n';

	return 0;
}
