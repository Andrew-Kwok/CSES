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

	int n;
	vector<ii> v;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		v.pb({a, b});
	}

	sort(v.begin(), v.end(), [](ii const &x, ii const &y){
		return x.s2 < y.s2 || x.s2 == y.s2 && x.f1 < y.f1;
	});

	int lst = 0;
	int res = 0;
	for (auto x : v)
	{
		if (x.f1 >= lst)
			lst = x.s2, res++;
	}
	cout << res << '\n';

	return 0;
}
