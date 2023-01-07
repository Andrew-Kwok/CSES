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
int const inf  = 1e9 + 7;

int main()
{
	fastio;

	int n;
	cin >> n;

	multiset<int> mst;
	for (int i = 0; i < n; ++i)
		mst.insert(inf);

	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;

		auto it = mst.upper_bound(x);
		mst.erase(it);
		mst.insert(x);
	}

	int res = 0;
	for (auto x : mst)
		res += (x < inf);

	cout << res << '\n';

	return 0;
}
