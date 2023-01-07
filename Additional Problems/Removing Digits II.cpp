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

const ld PI = 4*atan((ld)1);

// number of times the same answer appeared as the previous number
int tmp[] = { 9, 1, 9, 2, 8, 3, 7, 4, 6, 5, 6, 9, 7, 8, 9, 6, 1 };

int fq[1000000];
int dp[1000000];

void solve()
{
	fill(dp, dp + 1000000, 1e9);

	dp[0] = 0;
	for (int i = 1; i < 1000000; ++i)
	{
		string s = to_string(i);
		for (char &c : s)
		{
			c -= '0';
			dp[i] = min(dp[i], 1 + dp[i - c]);
		}
		// cout << dp[i] << " \n"[i == 100];
		fq[dp[i]]++;

		// cerr << dp[i] << '\n';
		if (i == 999999) cerr << dp[i] << '\n';
	}
	
	for (int i = 1; i < 128206; ++i)
	{
		cout << fq[i] << " \n"[i % 17 == 0];
		// assert(dp[i] == tmp[(i-1) % 17]);
	}
}

int main()
{
	fastio;

	int TC = 1;
	//cin >> TC;

	while (TC--)
		solve();

	return 0;
}
