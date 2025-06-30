#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll fact[21];

void solve1()
{
	int N; ll K;
	cin >> N >> K; --K;

	vector<int> v(N);
	iota(v.begin(), v.end(), 1);
	for (int i = N-1; i >= 0; --i)
	{
		ll id = K / fact[i]; K %= fact[i];
		cout << v[id] << " ";
		
		v.erase(v.begin() + id);
	}
	cout << '\n';
}

void solve2() 
{
	int N; cin >> N;

	vector<int> v(N);
	for (int &x : v)
		cin >> x;

	ll Z = 0;
	for (int i = 0; i < N; ++i)
	{
		int small = 0;
		for (int j = i+1; j < N; ++j)
			small += v[j] < v[i];
		Z += small * fact[N-1-i];
	}

	cout << Z+1 << '\n';
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	fact[0] = 1;
	for (int i = 1; i < 21; ++i)
		fact[i] = i * fact[i-1];

	int tc; cin >> tc;
	while (tc--)
	{
		int ty; cin >> ty;
		if (ty == 1) solve1();
		else solve2();
	}

	return 0;
}