#include <bits/stdc++.h>
using namespace std;

const int LG = 30;

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int basis[LG] = {};
	for (int i = 0; i < N; ++i)
	{
		int x; cin >> x;
		for (int j = LG-1; j >= 0; --j) if (x >> j & 1)
		{
			if (basis[j] == 0)
			{
				basis[j] = x;
				break;
			}
			x ^= basis[j];
		}
	}

	int Z = 1;
	for (int i = 0; i < LG; ++i) if (basis[i])
		Z <<= 1;
	cout << Z << '\n';

	return 0;
}