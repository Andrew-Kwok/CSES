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

constexpr ld PI = 4*atan((ld)1);

struct Line
{
	ll m, c;
	Line() : m(0), c(0) {}
	Line(ll _m, ll _c) : m(_m), c(_c) {}

	ld intersect(Line &o)
	{
		return (ld)(c - o.c) / (o.m - m);
	}
};

struct cht
{
	vector<Line> v;
	
	void addLine(ll m, ll c)
	{
		Line l(m, c);
		while (v.size() >= 2 && v[(int)v.size() - 2].intersect(v.back()) >= v.back().intersect(l))
			v.pop_back();
		v.pb(l);
	}

	ll query(ll x)
	{
		int l = 0, r = (int)v.size() - 1;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (v[mid].intersect(v[mid+1]) >= x) r = mid;
			else l = mid + 1;
		}
		return v[l].m * x + v[l].c;
	}
} ch;

int main()
{
	fastio;

	int n, m;
	cin >> n >> m;

	vector<int> s(n), f(n);
	for (int &x : s)
		cin >> x;
	for (int &x : f)
		cin >> x;

	ch.addLine(m, 0);
	for (int i = 0; i < n; ++i)
	{
		ll res = ch.query(s[i]);
		if (ch.v.back().m != f[i])
			ch.addLine(f[i], res);

		if (i == n-1)
			cout << res << '\n';
	}

	return 0;
}
