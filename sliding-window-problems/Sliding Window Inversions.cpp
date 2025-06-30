#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAX = 1 << 18;

int bit[MAX];
inline void add(int x, int val)
{
	for (++x; x < MAX; x += (x & -x))
		bit[x] += val;
}

inline int sum(int x)
{
	int Z = 0;
	for (++x; x > 0; x -= (x & -x))
		Z += bit[x];
	return Z;
}

int N, K, X[MAX];

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	vector<int> zip;
	zip.reserve(N);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> X[i]; zip.emplace_back(X[i]);
	}

	sort(zip.begin(), zip.end());
	zip.resize(unique(zip.begin(), zip.end()) - zip.begin());

	for (int i = 0; i < N; ++i)
		X[i] = (int)(lower_bound(zip.begin(), zip.end(), X[i]) - zip.begin());

	ll Z = 0;
	for (int i = 0; i < K; ++i)
	{
		Z += sum(MAX-2) - sum(X[i]);
		add(X[i], 1);
	}

	cout << Z;
	for (int i = K; i < N; ++i)
	{
		Z += sum(MAX-2) - sum(X[i]); add(X[i], 1);
		Z -= sum(X[i-K] - 1); add(X[i-K], -1);

		cout << " " << Z;
	}
	cout << '\n';

	return 0;
}