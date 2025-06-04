#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1e9 + 7;

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	map<int, int> fq;
	for (int i = 0; i < N; ++i)
	{
		int x; cin >> x;
		fq[x]++;
	}

	ll Z = 1;
	for (auto [_, x] : fq)
		(Z *= x+1) %= mod;
	cout << Z-1 << '\n';

	return 0;
}