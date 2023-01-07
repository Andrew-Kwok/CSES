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

ii ar[N];
multiset<int> mst;

int main()
{
	fastio;

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
		cin >> ar[i].f1 >> ar[i].s2;

	sort(ar, ar+n, [](ii const &x, ii const &y){
		return x.s2 < y.s2;
	});

	for (int i = 0; i < k; ++i)
		mst.insert(i);

	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		if (*mst.begin() > ar[i].f1)
			continue;

		res++;
		if (*prev(mst.end()) <= ar[i].f1)
		{
			mst.erase(prev(mst.end()));
			mst.insert(ar[i].s2);
		}
		else
		{
			auto it = mst.upper_bound(ar[i].f1);
			it = prev(it);
			mst.erase(it);
			mst.insert(ar[i].s2);
		}
	}
	cout << res << '\n';

	return 0;
}
