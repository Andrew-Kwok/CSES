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
const int MAX = 1e6 + 69;
const ll inf = 1e18 + 69;

struct Line
{
    ll m, c;
    Line(ll _m = 1e9, ll _c = 1e9) : m(_m), c(_c) {}

    ll operator() (ll x) { return m * x + c; }
} lichao[4 * MAX];


inline void insert(Line seg, int node = 1, int l = 1, int r = 1e6)
{
    if (l == r)
    {
        if (seg(l) < lichao[node](l))
            lichao[node] = seg; 
        return;
    }

    int mid = (l + r) >> 1;
    if (lichao[node].m < seg.m) swap(lichao[node], seg);
    if (lichao[node](mid) > seg(mid))
    {
        swap(lichao[node], seg);
        insert(seg, node << 1, l, mid);
    }
    else insert(seg, node << 1 | 1, mid+1, r);
}
    
inline ll query(ll x, int node = 1, int l = 1, int r = 1e6)
{
    if (l > x || r < x)
        return inf;
    if (l == r)
        return lichao[node](x);

    int mid = (l + r) >> 1;
    return min(lichao[node](x), min(query(x, node << 1, l, mid), query(x, node << 1 | 1, mid+1, r)));
}


int main()
{
	fastio;

	ll n, m;
	cin >> n >> m;

	vector<ll> s(n), f(n);
	for (ll &x : s)
		cin >> x;
	for (ll &x : f)
		cin >> x;

    insert(Line(m, 0ll));
	for (int i = 0; i < n; ++i)
	{
    	ll res = query(s[i]);
		insert(Line(f[i], res));

		if (i == n-1)
			cout << res << '\n';
	}

	return 0;
}
