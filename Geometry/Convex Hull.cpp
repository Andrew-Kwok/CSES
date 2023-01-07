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
	Point() : x(0), y(0) {}
	Point(ll p, ll q) : x(p), y(q) {}

	bool operator<(Point const &other) const { return x < other.x || (x == other.x && y < other.y); }
	bool operator==(Point const &other) const { return x == other.x && y == other.y; }

	friend ostream& operator<<(ostream &os, const Point &p) { return os << "(" << p.x << ", " << p.y << ")"; }
};

ll orientation(Point a, Point b, Point c)
{
	ll o = (a.y - b.y) * (b.x - c.x) - (a.x - b.x) * (b.y - c.y);

	if (o == 0)
		return 0;
	return o > 0 ? -1 : 1; // CW : CCW
}

ll dist(Point a, Point b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

vector<Point> v;
vector<Point> ccw_hull() //from below
{
	sort(v.begin() + 1, v.end(), [&](Point const &p, Point const &q){
		int o = orientation(v[0], p, q);	 
		if (o == 0)
			return dist(v[0], p) < dist(v[0], q);
		return o == 1;
	});

	vector<Point> hull;
	for (Point p : v)
	{
		while (hull.size() >= 2)
		{
			Point a = hull[hull.size() - 2];
			Point b = hull[hull.size() - 1];

			if (orientation(a, b, p) == -1)
				hull.pop_back();
			else break;
		}
		hull.pb(p);
	}
	return hull;
}

vector<Point> cw_hull() //from above
{
	sort(v.begin() + 1, v.end(), [&](Point const &p, Point const &q){
		int o = orientation(v[0], p, q);	 
		if (o == 0)
			return dist(v[0], p) < dist(v[0], q);
		return o == -1;
	});

	vector<Point> hull;
	for (Point p : v)
	{
		while (hull.size() >= 2)
		{
			Point a = hull[hull.size() - 2];
			Point b = hull[hull.size() - 1];

			if (orientation(a, b, p) == 1)
				hull.pop_back();
			else break;
		}
		hull.pb(p);
	}
	return hull;
}

int main()
{
	fastio;

	int n;
	cin >> n;

	v.resize(n);
	for (Point &p : v)
		cin >> p.x >> p.y;

	sort(v.begin(), v.end());

	vector<Point> ccw = ccw_hull();
	vector<Point> cw = cw_hull();

	set<Point> st;
	for (Point p : ccw) st.insert(p);
	for (Point p : cw) st.insert(p);

	cout << st.size() << '\n';
	for (Point p : st)
		cout << p.x << " " << p.y << '\n';
	
	return 0;
}
