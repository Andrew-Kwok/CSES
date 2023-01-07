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

int const inf = 1e9 + 7;
int const N = 507;

int dp[N][N];
int main()
{
	fastio;

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			dp[i][j] = inf;

	for (int i = 0; i < N; ++i)
		dp[i][i] = 0;


	int a, b;
	cin >> a >> b;

	for (int i = 1; i <= a; ++i)
	{
		for (int j = 1; j <= b; ++j)
		{
			for (int k = 1; k <= i-1; ++k) //Cut row
			{
				dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
			}
			for (int k = 1; k <= j-1; ++k) //Cut column
			{
				dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j-k]);
			}
		}
	}
	cout << dp[a][b] << '\n';

	return 0;
}
