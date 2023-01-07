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
bool fq[N] = {};
int main()
{
	fastio;

	int n;
	cin >> n;

	for (int i = 1; i < n; ++i)
	{
		int num; cin >> num;
		fq[num] = true;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (!fq[i])
		{
			cout << i << '\n';
			return 0;
		}
	}

	return 0;
}
