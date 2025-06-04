#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	map<int, int> memo;
	ll Z = 0; int prv = -1;
	for (int i = 0; i < N; ++i)
	{
		int x; cin >> x;
		if (memo.count(x)) prv = max(prv, memo[x]);
		Z += i-prv; memo[x] = i;
	}
	cout << Z << '\n';

	return 0;
}