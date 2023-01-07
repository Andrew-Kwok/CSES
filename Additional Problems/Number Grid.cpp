#include <bits/stdc++.h>
using namespace std;

// int ar[20][20];

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int y, x;
	cin >> y >> x;

	int res = 0;
	y--; x--;
	for (int i = 0; i < 30; ++i)
	{
		if ((x >> i & 1) ^ (y >> i & 1))
			res += (1 << i);
	}
	cout << res << '\n';

	// bitset<50> used;
	// for (int i = 0; i < 20; ++i)
	// {
	// 	for (int j = 0; j < 20; ++j)
	// 	{
	// 		used.reset();
	// 		for (int k = 0; k < j; ++k)
	// 			used[ar[i][k]] = 1;
	// 		for (int k = 0; k < i; ++k)
	// 			used[ar[k][j]] = 1;

	// 		for (int k = 0; k < 50; ++k)
	// 		{
	// 			if (!used[k])
	// 			{
	// 				ar[i][j] = k;
	// 				break;
	// 			}
	// 		}
	// 	}
	// }

	// for (int i = 0; i < 20; ++i)
	// 	for (int j = 0; j < 20; ++j)
	// 		cout << setw(2) << ar[i][j] << " \n"[j+1 == 20];

	return 0;
}