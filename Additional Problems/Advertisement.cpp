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

	vector<ll> v(n);
	for (ll &x : v)
		cin >> x;

	ll res = 0;
	vector<pl> st;
	for (int i = 0; i < n; ++i)
	{
		int pos = i;
		while (!st.empty() && st.back().f1 >= v[i])
		{
			res = max(res, st.back().f1 * (i - st.back().s2));
			pos = st.back().s2;
			st.pop_back();
		}
		st.pb({v[i], pos});
	}

	while (!st.empty())
	{
		res = max(res, st.back().f1 * (n - st.back().s2));
		st.pop_back();
	}

	cout << res << '\n';

	return 0;
}
