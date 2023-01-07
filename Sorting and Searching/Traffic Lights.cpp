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

	int x, n;
	cin >> x >> n;

	multiset<int> mst, dst;
	mst.insert(0);
	mst.insert(x);
	dst.insert(x);

	for (int i = 0; i < n; ++i)
	{
		int p; cin >> p;

		multiset<int> :: iterator a, b, c; //Position before p, position after p, distance
		a = b = mst.lower_bound(p);
		a = prev(a);
		mst.insert(p);

		c = dst.lower_bound(*b - *a);
		dst.erase(c);
		dst.insert(*b - p);
		dst.insert(p - *a);
	
		cout << *(prev(dst.end())) << '\n';
	}

	return 0;
}
