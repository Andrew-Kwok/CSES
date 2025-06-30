#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> A[2];
	for (int i = 0; i < 2; ++i)
	{
		A[i].resize(N);
		for (int &x : A[i])
			cin >> x, --x;
	}

	ll Z = 0;
	int top = 0, bot = 0;
	for (int i = 0; i < N; ++i) 
	{
		top += A[0][i], bot += A[1][i];
		if (top < 0 && bot > 0) 
		{
			int mn = min(-top, bot);
			Z += mn; top += mn; bot -= mn;
		} 
		else if (top > 0 && bot < 0) 
		{
			int mn = min(top, -bot);
			Z += mn; top -= mn; bot += mn;
		}

		Z += abs(top) + abs(bot);
	}
	cout << Z << '\n';

	return 0;
}