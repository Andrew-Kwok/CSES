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

int const N = 2e5 + 7;

int ar[N];
int main()
{
	fastio;

	int n, x;
	cin >> n >> x;

	for (int i = 0; i < n; ++i)
		cin >> ar[i];

	int sum = 0;
	int res = 0;
	for (int i = 0, j = 0; i < n && j < n; ++j)
	{
		sum += ar[j];
		while (i < j && sum > x) sum -= ar[i++];

		if (sum == x)
			res++;
	}
	cout << res << '\n';

	return 0;
}
