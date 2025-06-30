#include <bits/stdc++.h>
using namespace std;

using lll = __int128_t;

const int MAX = 1 << 18;

int N, X[MAX], Y[MAX];

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> X[i] >> Y[i];
	sort(X, X+N);
	sort(Y, Y+N);

	lll Z = 0, sum = 0;
	for (int i = 0; i < N; ++i)
	{
		Z += 1ll * i * X[i] - sum;
		sum += X[i];
	}

	sum = 0;
	for (int i = 0; i < N; ++i)
	{
		Z += 1ll * i * Y[i] - sum;
		sum += Y[i];
	}

	if (Z == 0)
	{
		puts("0");
		return 0;
	}

	string res = "";
	for (; Z; Z /= 10)
		res += (char)('0' + Z%10);
	reverse(res.begin(), res.end());

	cout << res << '\n';
	return 0;
}