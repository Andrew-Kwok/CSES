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

int const N = 2e5 + 7;
ll bit[N];

inline void add(ll x, ll val)
{
	while (x < N)
		bit[x] += val, x += (x & -x);
}

inline ll sum(ll x)
{
	ll res = 0;
	while (x)
		res += bit[x], x -= (x & -x);
	return res;

}

int main()
{
	fastio;

	int n, q;
	cin >> n >> q;

	int t, a, b, u;
	for (int i = 1; i <= n; ++i)
	{
		cin >> u;
		add(i, u);
		add(i+1, -u);
	}

	while (q--)
	{
		cin >> t;
		if (t == 1)
		{
			cin >> a >> b >> u;
			add(a, u);
			add(b+1, -u);
		}
		else
		{
			cin >> u;
			cout << sum(u) << '\n';
		}
	}

	return 0;
}
