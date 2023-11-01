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

// Observation
// Let f(n) denote the answer for n
// 1. \forall x \in \nats^+. f(n) \le f(n+1)
// 2. the ten^th will always decrease by at most 1

// Let dp[i][j][k] be the number of steps to go from i \underset{j times}{9...9} k to "(i-1) \underset{j times}{9...9} ?

pair<ll, int> dp[10][18][10];

void solve()
{
	for (int i = 1; i <= 9; ++i)
	{
		for (int k = 0; k <= 9; ++k)
		{
			if (i <= k) dp[i][0][k] = { 2, 10 - i };
			else dp[i][0][k] = { 1, 10 + k - i };
		}
	}

	for (int j = 1; j < 18; ++j)
	{
		for (int i = 1; i <= 9; ++i)
		{
			for (int k = 0; k <= 9; ++k)
			{
				int cur = k;
				for (int x = 9; x >= 0; --x)
				{
					auto [a, b] = dp[max(i, x)][j-1][cur];
					dp[i][j][k].f1 += a;
					cur = b;
				}
				dp[i][j][k].s2 = cur;
			}
		}
	}

	string s;
	cin >> s;

	int n = (int)s.size();

	vector<int> num(n);
	for (int i = 0; i < n; ++i)
		num[i] = s[n-i-1] - '0';

	// make the numbers from [1 .. n-2] 9
	ll res = 0;
	for (int i = 1; i+1 < n; ++i)
	{
		if (num[i] < 0) num[i] += 10, num[i+1] -= 1;
		if (num[i] == 9)
			continue;

		int mx = *max_element(num.begin() + i+1, num.end());
		
		while (num[i] >= 0) 
		{
			res += dp[max(mx, num[i])][i-1][num[0]].f1;
			num[0] = dp[max(mx, num[i])][i-1][num[0]].s2;
			num[i]--;
		}

		num[i] += 10; num[i+1] -= 1;
	}

	for (int i = n-1; i >= 1; --i)
	{
		while (num[i] > 0)
		{
			res += dp[num[i]][i-1][num[0]].f1;
			num[0] = dp[num[i]][i-1][num[0]].s2;
			num[i]--;
		}
	}

	cout << res + (num[0] > 0) << '\n';
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
