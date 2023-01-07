#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ii pair<int, int>
#define f1 first
#define s2 second

int const N = 50;

int ar[N];
int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x;
	cin >> n >> x;

	for (int i = 0; i < n; ++i)
		cin >> ar[i];

	vector<int> v;
	vector<ii> a, b;
	for (int i = 0; i < (1 << (n/2)); ++i)
	{	
		int sum = 0;
		for (int j = 0; j < n/2; ++j)
		{
			if (i & (1 << j))
				sum += ar[j];

			if (sum > x)
				break;
		}

		if (sum <= x)
			v.pb(sum);
	}
	sort(v.begin(), v.end());

	for (int val : v)
	{
		if (!a.empty() && a.back().f1 == val)
			a.back().s2++;
		else a.pb({val, 1});
	}
	
	v.clear();
	for (int i = 0; i < (1 << (n - n/2)); ++i)
	{
		int sum = 0;
		for (int j = 0; j < (n - n/2); ++j)
		{
			if (i & (1 << j))
				sum += ar[j + n/2];

			if (sum > x)
				break;
		}

		if (sum <= x)
			v.pb(sum);
	}
	sort(v.begin(), v.end());

	for (int val : v)
	{
		if (!b.empty() && b.back().f1 == val)
			b.back().s2++;
		else b.pb({val, 1});
	}

	long long res = 0;
	for (int i = 0, j = (int)b.size() - 1; i < (int)a.size(); ++i)
	{
		while (j >= 0 && a[i].f1 + b[j].f1 > x)
			j--;

		if (j >= 0 && a[i].f1 + b[j].f1 == x)
			res += 1ll * a[i].s2 * b[j].s2;
	}

	cout << res << '\n';

	return 0;
}