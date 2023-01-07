#include <iostream>
#include <vector>
using namespace std;

#define pb push_back
#define ll long long

struct Point
{
	int x, y;
	Point() : x(0), y(0) {}
	Point(int _x, int _y) : x(_x), y(_y) {}

	friend ostream& operator<< (ostream &os, const Point &p) { return os << "(" << p.x << "," << p.y << ")"; }
	friend bool operator== (const Point &a, const Point &b) { return a.x == b.x && a.y == b.y; }
	friend bool operator!= (const Point &a, const Point &b) { return a.x != b.x || a.y != b.y; }
};

inline int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<Point> v(n);
	for (auto &[x, y] : v)
		cin >> x >> y;
	v.pb(v[0]);

	ll area = 0;
	for (int i = 0; i < n; ++i)
	{
		area += 1ll * v[i].x * v[i+1].y;
		area -= 1ll * v[i+1].x * v[i].y;
	}
	area = abs(area);

	ll peri = n;
	for (int i = 0; i < n; ++i)
	{
		int a = abs(v[i+1].x - v[i].x);
		int b = abs(v[i+1].y - v[i].y);

		int g = gcd(a, b);
		peri += g - 1;
	}
	cout << (area + 2 - peri) / 2 << " " << peri << '\n';

	return 0;
}