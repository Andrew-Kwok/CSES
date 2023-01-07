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


ii ds[N];
int frep(int x)
{
	return ds[x].f1 == x ? x : ds[x].f1 = frep(ds[x].f1);
}

int component, sz;
void join(int x, int y)
{
	x = frep(x); y = frep(y);
	if (x == y)
		return;

	ds[x].f1 = y;
	ds[y].s2 += ds[x].s2;

	component--;
	sz = max(sz, ds[y].s2);
}

int main()
{
	fastio;

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
		ds[i] = {i, 1};

	component = n;
	sz = 1;

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		join(a, b);
		cout << component << " " << sz << '\n';
	}

	return 0;
}
