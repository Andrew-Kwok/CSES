#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x) cerr << "[" << #x << "]: " << x << "\n";

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using pl = pair<ll, ll>;

constexpr ld PI = 4*atan((ld)1);
constexpr int MAX = 5069;

int n;
ll ar[MAX];

int opt[MAX][MAX];	
ll dp[MAX][MAX];

inline ll cost(int l, int r)
{
	return ar[r] - ar[l-1];
}

int main()
{
	fastio;

	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < MAX; ++j)
			dp[i][j] = 1e18;

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> ar[i], ar[i] += ar[i-1];

	for (int i = 1; i <= n; ++i)
		dp[i][i] = 0, opt[i][i] = i;

	for (int len = 2; len <= n; ++len)
	{
		for (int L = 1; L + len - 1 <= n; ++L)
		{
			int R = L + len - 1;
			for (int k = max(L+1, opt[L][R-1]); k <= min(R, opt[L+1][R]); ++k)
			{
				ll val = dp[L][k-1] + dp[k][R] + cost(L, R);
				if (val <= dp[L][R])
				{
					dp[L][R] = val;
					opt[L][R] = k;
				}
			}
		}
	}

	cout << dp[1][n] << '\n';
	return 0;
}
