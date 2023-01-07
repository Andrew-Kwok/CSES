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

int orientation(Point p, Point q, Point r)
{
	ll o = (p.x - q.x) * (q.y - r.y) - (q.x - r.x) * (p.y - q.y);

	if (o == 0)
		return 0; //collinear
	return o < 0 ? 1 : -1; // CW : CCW
}

void solve()
{
	Point p, q, r;
	cin >> p.x >> p.y >> q.x >> q.y >> r.x >> r.y;

	int o = orientation(p, q, r);

	if (o == 0) cout << "TOUCH\n";
	else cout << (o > 0 ? "RIGHT\n" : "LEFT\n");
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
