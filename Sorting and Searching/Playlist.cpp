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

map<int, int> memo;
int main()
{
	fastio;

	int n;
	cin >> n;

	int res = 0;
	int prv = 0;
	int k;

	for (int i = 1; i <= n; ++i)
	{
		cin >> k;
		prv = max(prv, memo[k]);
		res = max(res, i - prv);
		memo[k] = i;
	}
	cout << res << '\n';

	return 0;
}
