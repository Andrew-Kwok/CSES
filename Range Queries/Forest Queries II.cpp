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
int const MAX = 1007;

bool ar[MAX][MAX];
int bit[MAX][MAX];

inline void add(int r, int c, int val)
{
	for (int i = r; i < MAX; i += (i & -i))
		for (int j = c; j < MAX; j += (j & -j))
			bit[i][j] += val;
}

inline int sum(int r, int c)
{
	int res = 0;
	for (int i = r; i > 0; i -= (i & -i))
		for (int j = c; j > 0; j -= (j & -j))
			res += bit[i][j];
	return res;
}

int main()
{
	fastio;

	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; ++i)
	{
		string s;
		cin >> s;

		for (int j = 1; j <= n; ++j)
		{
			if (s[j-1] == '*')
			{
				ar[i][j] = true;
				add(i, j, 1);
			}
		}
	}

	while (q--)
	{
		int t;
		cin >> t;

		if (t == 1)
		{
			int r, c;
			cin >> r >> c;

			add(r, c, !ar[r][c] - ar[r][c]);
			ar[r][c] = !ar[r][c];
		}
		else
		{
			int r1, c1, r2, c2;
			cin >> r1 >> c1 >> r2 >> c2;
			cout << sum(r2, c2) - sum(r1-1, c2) - sum(r2, c1-1) + sum(r1-1, c1-1) << '\n';
		}
	}

	return 0;
}
