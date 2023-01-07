#include <bits/stdc++.h>
using namespace std;

#define ll long long

int const N = 1e6 + 7;
ll const mod = 1e9 + 7;

inline ll add(ll x, ll y)
{
	return (x + y) % mod;
}

inline ll mul(ll x, ll y)
{
	return (x * y) % mod;
}

int D[N];
int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	D[1] = 0;
	D[2] = 1;

	for (int i = 3; i < N; ++i)
		D[i] = mul(i-1, add(D[i-1], D[i-2]));

	int n;
	cin >> n;
	cout << D[n] << '\n';


	return 0;
}