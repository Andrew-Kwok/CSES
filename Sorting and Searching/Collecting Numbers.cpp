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
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i].f1;
		v[i].s2 = i;
	}
	sort(v.begin(), v.end());

	int res = 1;
	int prv = -1;
	for (int i = 0; i < n; ++i)
	{
		if (prv > v[i].s2) res++;
		prv = v[i].s2;
	}
	cout << res << '\n';

	return 0;
}
