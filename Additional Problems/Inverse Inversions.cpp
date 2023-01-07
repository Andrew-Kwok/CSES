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

const ld PI = 4*atan((ld)1);

void solve()
{
	ll N, K;
	cin >> N >> K;

	for (ll i = N; i >= 1; --i)
	{
		if (K >= i-1)
		{
			cout << i << " ";
			K -= i-1;
		}
		else
		{
			cout << K+1 << " ";
			for (int j = 1; j <= i; ++j)
			{
				if (j == K+1)
					continue;
				cout << j << " ";
			}
			cout << '\n';

			return;
		}
	}
}

int main()
{
	fastio;

	int TC = 1;
	//cin >> TC;

	while (TC--)
		solve();

	return 0;
}
