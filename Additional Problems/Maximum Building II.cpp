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
const int MAX = 1069;

int N, M;
char s[MAX][MAX];
int h[MAX];
int pfx[MAX][MAX];

void solve()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> s[i];

	for (int i = 0; i < N; ++i)
		h[i] = M;

	for (int j = M-1; j >= 0; --j)
	{
		for (int i = 0; i < N; ++i)
			if (s[i][j] == '*')
				h[i] = j;

		vector<ii> sk;
		for (int i = 0; i <= N; ++i)
		{
			int x, prv = i;
			if (i == N) x = 0;
			else x = h[i] - j;

			for (; !sk.empty() && sk.back().f1 >= x; sk.pop_back())
			{
				pfx[i - sk.back().s2][1 + max(x, sk.size() >= 2 ? sk[(int)sk.size() - 2].f1 : 0)]++;
				pfx[i - sk.back().s2][1 + sk.back().f1]--;
				// for (int k = sk.back().f1; k > max(x, sk.size() >= 2 ? sk[(int)sk.size() - 2].f1 : 0); --k)
				// 	pfx[i - sk.back().s2][k]++;
				prv = sk.back().s2;
			}

			sk.pb({x, prv});
		}

	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 2; j <= M; ++j)
			pfx[i][j] += pfx[i][j-1];
	}

	for (int j = 1; j <= M; ++j)
	{
		int sum = 0, ctr = 0;
		for (int i = N; i >= 1; --i)
		{
			ctr += pfx[i][j];
			sum += ctr;
			pfx[i][j] = sum;
		}
	}

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			cout << pfx[i][j] << " \n"[j == M];
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
