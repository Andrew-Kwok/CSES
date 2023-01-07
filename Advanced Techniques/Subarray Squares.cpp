#include <iostream>
using namespace std;

#define ll long long

const int MAX = 3007;

ll pfx[MAX];
ll dp[2][MAX];

void dnc(int k, int l, int r, int optL, int optR)
{
	if (l > r)
		return;

	ll optVal = 1e18;
	int optIdx = -1;
	int mid = (l + r) >> 1;
	for (int i = optL; i <= min(optR, mid); ++i)
	{
		ll val = dp[~k & 1][i-1] + (pfx[mid] - pfx[i-1]) * (pfx[mid] - pfx[i-1]);
		if (val < optVal)
		{
			optVal = val;
			optIdx = i;
		}
	}

	dp[k & 1][mid] = optVal;
	dnc(k, l, mid-1, optL, optIdx);
	dnc(k, mid+1, r, optIdx, optR);
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
		cin >> pfx[i], pfx[i] += pfx[i-1];

	for (int i = 1; i <= n; ++i)
		dp[0][i] = pfx[i] * pfx[i];
	for (int i = 1; i < k; ++i)
		dnc(i, 1, n, 1, n);
	cout << dp[~k & 1][n] << '\n';

	return 0;
}