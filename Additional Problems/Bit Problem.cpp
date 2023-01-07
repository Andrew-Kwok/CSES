#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x) cerr << "[" << #x << "]: " << x << "\n";

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using pl = pair<ll, ll>;

const ld PI = 4*atan((ld)1);
const int MAX = 1 << 20;
const int LG = 20;

int A[MAX][21]; // x | y == x
int B[MAX][21]; // x & y == x

void solve()
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (int &x : v)
	{
		cin >> x;
		A[x][0]++;
		B[x][0]++;
	}

	for (int mask = 0; mask < MAX; ++mask)
	{
		for (int i = 0; i < LG; ++i)
		{
			A[mask][i+1] += A[mask][i];
			if (mask >> i & 1)
				A[mask][i+1] += A[mask ^ (1 << i)][i];
		}
	}

	for (int mask = MAX-1; mask >= 0; --mask)
	{
		for (int i = 0; i < LG; ++i)
		{
			B[mask][i+1] += B[mask][i];
			if (mask >> i & 1)
				B[mask ^ (1 << i)][i+1] += B[mask][i];
		}
	}

	for (int x : v)
		cout << A[x][20] << " " << B[x][20] << " " << n - A[MAX - 1 - x][20] << '\n';
}

int main()	
{
	fastio;

	int TC = 1;
	//cin >> TC;

	while (TC--)
		solve();

	return 0;
}
