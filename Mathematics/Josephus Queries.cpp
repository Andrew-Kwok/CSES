#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k)
{
	if (n == 1)
		return 0;
	if (k <= n/2)
		return 2 * k - 1;
	
	if (n & 1)
	{
		int r = solve((n+1)/2, k - n/2);
		
		if (r == 0)
			return n-1;
		return 2 * (r-1);
	}
	else
	{
		return 2 * solve(n/2, k - n/2);
	}
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int q;
	cin >> q;

	while (q--)
	{
		int n, k;
		cin >> n >> k;

		cout << 1 + solve(n, k) << '\n';
	}

	return 0;
}