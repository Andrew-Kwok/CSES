#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x...) cerr << "[" << #x << "]: " << x << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;

ld const PI = 4*atan((ld)1);

int main()
{
	fastio;

	int n;
	vector<ii> v;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		v.pb({a, 1});
		v.pb({b, -1});
	}
	sort(v.begin(), v.end());

	int ctr = 0;
	int res = 0;
	for (auto x : v)
	{
		ctr += x.s2;
		res = max(res, ctr);
	}
	cout << res << '\n';

	return 0;
}
