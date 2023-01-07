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
const int MAX = 4e5 + 69;
const int LG = 18;

ll pfx[MAX];
int up[MAX][LG];

void solve()
{
	int n; ll k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
		cin >> pfx[i], pfx[i+n] = pfx[i];
	for (int i = 1; i < 2*n; ++i)
		pfx[i] += pfx[i-1];

	up[2*n][0]=  2*n;
	for (int i = 0, j = 0; i < 2*n; ++i)
	{
		while (j < 2*n && pfx[j] - (i ? pfx[i-1] : 0) <= k)
			j++;
		up[i][0] = j;
	}

	for (int j = 1; j < LG; ++j)
		for (int i = 0; i <= 2*n; ++i)
			up[i][j] = up[up[i][j-1]][j-1];


	int res = 1e9 + 69;
	for (int i = 0; i < n; ++i)
	{
		int cur = i, ctr = 0;
		for (int j = LG-1; j >= 0; --j)
			if (up[cur][j] < i+n)
				cur = up[cur][j], ctr += (1 << j);

		res = min(res, ctr);
	}

	cout << res+1 << '\n';
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
