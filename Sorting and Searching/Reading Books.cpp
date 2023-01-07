#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long n, x, mx = 0, sum = 0;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		mx = max(mx, x);
		sum += x;
	}

	cout << max(2*mx, sum) << '\n';

	return 0;
}