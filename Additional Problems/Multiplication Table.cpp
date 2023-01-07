#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

ll n;

inline ll solve(ll x)
{
	ll sum = 0;
	for (int i = 1; i <= n; ++i)
		sum += min(n, x/i);
	return sum;
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;


	ll l = 1, r = n*n;
	while (l < r)
	{
		ll mid = (l + r) >> 1;
		if (solve(mid) >= (n*n + 1)/2) r = mid;
		else l = mid + 1;
	}
	cout << l << '\n';

	return 0;
}