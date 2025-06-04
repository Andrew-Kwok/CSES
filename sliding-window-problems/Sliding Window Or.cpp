#include <bits/stdc++.h>
using namespace std;

#define f1 first
#define s2 second

using ii = pair<int, int>;

const int MAX = 1e7 + 69;

int N, K;
int st[2 * MAX];

inline int query(int l, int r)
{
	int Z = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1) Z |= st[l++];
		if (r & 1) Z |= st[--r]; 
	}
	return Z;
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	int X, A, B, C;
	cin >> N >> K >> X >> A >> B >> C;

	const auto f = [A,B,C](int x) -> int
	{
		return (1ll*A*x+B) % C;
	};

	for (int i = 0; i < N; ++i)
	{
		st[i+N] = X;
		X = f(X);
	}
	for (int i = N-1; i >= 1; --i)
		st[i] = st[i << 1] | st[i << 1 | 1];

	int Z = 0;
	for (int i = 0; i < N-K+1; ++i) {
		Z ^= query(i, i+K);
	}		

	cout << Z << '\n';
	return 0;
}