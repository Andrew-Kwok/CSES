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

	int n, x;
	cin >> n >> x;

	ll res = 0;
	ll sum = 0;
	map<ll, int> fq;
	fq[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;

		sum += num;
		res += fq[sum - x];
		fq[sum]++;
	}

	cout << res << '\n';

	return 0;
}
