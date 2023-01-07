#include <iostream>
using namespace std;

// source: https://youtu.be/ab_dY3dZFHM?t=79
const int KNIGHTS_TOUR[8][8] = {
	{60, 11, 56, 7, 54, 3, 42, 1},
	{57, 8, 59, 62, 31, 64, 53, 4},
	{12, 61, 10, 55, 6, 41, 2, 43},
	{9, 58, 13, 32, 63, 30, 5, 52},
	{34, 17, 36, 23, 40, 27, 44, 29},
	{37, 14, 33, 20, 47, 22, 51, 26},
	{18, 35, 16, 39, 24, 49, 28, 45},
	{15, 38, 19, 48, 21, 46, 25, 50}
};

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x, y;
	cin >> x >> y;
	x--; y--;

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			cout << 1 + (KNIGHTS_TOUR[i][j] - KNIGHTS_TOUR[y][x] + 64) % 64 << " ";
		}
		cout << '\n';
	}

	return 0;
}
