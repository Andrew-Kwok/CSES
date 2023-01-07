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

int main()
{
	fastio;

	int n;
	cin >> n;

	vector<ii> v(n);
	for (ii &x : v)
		cin >> x.f1 >> x.s2;
	sort(v.begin(), v.end());

	ll res = 0;
	ll stime = 0;
	for (ii x : v)
	{
		stime += x.f1;
		res += x.s2 - stime;
	}
	cout << res << '\n';

	return 0;
}
