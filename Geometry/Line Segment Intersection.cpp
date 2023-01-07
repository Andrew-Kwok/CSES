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

bool onSegment(Point p, Point q, Point r)
{
	return min(p.x, r.x) <= q.x && q.x <= max(p.x, r.x) &&
		   min(p.y, r.y) <= q.y && q.y <= max(p.y, r.y);
}

bool solve()
{
	Point a, b, c, d;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

	int o1 = orientation(a, b, c);
	int o2 = orientation(a, b, d);
	int o3 = orientation(c, d, a);
	int o4 = orientation(c, d, b);

	if (o1 != o2 && o3 != o4)
		return true;

	if (o1 == 0 && onSegment(a, c ,b)) return true;
	if (o2 == 0 && onSegment(a, d, b)) return true;
	if (o3 == 0 && onSegment(c, a, d)) return true;
	if (o4 == 0 && onSegment(c, b, d)) return true;

	return false;
}

int main()
{
	fastio;

	int t;
	cin >> t;

	while (t--)
		cout << (solve() ? "YES\n" : "NO\n"); 

	return 0;
}
