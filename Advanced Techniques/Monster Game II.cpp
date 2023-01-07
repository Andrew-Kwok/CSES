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

struct Line {
  mutable ll m, b, p;
  bool operator<(const Line& o) const { return m < o.m; }
  bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
  // (for doubles, use inf = 1/.0, div(a,b) = a/b)
  const ll inf = LLONG_MAX;
  ll div(ll a, ll b) { // floored division
    return a / b - ((a ^ b) < 0 && a % b); 
  }
  bool isect(iterator x, iterator y) {
    if (y == end()) { x->p = inf; return false; }
    if (x->m == y->m) x->p = x->b > y->b ? inf : -inf;
    else x->p = div(y->b - x->b, x->m - y->m);
    return x->p >= y->p;
  }
  void add(ll m, ll b) {
    auto z = insert({m, b, 0}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
  }
  ll query(ll x) {
    assert(!empty());
    auto l = *lower_bound(x);
    return l.m * x + l.b;
  }
};

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

	LineContainer ch;
	
	ch.add(-m, 0);
	for (int i = 0; i < n; ++i)
	{
		ll res = ch.query(s[i]);
		ch.add(-f[i], res);

		if (i == n-1)
			cout << -res << '\n';
	}

	return 0;
}
