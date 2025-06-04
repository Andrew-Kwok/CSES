#include <bits/stdc++.h>
using namespace std;

const int MAX = 1 << 18;

int N, K;
int ar[MAX], idx[MAX], bit[MAX];

inline void add(int x, int val) 
{
	for (; x < MAX; x |= x+1)
		bit[x] += val;
}

inline int query(int x)
{
	int Z = 0;
	for (; x > 0; x &= x-1) 
		Z += bit[x-1];
	return Z;
}


int main() 
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> ar[i];


	memset(idx, -1, sizeof(idx));
	for (int i = 0; i < K; ++i) if (ar[i] < MAX)
	{
		if (idx[ar[i]] == -1)
			add(ar[i], 1);
		idx[ar[i]] = i;
	}

	const auto mex = [&]() -> int
	{
		int l = 0, r = MAX-1;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (query(mid+1) < mid) r = mid;
			else l = mid + 1;
		}
		return l;
	};

	cerr << query(1) << '\n';

	cout << mex() << '\n';
	for (int i = K; i < N; ++i)
	{
		if (ar[i] < MAX) 
		{
			if (idx[ar[i]] <= i-K)
				add(ar[i], 1);
			idx[ar[i]] = i;
		}
		if (ar[i-K] < MAX && idx[ar[i-K]] <= i-K)
		{
			add(ar[i-K], -1);
		}
		cout << " " << mex();
	}

	return 0;
}