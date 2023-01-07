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

int const N = 1e5 + 7;

bool res[N] = {};
int main()
{
	fastio;

	int n;
	cin >> n;

	res[0] = true;
	for (int i = 0; i < n; ++i)
	{
		int coin;
		cin >> coin;

		for (int j = 1e5; j >= coin; --j)
			res[j] |= (res[j-coin]);
	}

	vector<int> v;
	for (int i = 1; i <= 1e5; ++i)
		if (res[i])
	{
		v.pb(i);
	}

	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); ++i)
	{
		if (i) cout << " ";
		cout << v[i];
	}
	cout << '\n';

	return 0;
}
