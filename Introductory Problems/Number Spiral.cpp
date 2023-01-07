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

	int t;
	cin >> t;

	while (t--)
	{
		ll y, x, m;
		cin >> y >> x;
		m = max(y, x);

		ll res = (m-1) * (m-1) + m;
		if (m % 2 == 0)
		{
			if (x <= y) res += abs(x - y);
			else res -= abs(x - y);
		}
		else
		{
			if (x >= y) res += abs(x - y);
			else res -= abs(x - y);
		}
		cout << res << '\n';
	}

	return 0;
}
