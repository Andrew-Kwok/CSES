#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x...) cerr << "[" << #x << "]: " << x << "\n";

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using pl = pair<ll, ll>;

ld const PI = 4*atan((ld)1);
int const MAX = 1e6  +7;

int p[107];
bool dp[MAX];
int main()
{
	fastio;

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < k; ++i)
		cin >> p[i];

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < k; ++j)
		{
			if (i >= p[j])
				dp[i] = (dp[i] || !dp[i-p[j]]);
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << (dp[i] ? "W" : "L");
	cout << '\n';

	return 0;
}
