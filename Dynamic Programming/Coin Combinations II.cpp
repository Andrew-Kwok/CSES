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

int const N = 1e6 + 7;
int const inf = 1e9 + 7;
ll const mod = 1e9 + 7;

ll add(ll x, ll y)
{
	return (x + y) % mod;
}

int coin[107];
ll res[N] = {};
int main()
{
	fastio;

	int n, x;
	cin >> n >> x;

	res[0] = 1;
	for (int i = 0; i < n; ++i)
		cin >> coin[i];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= x - coin[i]; ++j)
			res[j + coin[i]] = add(res[j + coin[i]], res[j]);
	}
	cout << res[x] << '\n';

	return 0;
}
