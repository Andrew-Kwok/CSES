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

	int n;
	cin >> n;

	ll sum = 1LL * n * (n+1) / 2;

	if (sum & 1)
	{
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	vector<int> a, b;
	ll ctr = sum / 2;
	for (int i = n; i >= 1; --i)
	{
		if (ctr >= i) a.pb(i), ctr -= i;
		else b.pb(i);
	}

	cout << a.size() << '\n';
	for (int i = 0; i < a.size(); ++i)
	{
		if (i) cout << " ";
		cout << a[i];
	}
	cout << '\n';

	cout << b.size() << '\n';
	for (int i = 0; i < b.size(); ++i)
	{
		if (i) cout << " ";
		cout << b[i];
	}
	cout << '\n';

	return 0;
}
