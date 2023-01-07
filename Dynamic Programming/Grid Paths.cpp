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

int const N = 1e3 + 7;

ll const mod = 1e9 + 7;

inline ll add(ll x, ll y)
{
	return (x + y) % mod;
}

char s[N][N];
ll dp[N][N] = {};
int main()
{
	fastio;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> s[i];

	dp[0][0] = (s[0][0] == '.');
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
	{
		if (i && s[i][j] == '.') dp[i][j] = add(dp[i][j], dp[i-1][j]);
		if (j && s[i][j] == '.') dp[i][j] = add(dp[i][j], dp[i][j-1]);
	}
	cout << dp[n-1][n-1] << '\n';

	return 0;
}
