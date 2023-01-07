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

int const N = 5e3 + 7;

ll ar[N];
ll pfx[N];
ll dp[N][N];

inline ll sum(int l, int r)
{
	return pfx[r] - pfx[l-1];
}

int main()
{
	fastio;

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> ar[i], pfx[i] = ar[i] + pfx[i-1];

	for (int r = 1; r <= n; ++r)
	{
		dp[r][r] = ar[r];
		for (int l = r-1; l >= 1; --l)
		{
			dp[l][r] = max(ar[l] + sum(l+1, r) - dp[l+1][r], ar[r] + sum(l, r-1) - dp[l][r-1]);
		}
	}
	cout << dp[1][n] << '\n';

	return 0;
}
