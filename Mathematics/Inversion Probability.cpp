#include <iostream>
#include <iomanip>
#include <vector>
#include <functional>
using namespace std;

#define ld long double

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int &x : v)
		cin >> x;

	const auto get = [](int a, int b) -> ld
	{
		ld res = 0;
		if (a <= b) res = a * (a-1) / 2;
		else res = b * (b-1) / 2 + (a-b) * b; 

		return res / (a*b);
	};

	ld res = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j)
			res += get(v[i], v[j]);
	
	cout << fixed << setprecision(6) << res << '\n';

	return 0;
}