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

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		join(a, b);
	}

	vector<ii> res;
	for (int i = 2; i <= n; ++i)
	{
		if (frep(1) != frep(i))
		{
			res.pb({1, i});
			join(1, i);
		}
	}

	cout << res.size() << '\n';
	for (auto x : res)
		cout << x.f1 << " " << x.s2 << '\n';

	return 0;
}
