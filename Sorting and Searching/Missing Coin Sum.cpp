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

int main()
{
	fastio;

	int n;
	cin >> n;

	vector<int> v(n);
	for (int &x : v)
		cin >> x;
	sort(v.begin(), v.end());
	v.pb(-1);

	if (v[0] != 1)
	{
		cout << 1 << '\n';
		return 0;
	}

	ll sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += v[i];
		if (i+1 == n || v[i+1] > sum + 1)
		{
			cout << sum + 1 << '\n';
			return 0;
		}
	}

	return 0;
}
