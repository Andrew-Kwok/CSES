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
ll const inf = 9e18;

struct Point
{
	ll x, y;
	Point() : x(0), y(0) {}
	Point(ll a, ll b) : x(a), y(b) {}
	
	bool operator<(Point const &other) const { return x < other.x || (x == other.x && y < other.y); }
	bool operator==(Point const &other) const { return x == other.x && y == other.y; }
};

inline ll dist(Point const &p, Point const &q)
{
	return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

inline ll brute(vector<Point> v)
{
	ll res = inf;
	for (int i = 0; i < v.size(); ++i)
		for (int j = i+1; j < v.size(); ++j)
			res = min(res, dist(v[i], v[j]));
	return res;
}

ll combine(vector<Point> v, ll d)
{
	sort(v.begin(), v.end(), [](Point const &p, Point const &q){
		return p.y < q.y || (p.y == q.y && p.x < q.x);
	});

	for (int i = 0; i < v.size(); ++i)
		for (int j = i+1; j < v.size() && (v[i].y - v[j].y) * (v[i].y - v[j].y) < d; ++j)
			d = min(d, dist(v[i], v[j]));

	return d;
}

ll dnc(vector<Point> v)
{
	if (v.size() <= 3)
		return brute(v);

	int mid = (v.size() / 2);
	vector<Point> next_v;

	next_v.clear();
	for (int i = 0; i < mid; ++i)
		next_v.pb(v[i]);
	ll ld = dnc(next_v);

	next_v.clear();
	for (int i = mid; i < v.size(); ++i)
		next_v.pb(v[i]);
	ll rd = dnc(next_v);


	ll d = min(ld, rd);

	next_v.clear();
	for (int i = 0; i < v.size(); ++i)
		if ((v[i].x - v[mid].x) * (v[i].x - v[mid].x) < d)
			next_v.pb(v[i]);

	return min(d, combine(next_v, d));
}

int main()
{
	fastio;

	int n;
	cin >> n;

	vector<Point> v(n);
	for (Point &p : v)
		cin >> p.x >> p.y;

	sort(v.begin(), v.end());
	cout << dnc(v) << '\n';

	return 0;
}
