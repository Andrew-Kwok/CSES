#include <iostream>
using namespace std;

#define ll long long

//get the number of integers from 0 to n where no two adjacent digits are the same
ll solve(ll n)
{
	if (n == -1)
		return 0;

	ll dp[2][10][2] = {};
	string s = to_string(n);

	for (int i = 0; i < (int)s.size(); ++i)
	{	
		for (int j = 0; j < 10; ++j)
			for (int k = 0; k < 2; ++k)
				dp[i&1][j][k] = 0;

		for (int j = 0; j < 10; ++j)
			for (int k = 0; k < 10; ++k)
				if (j != k)
					dp[i&1][j][0] += dp[~i&1][k][0];

		for (int j = 0; j < s[i] - '0'; ++j)
			for (int k = 0; k < 10; ++k)
				if (j != k)
					dp[i&1][j][0] += dp[~i&1][k][1];

		if (i == 0)
		{
			for (int j = 1; j < s[i] - '0'; ++j)
				dp[i&1][j][0]++;
			if (s[i] != '0')
				dp[i&1][s[i] - '0'][1]++;
		}
		else
		{
			for (int j = 1; j < 10; ++j)
				dp[i&1][j][0]++;
		}	

		for (int j = s[i] - '0'; j <= s[i] - '0'; ++j)
			for (int k = 0; k < 10; ++k)
				if (j != k)
					dp[i&1][j][1] += dp[~i&1][k][1];
	}

	ll sum = 0;
	for (int i = 0; i < 10; ++i)
		sum += dp[~s.size() & 1][i][0];
	for (int i = 0; i < 10; ++i)
		sum += dp[~s.size() & 1][i][1];
	return sum + 1; //+1 for zero
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll a, b;
	cin >> a >> b;

	cout << solve(b) - solve(a - 1) << '\n';
	return 0;
}