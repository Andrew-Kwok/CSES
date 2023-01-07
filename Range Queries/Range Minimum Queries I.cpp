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
int const lgN = log2(N) + 1;

int st[N][lgN];
int lg[N];

int main()
{
	fastio;

	int n, q;
	cin >> n >> q;

	lg[1] = 0;
	for (int i = 2; i <= n; ++i)
		lg[i] = lg[i/2] + 1;

	for (int i = 1; i <= n; ++i)
		cin >> st[i][0];

	for (int j = 1; j <= lg[n]; ++j)
		for (int i = 1; i + (1 << j) - 1 <= n; ++i)
			st[i][j] = min(st[i][j-1], st[i + (1 << (j-1))][j-1]);

	while (q--)
	{
		int a, b;
		cin >> a >> b;

		int j = lg[b - a + 1];
		cout << min(st[a][j], st[b - (1 << j) + 1][j]) << '\n';
	}

	return 0;
}
