#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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

	int Xk = X;
	ll p1 = 0, p2 = 0, Z = 0;
	for (int i = 0; i < K-1; ++i)
	{
		p2 += Xk;
		Xk = f(Xk);
	}

	for (int i = K-1; i < N; ++i)
	{
		p2 += Xk; Xk = f(Xk);
		Z ^= (p2 - p1);
		p1 += X; X = f(X);
	}

	cout << Z << '\n';
	return 0;
}