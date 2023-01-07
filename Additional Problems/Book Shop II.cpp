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
const int MAX = 1e5 + 69;

int dp[MAX] = {};
int H[MAX], S[MAX], K[MAX];

void solve()
{
	int n, x;
	cin >> n >> x;

	for (int i = 0; i < n; ++i)
		cin >> H[i];
	for (int i = 0; i < n; ++i)
		cin >> S[i];
	for (int i = 0; i < n; ++i)
		cin >> K[i];

	// conversion to 0-1 knapsack
	vector<ii> v; 
	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; K[i] > 0; ++j)
		{
			int mn = min(j, K[i]);
			K[i] -= mn;
			v.pb({mn * H[i], mn * S[i]});
		}
	}

	n = (int)v.size();

	for (int i = 0; i < n; ++i)
	{
		for (int j = x; j >= v[i].f1; --j)
			dp[j] = max(dp[j], dp[j - v[i].f1] + v[i].s2);
	}
	cout << *max_element(dp, dp + x+1) << '\n';
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
