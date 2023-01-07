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

void solve()
{
	int n;
	cin >> n;

	ll xsum = 0;
	for (int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		xsum ^= x;
	}
	cout << (xsum ? "first\n" : "second\n");
	return;
}

int main()
{
	fastio;

	int t;
	cin >> t;

	while (t--)
		solve();

	return 0;
}
