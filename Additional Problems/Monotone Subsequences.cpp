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

void solve()
{
	int n, k;
	cin >> n >> k;

	if ((n+k-1) / k > k)
	{
		cout << "IMPOSSIBLE\n";
		return;
	}	

	for (int i = 1; i <= n; i += k)
	{
		for (int j = min(n, i+k-1); j >= i; --j)
			cout << j << " ";
	}
	cout << '\n';
}

int main()
{
	fastio;

	int TC = 1;
	cin >> TC;

	while (TC--)
		solve();

	return 0;
}
