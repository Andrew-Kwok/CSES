#include <bits/stdc++.h>
using namespace std;

#define pb push_back

using ll = long long;

const int MAX = 1 << 20;

vector<int> prime;

void init()
{
	bitset<MAX> p;

	for (int i = 3; i < MAX; i += 2)
		p[i] = true;

	for (int i = 3; i < MAX; i += 2) if (p[i])
		for (ll j = 1ll*i*i; j < MAX; j += i)
			p[j] = false;

	prime.pb(2);
	for (int i = 3; i < MAX; i += 2) if (p[i])
		prime.pb(i);
}

void solve()
{
	ll N; cin >> N; ++N;

	// claim: next prime should be within [N+1, N+1000]
	bitset<1000> Z;
	for (int i = 0; i < 1000; ++i)
		Z[i] = true;

	for (int p : prime)
	{
		for (ll x = max(2ll*p, (N+p-1)/p * p); x < N+1000; x += p)
			Z[x-N] = false; 
	}

	for (int i = 0; i < 1000; ++i) if (Z[i])
	{
		cout << N+i << '\n';
		return;
	}

	assert(0);
}

int main()
{
	init();

	ios :: sync_with_stdio(0);
	cin.tie(0);

	int tc; cin >> tc;
	while (tc--)
	{
		solve();
	}

	return 0;
}