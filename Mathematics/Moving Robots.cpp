#include <iostream>
#include <iomanip>
using namespace std;

#define ld long double

constexpr int dx[4] = {-1, 1, 0, 0};
constexpr int dy[4] = {0, 0, -1, 1};

ld dp[101][8][8];
ld res[8][8];

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			res[i][j] = 1;

	int k;
	cin >> k;

	const auto valid = [](int r, int c) -> bool
	{
		return 0 <= r && r < 8 && 0 <= c && c < 8;
	};

	for (int r = 0; r < 8; ++r)
	{
		for (int c = 0; c < 8; ++c)
		{
			for (int x = 0; x <= k; ++x)
				for (int i = 0; i < 8; ++i)
					for (int j = 0; j < 8; ++j)
						dp[x][i][j] = 0;

			dp[0][r][c] = 1;
			for (int x = 0; x < k; ++x)
			{
				for (int i = 0; i < 8; ++i)
				{
					for (int j = 0; j < 8; ++j)
					{
						int num = 0;
						for (int z = 0; z < 4; ++z)
							num += valid(i + dx[z], j + dy[z]);

						for (int z = 0; z < 4; ++z)
							if (valid(i + dx[z], j + dy[z]))
								dp[x+1][i + dx[z]][j + dy[z]] += dp[x][i][j] / num;
					}
				}
			}

			for (int i = 0; i < 8; ++i)
				for (int j = 0; j < 8; ++j)
					res[i][j] *= (1 - dp[k][i][j]);
		}
	}

	ld sum = 0;
	for (int r = 0; r < 8; ++r)
		for (int c = 0; c < 8; ++c)
			sum += res[r][c];


	cout << fixed << setprecision(6) << sum << '\n';
	return 0;
}