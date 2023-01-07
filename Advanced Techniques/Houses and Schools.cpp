#include <iostream>
using namespace std;

#define ll long long

const int MAX = 3e3 + 69;

int n, K;
ll ar[MAX], pfx[MAX], val[MAX];

int opt[MAX][MAX];
ll cost[MAX][MAX];
ll dp[2][MAX];

inline void rc(int j, int l, int r, int optL, int optR)
{
	if (l > r)
		return;

	int mid = (l + r) >> 1;
	ll optVal = 1e18; int optIdx = -1;
	for (int i = optL; i <= min(mid, optR); ++i)
	{
		ll cur = dp[~j & 1][i-1] + cost[i][mid];
		if (cur < optVal)
		{
			optVal = cur;
			optIdx = i;
		}
	}

	dp[j&1][mid] = optVal;
	rc(j, l, mid-1, optL, optIdx);
	rc(j, mid+1, r, optIdx, optR);
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < MAX; ++j)
			cost[i][j] = 1e18;

	cin >> n >> K;
	for (int i = 1; i <= n; ++i)
	{
		cin >> ar[i];
		pfx[i] = ar[i] + pfx[i-1];
		val[i] = ar[i] * i + val[i-1];
	}

	for (int i = 1; i <= n; ++i)
		cost[i][i] = 0, opt[i][i] = i;

	for (int len = 2; len <= n; ++len)
	{
		for (int L = 1; L+len-1 <= n; ++L)
		{
			int R = L + len - 1;
			for (int k = max(L, opt[L][R-1]); k <= min(R, opt[L+1][R]); ++k)
			{
				// school is placed at 'k'
				ll C = (pfx[k-1] - pfx[L-1]) * k - (val[k-1] - val[L-1]);
				C += (val[R] - val[k]) - (pfx[R] - pfx[k]) * k;
				if (C <= cost[L][R])
				{
					cost[L][R] = C;
					opt[L][R] = k;
				}
			}
		}
	}

	for (int i = 1; i <= n; ++i)
		dp[0][i] = cost[1][i];
	for (int j = 1; j < K; ++j)
		rc(j, 1, n, 1, n);
	cout << dp[~K & 1][n] << '\n';

	return 0;
}