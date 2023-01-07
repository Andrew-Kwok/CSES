#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> v(n, 0);
	for (int i = 0; i < n; ++i)
	{	
		for (int j = 0; j < k; ++j)
		{
			char x; cin >> x;
			v[i] ^= (1 << j) * (x == '1');
		}
	}

	int res = k;
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j)
			res = min(res, __builtin_popcount(v[i] ^ v[j]));
	cout << res << '\n';

	return 0;
}