#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x...) cerr << "[" << #x << "]: " << x << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;

ld const PI = 4*atan((ld)1);

int const N = 1e6 + 7;
int const inf = 1e9 + 7;

int coin[N];
int res[N];
int main()
{
	fastio;

	int n, x;
	cin >> n >> x;

	res[0] = 0;
	for (int i = 1; i <= x; ++i)
		res[i] = inf;

	for (int i = 0; i < n; ++i)
		cin >> coin[i];

	for (int i = 1; i <= x; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i - coin[j] >= 0)
				res[i] = min(res[i], 1 + res[i - coin[j]]);
		}
	}
	cout << (res[x] == inf ? -1 : res[x]) << '\n';

	return 0;
}
