#include <iostream>
#include <iomanip>
using namespace std;

#define ld long double

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	const auto fpow = [](ld x, int y) -> ld
	{
		ld res = 1;
		for (; y > 0; y >>= 1, x *= x)
			if (y & 1)
				res *= x;
		return res;
	};

	long double ans = 0;
	for (int i = 1; i <= k; ++i)
		ans += i * (fpow( (ld)i/k, n) - fpow( (ld)(i-1)/k, n));
	cout << fixed << setprecision(6) << ans << '\n';


	return 0;
}