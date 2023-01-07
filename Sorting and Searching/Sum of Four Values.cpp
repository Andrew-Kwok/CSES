#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x...) cerr << "[" << #x << "]: " << x << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;

ld const PI = 4*atan((ld)1);

int const N = 1e3 + 7;

ii ar[N];
vector<pair<int, ii>> v;

bool different(int a, int b, int c, int d)
{
	int tmp[4] = {a, b, c, d};
	for (int i = 0; i < 4; ++i)
		for (int j = i+1; j < 4; ++j)
			if (tmp[i] == tmp[j])
				return false;
	return true;
}

int main()
{
	fastio;

	int n, x;
	cin >> n >> x;

	for (int i = 0; i < n; ++i)
		cin >> ar[i].f1, ar[i].s2 = i+1;

	sort(ar, ar+n);
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j <  n; ++j)
			v.pb({ar[i].f1 + ar[j].f1, {i, j}});

	sort(v.begin(), v.end());
	for (int i = 0, j = v.size() - 1; i < j; ++i)
	{
		ll sum = x - v[i].f1;

		while (i < j && v[j].f1 > sum) --j;
		if (i < j && v[j].f1 == sum && different(v[i].s2.f1, v[i].s2.s2, v[j].s2.f1, v[j].s2.s2))
		{
			cout << ar[v[i].s2.f1].s2 << " " << ar[v[i].s2.s2].s2 << " " << ar[v[j].s2.f1].s2 << " " << ar[v[j].s2.s2].s2 << '\n';
			return 0;
		}
	}
	for (int i = 0, j = v.size() - 1; i < j; --j)
	{
		ll sum = x - v[j].f1;

		while (i < j && v[i].f1 > sum) ++i;
		if (i < j && v[i].f1 == sum && different(v[i].s2.f1, v[i].s2.s2, v[j].s2.f1, v[j].s2.s2))
		{
			cout << ar[v[i].s2.f1].s2 << " " << ar[v[i].s2.s2].s2 << " " << ar[v[j].s2.f1].s2 << " " << ar[v[j].s2.s2].s2 << '\n';
			return 0;
		}
	}

	cout << "IMPOSSIBLE\n";
	return 0;
}
