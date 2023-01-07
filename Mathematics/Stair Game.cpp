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

constexpr ld PI = 4*atan((ld)1);

void solve()
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (int &x : v)
		cin >> x;

	int ctr = 0;
	for (int i = 1; i < n; i += 2)
		ctr ^= v[i];

	cout << (ctr ? "first\n" : "second\n");
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
