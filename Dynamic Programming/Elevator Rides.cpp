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
const int inf = 1e9 + 7;

int ar[20];
ii dp[1 << 20];
int main()
{
	fastio;

	int n, x;
	cin >> n >> x;

	for (int i = 0; i < n; ++i)
		cin >> ar[i];

	dp[0] = {0, inf};
	for (int mask = 1; mask < (1 << n); ++mask)
	{
		dp[mask] = {inf, 0};
		for (int i = 0; i < n; ++i)
			if (mask & (1 << i))
		{
			auto [c, w] = dp[mask ^ (1 << i)];
			if (w + ar[i] > x)
			{
				c++;
				w = min(w, ar[i]);
			}
			else w += ar[i];
			dp[mask] = min(dp[mask], {c, w});
		}
	}

	cout << dp[(1 << n) - 1].f1 << '\n';
	return 0;
}
