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

const int MAX = 2e5 + 7;

int n;
int p[MAX];
int up[MAX][30];

void init()
{
	for (int i = 1; i <= n; ++i)
		up[i][0] = p[i];

	for (int j = 1; j < 30; ++j)
		for (int i = 1; i <= n; ++i)
			up[i][j] = up[up[i][j-1]][j-1];
}

int main()
{
	fastio;

	int q;
	cin >> n >> q;

	for (int i = 1; i <= n; ++i)
		cin >> p[i];
	init();

	while (q--)
	{
		int x, k;
		cin >> x >> k;

		for (int j = 0; j < 30; ++j)
			if (k & (1 << j))
				x = up[x][j];
		cout << x << '\n';
	}

	return 0;
}
