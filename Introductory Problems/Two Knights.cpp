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

int const N = 1e4 + 7;
ll dp[N];
int main()
{
	fastio;

	dp[1] = 0;
	dp[2] = 0;
	dp[3] = 8;
	dp[4] = 24;

	for (int i = 5; i < N; ++i)
		dp[i] = dp[i-1] + 8*i - 16;


	ll n;
	cin >> n;

	for (ll i = 1; i <= n; ++i)
	{
		cout << i*i * (i*i-1) / 2 - dp[i] << '\n';
	}

	return 0;
}
