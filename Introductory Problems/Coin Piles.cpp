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

int main()
{
	fastio;

	int t;
	cin >> t;

	while (t--)
	{
		int a, b;
		cin >> a >> b;

		int dif = abs(a - b);
		a = b = min(a - dif, b - dif);

		if (a >= 0 && a % 3 == 0) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}
