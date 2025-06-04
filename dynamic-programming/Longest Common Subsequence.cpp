#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAX = 1 << 10;

int A[MAX], B[MAX], dp[MAX][MAX];

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
		cin >> A[i];
	for (int i = 1; i <= M; ++i)
		cin >> B[i];

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			if (A[i] == B[j])
				dp[i][j] = max(dp[i][j], 1 + dp[i-1][j-1]);
		}
	}

	vector<int> v;
	for (int i = N, j = M; i >= 1 && j >= 1;)
	{
		if (dp[i][j] == dp[i-1][j]) --i;
		else if (dp[i][j] == dp[i][j-1]) --j;
		else
		{
			v.pb(A[i]);
			--i; --j;
		}
	}

	cout << v.size() << '\n';
	for (auto it = v.rbegin(); it != v.rend(); ++it)
		cout << *it << " ";
	cout << '\n';

	return 0;
}