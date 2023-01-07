#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

const int MAX = 1e6 + 69;

int fq[MAX] = {};
int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	ll res = 1LL * n * (n-1) / 2;
	while (n--)
	{
		int x; cin >> x;
		
		vector<int> p;
		for (int i = 2; i*i <= x; ++i)
		{
			if (x % i == 0)
			{
				p.pb(i);
				while (x % i == 0)
					x /= i;
			}
		}
		if (x > 1) p.pb(x);

		for (int mask = 1; mask < (1 << p.size()); ++mask)
		{
			int mtp = 1;
			for (int i = 0; i < (int)p.size(); ++i)
			{
				if (mask >> i & 1)
					mtp *= p[i];
			}

			if (__builtin_popcount(mask) & 1) res -= fq[mtp];
			else res += fq[mtp];
			fq[mtp]++;
		}
	}
	cout << res << '\n';

	return 0;
}