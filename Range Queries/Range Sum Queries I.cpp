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
int const N = 2e5 + 7;

ll pfx[N];
int main()
{
	fastio;

	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; ++i)
		cin >> pfx[i], pfx[i] += pfx[i-1];

	while (q--)
	{
		int a, b;
		cin >> a >> b;
		cout << pfx[b] - pfx[a-1] << '\n';
	}

	return 0;
}
