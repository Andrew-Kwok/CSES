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
int const N = 5e3 + 7;

int slen, tlen;
char s[N], t[N];
int dp[N][N];
int main()
{
	fastio;

	cin >> s >> t;	
	slen = strlen(s);
	tlen = strlen(t);

	
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			dp[i][j] = inf;
		

	for (int i = 0; i < N; ++i)
		dp[0][i] = i = dp[i][0] = i;

	for (int i = 1; i <= slen; ++i)
	{
		for (int j = 1; j <= tlen; ++j)
		{
			if (s[i-1] == t[j-1])
				dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
			dp[i][j] = min(dp[i][j], 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}));
		}
	}
	cout << dp[slen][tlen] << '\n';

	return 0;
}
