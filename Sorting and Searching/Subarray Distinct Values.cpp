#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x...) cerr << "[" << #x << "]: " << x << "\n";

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using pl = pair<ll, ll>;

ld const PI = 4*atan((ld)1);
int const MAX = 2e5 + 7;

int n;
int ar[MAX];
int fq[MAX];

void compress()
{
	vector<int> v;
	for (int i = 1; i <= n; ++i)
		v.pb(ar[i]);
	sort(v.begin(), v.end());

	for (int i = 1; i <= n; ++i)
	{
		ar[i] = lower_bound(v.begin(), v.end(), ar[i]) - v.begin();
	}
}

int main()
{
	fastio;

	int k;
	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
		cin >> ar[i];
	compress();

	int ctr = 0;
	ll res = 0;
	for (int i = 1, j = 1; j <= n; ++j)
	{
		if (fq[ar[j]] == 0)
			ctr++;
		fq[ar[j]]++;


		while (ctr > k)
		{
			if (fq[ar[i]] == 1)
				ctr--;
			fq[ar[i++]]--;

			cerr << i << '\n';
		}

		res += j - i + 1;
	}
	cout << res << '\n';

	return 0;
}
