#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool isTriangle(ll N)
{
	ll x = (sqrtl(8*N + 1) - 1) / 2;
	return x * (x+1) == 2 * N;
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	int tc; cin >> tc;
	while (tc--)
	{
		ll N;
		cin >> N;

		if (isTriangle(N))
		{
			cout << 1 << '\n';
			continue;
		}

		int Z = 3;
		for (ll a = 1; a * (a+1) <= N; ++a)
		{
			if (isTriangle(N - a * (a+1) / 2))
			{
				Z = 2;
				break;
			}
		}

		cout << Z << '\n';
	}

	return 0;
}