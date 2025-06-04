#include <bits/stdc++.h>
using namespace std;

const int MAX = 1 << 18;

int N, K;
int ar[MAX];

int main() 
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> ar[i];

	map<int, int> memo;
	for (int i = 0; i < K; ++i)
	{
		memo[ar[i]] = i;
	}

	cout << memo.size();;
	for (int i = K; i < N; ++i)
	{
		memo[ar[i]] = i;
		if (memo[ar[i-K]] <= i-K)
			memo.erase(ar[i-K]);

		cout << " " << memo.size();
	}

	return 0;
}