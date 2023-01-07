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

int p[N];
int main()
{
	fastio;

	int n, x;
	cin >> n >> x;

	for (int i = 0; i < n; ++i)
		cin >> p[i];
	sort(p, p+n, greater<int>());

	multiset<int> mst;
	for (int i = 0; i < n; ++i)
		mst.insert(x);


	for (int i = 0; i < n; ++i)
	{
		auto it = mst.lower_bound(p[i]);

		int new_val;
		if (*it == x) new_val = *it - p[i];
		else new_val = 0;

		mst.erase(it);
		mst.insert(new_val);
	}

	int res = 0;
	for (auto num : mst)
		res += (num != x);

	cout << res << '\n';
	return 0;
}
