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
const int MAX = 2e5 + 69;
const int inf = 1e9 + 69;

int N, Q;
int ar[MAX];

ll pfx[31][MAX]; // pfx[x]: prefix sum of numbers < 2^x
array<int, 30> st[2 * MAX]; // st[x]: rmq of elements [2^x, 2^{x+1})

inline array<int, 30> merge(const array<int, 30> &lhs, const array<int, 30> &rhs)
{
	array<int, 30> res;
	for (int i = 0; i < 30; ++i)
		res[i] = min(lhs[i], rhs[i]);
	return res;
}

inline array<int, 30> query(int l, int r)
{
	array<int, 30> res; fill(res.begin(), res.end(), inf);
	for (l += N-1, r += N; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1) res = merge(res, st[l++]);
		if (r & 1) res = merge(res, st[--r]);
	}
	return res;
}

void solve()
{
	cin >> N >> Q;
	for (int i = 1; i <= N; ++i)
		cin >> ar[i];

	for (int x = 0; x <= 30; ++x)
	{
		for (int i = 1; i <= N; ++i)
		{
			if (ar[i] < (1 << x))
				pfx[x][i] = ar[i];
			pfx[x][i] += pfx[x][i-1];
		}
	}

	for (int x = 0; x < 30; ++x)
	{
		for (int i = 0; i < N; ++i)
		{
			if ((1 << x) <= ar[i+1] && ar[i+1] <= (1 << (x+1)))
				st[i+N][x] = ar[i+1];
			else st[i+N][x] = inf;
		}
	}

	for (int i = N-1; i > 0; --i)
		st[i] = merge(st[i << 1], st[i << 1 | 1]);


	while (Q--)
	{
		int l, r; cin >> l >> r;

		ll res = pfx[30][r] - pfx[30][l-1] + 1;
		array<int, 30> mn = query(l, r);
		for (int i = 0; i < 30; ++i)
		{
			ll val = pfx[i][r] - pfx[i][l-1];
			if (val < (1 << (i+1)) && mn[i] > val + 1)
			{
				res = val + 1;
				break;
			}
		}
		cout << res << '\n';
	}
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
