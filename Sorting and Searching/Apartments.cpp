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

int a[N], b[N];
int main()
{
	fastio;

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i)
		cin >> b[i];

	sort(a, a+n);
	sort(b, b+m);

	int res = 0;
	for (int i = 0, j = 0; i < n && j < m;)
	{
		if (a[i] - k <= b[j] && b[j] <= a[i] + k) res++, i++, j++;
		else if (b[j] < a[i] - k) j++;
		else i++;
	}

	cout << res << '\n';

	return 0;
}
