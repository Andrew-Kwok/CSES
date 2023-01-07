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

int const N = 1e5 + 7;

ll const mod = 1e9 + 7;

inline ll add(ll x, ll y)
{
	return (x + y) % mod;
}

ll ar[N];
ll dp[2][107];
int main()
{
	fastio;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> ar[i];

	for (int j = 1; j <= m; ++j)
	{
		if (ar[0] == 0 || ar[0] == j)
			dp[0][j] = 1;
	}

	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j <= m; ++j)
			dp[i%2][j] = 0;

		if (ar[i])
		{
			dp[i%2][ar[i]] = add(dp[(i+1)%2][ar[i]], add(dp[(i+1)%2][ar[i]-1], dp[(i+1)%2][ar[i]+1]));
		}
		else
		{
			for (int j = 1; j <= m; ++j)
			{
				dp[i%2][j] = add(dp[(i+1)%2][j], add(dp[(i+1)%2][j-1], dp[(i+1)%2][j+1]));
			}
		}
	}

	ll res = 0;
	for (int j = 1; j <= m; ++j)
		res = add(res, dp[(n+1)%2][j]);
	cout << res << '\n';

	return 0;
}
