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
 
ld const PI = 4*atan((ld)1);
int const inf = 1e9 + 7;
 
struct Point
{
	int x, y;
	Point() : x(0), y(0) {}
	Point(int _x, int _y) : x(_x), y(_y) {}

	friend ostream& operator<< (ostream &os, const Point &p) { return os << "(" << p.x << "," << p.y << ")"; }
	friend bool operator== (const Point &a, const Point &b) { return a.x == b.x && a.y == b.y; }
	friend bool operator!= (const Point &a, const Point &b) { return a.x != b.x || a.y != b.y; }
};
 
int orientation(Point p, Point q, Point r)
{
	ll o = 1ll * (q.y - p.y) * (r.x - q.x) - 1ll * (q.x - p.x) * (r.y - q.y);

	if (o == 0)
		return 0; //collinear
	return o > 0 ? -1 : 1; // CW : CCW
}
 
bool onSegment(Point p, Point q, Point r)
{
	return min(p.x, r.x) <= q.x && q.x <= max(p.x, r.x) &&
		   min(p.y, r.y) <= q.y && q.y <= max(p.y, r.y);
}
 

int main()
{
	fastio;
 
	int n, q;
	cin >> n >> q;
 
	vector<Point> v(n);
	for (Point &p : v)
		cin >> p.x >> p.y;
	v.pb(v[0]);

	const auto solve = [&](Point p) -> int
	{
		int winding = 0;
		for (int i = 0; i < n; ++i)
		{
			if (p == v[i])
				return 0;

			if (v[i].y == p.y && p.y == v[i+1].y) // horizontal line
			{
				if (onSegment(v[i], p, v[i+1]))
					return 0;
			}
			else
			{
				bool below = v[i].y < p.y;
				if (below != (v[i+1].y < p.y))
				{
					int o = orientation(p, v[i+1], v[i]);
					if (o == 0)
						return 0;
					if (below == (o > 0))	
						winding += below ? 1 : -1;
				}
			}
		}

		return winding == 0 ? 2 : 1;
	};

	while (q--)
	{
		Point p;
		cin >> p.x >> p.y;
 
		string res[3] = {"BOUNDARY", "INSIDE", "OUTSIDE"};
		cout << res[solve(p)] << '\n';
	}
 
	return 0;
}