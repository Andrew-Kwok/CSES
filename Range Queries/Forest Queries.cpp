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

int const N = 1e3 + 7;
ll pfx[N][N];
char s[N][N];

int main()
{
	fastio;

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n; ++i)
		cin >> s[i];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
	{
		pfx[i+1][j+1] = (s[i][j] == '*') + pfx[i][j+1] + pfx[i+1][j] - pfx[i][j];
	}

	while (q--)
	{
		int r1, r2, c1, c2;
		cin >> r1 >> c1 >> r2 >> c2;

		cout << pfx[r2][c2] - pfx[r1-1][c2] - pfx[r2][c1-1] + pfx[r1-1][c1-1] << '\n';
	}

	return 0;
}
