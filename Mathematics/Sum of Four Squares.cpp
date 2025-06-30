#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e7 + 69;

bitset<MAX> good;

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i*i < MAX; ++i)
	{
		for (int j = i; i*i + j*j < MAX; ++j) 
			good[i*i + j*j] = 1;
	}

	int tc; cin >> tc;
	while (tc--) 
	{
		int N; cin >> N;

		int a = -1, b = -1;
		for (int i = 0; i*i <= N && a == -1; ++i)
		{
			for (int j = i; i*i + j*j <= N && a == -1; ++j) if (good[N - i*i - j*j])
			{
				N -= i*i + j*j;
				a = i; b = j;
			}
		}

		for (int i = 0; i*i <= N; ++i)
		{
			int j = (int)sqrt(N - i*i);
			if (i*i + j*j == N)
			{
				cout << a << " " << b << " " << i << " " << j << '\n';
				break;
			}
		}
	}

	return 0;
}