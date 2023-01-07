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

int const N = 1e5 + 7;
int ds[N];

int frep(int x)
{
	return ds[x] == x ? x : ds[x] = frep(ds[x]);
}

void join(int a, int b)
{
	a = frep(a); b = frep(b);
	ds[b] = a;
}

int main()
{
	fastio;

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		ds[i] = i;

	vector<pair<ll, ii>> v(m);
	for (auto &x : v)
		cin >> x.s2.f1 >> x.s2.s2 >> x.f1;

	sort(v.begin(), v.end());
	ll res = 0;
	for (auto x : v)
	{
		if (frep(x.s2.f1) != frep(x.s2.s2))
		{
			res += x.f1;
			join(x.s2.f1, x.s2.s2);
		}
	}

	for (int i = 2; i <= n; ++i)
	{
		if (frep(1) != frep(i))
		{
			debug(i);
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}

	cout << res << '\n';
	return 0;
}
