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

ll ar[N];
set<ll> st;
int main()
{
	fastio;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> ar[i];
	sort(ar, ar+n);

	ll a = 0, b = 0;
	for (int i = 0; i < n; ++i)
	{
		st.insert(ar[i]);
		b += ar[i];
	}
	st.insert(b / n);
	st.insert(b / n + 1);

	ll res = 1e18;
	ll idx = 0;

	for (auto x : st)
	{
		while (ar[idx] < x)
			a += ar[idx], b -= ar[idx], idx++;
		
		//cout << x << " " << idx << " " << a << " " << b << '\n';
		//cout << (idx * x - a) << " " <<  (b - (n-idx) * x) << '\n';

		res = min(res, (idx * x - a) + (b - (n-idx) * x));
	}
	cout << res << '\n';
	return 0;
}
