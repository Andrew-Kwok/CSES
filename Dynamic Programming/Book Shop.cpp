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

int page[1007];
int price[1007];
int dp[2][N] = {};

int main()
{
	fastio;	

	int n, x;
	cin >> n >> x;

	for (int i = 0; i < n; ++i)
		cin >> price[i];
	for (int i = 0; i < n; ++i)
		cin >> page[i];

	for (int i = 0; i < n; ++i)
	{
		for (int j = x; j >= 0; --j)
		{
			dp[i%2][j] = dp[(i+1)%2][j];
			if (j >= price[i])
				dp[i%2][j] = max(dp[i%2][j], page[i] + dp[(i+1)%2][j - price[i]]);
		}
	}
	cout << dp[(n+1)%2][x] << '\n';

	return 0;
}
