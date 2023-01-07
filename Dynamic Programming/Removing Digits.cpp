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

int const N = 1e6 + 7;

int res[N];
int main()
{
	fastio;

	for (int i = 0; i < N; ++i)
		res[i] = 1e9;
	res[0] = 0;

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		string s = to_string(i);
		for (auto x : s)
			res[i] = min(res[i], 1 + res[i - (x - '0')]);
	}
	cout << res[n] << '\n';

	return 0;
}
