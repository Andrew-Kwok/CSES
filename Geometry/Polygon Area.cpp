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

struct Point
{
	ll x, y;
};

int main()
{
	fastio;

	int n;
	cin >> n;

	vector<Point> v(n);
	for (Point &p : v)
		cin >> p.x >> p.y;

	v.pb(v[0]);

	ll area = 0;
	for (int i = 0; i < n; ++i)
	{
		area += v[i].x * v[i+1].y;
		area -= v[i].y * v[i+1].x;
	}

	cout << abs(area) << '\n';

	return 0;
}
