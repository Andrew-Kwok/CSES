#include <bits/stdc++.h>
using namespace std;

#define f1 first
#define s2 second

using ii = pair<int, int>;

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	int N, K, X, A, B, C;
	cin >> N >> K >> X >> A >> B >> C;

	const auto f = [&](int x) -> int
	{
		return (1ll*A*x+B) % C;
	};

	deque<ii> dq;
	for (int i = 0; i < K-1; ++i)
	{
		while (!dq.empty() && dq.back().f1 >= X)
		{
			dq.pop_back();
		}
		dq.push_back({X, i});
		X = f(X);
	}

	int Z = 0;
	for (int i = K-1; i < N; ++i)
	{
		while (!dq.empty() && dq.back().f1 >= X)
		{
			dq.pop_back();
		}
		dq.push_back({X, i});
		X = f(X);

		while (i - dq.front().s2 >= K)
			dq.pop_front();
		Z ^= dq.front().f1;
	}

	cout << Z << '\n';
	return 0;
}