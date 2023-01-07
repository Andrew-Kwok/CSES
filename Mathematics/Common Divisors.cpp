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

int const N = 1e6 + 7;
int fq[N];
int main()
{
	fastio;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		fq[x]++;
	}

	for (int i = N; i > 1; --i)
	{
		int ctr = 0;
		for (int j = i; j < N && ctr < 2; j += i)
			ctr += fq[j];

		if (ctr >= 2)
		{
			cout << i << '\n';
			return 0;
		}
	}

	cout << 1 << '\n';
	return 0;
}
