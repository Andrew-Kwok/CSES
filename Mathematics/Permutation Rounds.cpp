#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAX = 1 << 18;
const int mod = 1e9 + 7;

int N, P[MAX], spf[MAX], fq[MAX];
bitset<MAX> vst;

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	
	iota(spf, spf + MAX, 0);
	for (int i = 2; i < MAX; ++i) if (spf[i] == i)
	{
		for (ll j = 1ll*i*i; j < MAX; j += i)
			spf[j] = i;
	}

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> P[i];

	for (int i = 1; i <= N; ++i) if (!vst[i])
	{
		int len = 0;
		for (int cur = i; !vst[cur]; cur = P[cur])
			vst[cur] = true, len++;
	
		int prv = 0, ctr = 0;
		for (; len > 1; len /= spf[len])
		{
			if (prv == spf[len]) ctr++;
			else prv = spf[len], ctr = 1;
			fq[prv] = max(fq[prv], ctr);
		}
	}

	ll Z = 1;
	for (int i = 1; i < MAX; ++i) 
	{
		for (int j = 0; j < fq[i]; ++j)
			(Z *= i) %= mod;
	}
	cout << Z << '\n';

	return 0;
}