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

int const N = 2e5 + 7;

ll n, t;
ll ar[N];

bool check(ll x)
{
	ll ctr = 0;
	for (int i = 0; i < n; ++i)
	{
		ctr += x / ar[i];

		if (ctr >= t)
			return true;
	}
	return false;
}

int main()
{
	fastio;

	cin >> n >> t;
	for (int i = 0; i < n; ++i)
		cin >> ar[i];

	ll lt = 1, rt = 1e18;
	while (lt < rt)
	{
		ll mid = (lt + rt) / 2;
		if (check(mid)) rt = mid;
		else lt = mid + 1;
	}
	cout << lt << '\n';

	return 0;
}
