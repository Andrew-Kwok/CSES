#include <iostream>
#include <bitset>
using namespace std;

#pragma GCC target("popcnt")

const int MAX = 3000;

bitset<MAX> grid[MAX];
int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string s; cin >> s;
		grid[i] = bitset<MAX>(s);
	}

	long long res = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			int ctr = (int)(grid[i] & grid[j]).count();
			res += ctr * (ctr - 1) / 2;
		}
	}
	cout << res << '\n';

	return 0;
}