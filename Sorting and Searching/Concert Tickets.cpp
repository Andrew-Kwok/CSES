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

int main()
{
	fastio;

	int n, m;
	cin >> n >> m;

	multiset<int> mst;
	for (int i = 0; i < n; ++i)
	{
		int num; cin >> num;
		mst.insert(num);
	}

	for (int i = 0; i < m; ++i)
	{
		int x; cin >> x;

		if (mst.empty() || *mst.begin() > x)
		{
			cout << -1 << '\n';
			continue;
		}

		auto it = mst.upper_bound(x);
		it = prev(it);

		cout << *it << '\n';
		mst.erase(it);
	}

	return 0;
}
