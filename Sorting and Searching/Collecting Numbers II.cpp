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
int const MAX = 2e5 + 7;

int loc[MAX];
int ar[MAX];

static int res = 1;

inline void remove(int u, int v)
{
	if (u > v)
		swap(u, v);

	if (u+1 == v)
	{
		res -= loc[u] < loc[u-1];
		res -= loc[u+1] < loc[u];
		res -= loc[u+2] < loc[u+1];
	}
	else
	{
		res -= loc[u] < loc[u-1];
		res -= loc[u+1] < loc[u];

		res -= loc[v] < loc[v-1];
		res -= loc[v+1] < loc[v];
	}
}

inline void add(int u, int v)
{
	if (u > v)
		swap(u, v);

	if (u+1 == v)
	{
		res += loc[u] < loc[u-1];
		res += loc[u+1] < loc[u];
		res += loc[u+2] < loc[u+1];
	}
	else
	{
		res += loc[u] < loc[u-1];
		res += loc[u+1] < loc[u];

		res += loc[v] < loc[v-1];
		res += loc[v+1] < loc[v];
	}
}

int main()
{
	fastio;

	int n, q;
	cin >> n >> q;

	loc[0] = 0;
	loc[n+1] = n+1;
	for (int i = 1; i <= n; ++i)
		cin >> ar[i], loc[ar[i]] = i;

	for (int i = 1; i <= n; ++i)
		res += (loc[i] < loc[i-1]);

	while (q--)
	{
		int i, j;
		cin >> i >> j;

		remove(ar[i], ar[j]);

		swap(ar[i], ar[j]);
		loc[ar[i]] = i;
		loc[ar[j]] = j;

		add(ar[i], ar[j]);

		cout << res << '\n';
	}

	return 0;
}
