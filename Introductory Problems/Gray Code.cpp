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
int const MAX = (1 << 16) + 7;

int n;
int res[MAX];

void out(int x)
{
	for (int i = 0; i < n; ++i)
		cout << ((x & (1 << i)) > 0);
	cout << '\n';
}

int main()
{
	fastio;

	cin >> n;

	res[0] = 0; out(res[0]);
	res[1] = 1; out(res[1]);

	int idx = 2;
	for (int i = 1; i < n; ++i)
	{
		for (int j = idx-1; j >= 0; --j)
			res[idx] = (1 << i) | (res[j]),
			out(res[idx++]);
	}

	return 0;
}
