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

ll const mod = 1e9 + 7;

ll add(ll x, ll y)
{
	return (x + y) % mod;
}

int const N = 1e6 + 7;
ll res[N];

int main()
{
	fastio;

	int n;
	cin >> n;

	for (int i = 1; i <= 6; ++i)
		res[i] = 1;
	for (int i = 2; i <= n; ++i)
	{
		for (int j = max(1, i-6); j <= i-1; ++j)
			res[i] = add(res[i], res[j]);
	}
	cout << res[n] << '\n';

	return 0;
}
