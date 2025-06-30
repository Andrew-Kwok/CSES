#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	map<int, vector<int>> pos;
	for (int i = 0; i < N; ++i)
	{
		int x; cin >> x;
		pos[x].emplace_back(i);
	}

	ll Z = 0;
	const auto triangle = [&](int x) -> ll
	{
		return 1ll * x * (x+1) / 2;
	};

	for (auto [_, v] : pos)
	{
		Z += triangle(N);
		for (int i = 0; i+1 < (int)v.size(); ++i)
		{
			Z -= triangle(v[i+1] - v[i] - 1);
		}
		Z -= triangle(v[0]);
		Z -= triangle(N-1 - v.back());
	}

	cout << Z << '\n';
	return 0;
}