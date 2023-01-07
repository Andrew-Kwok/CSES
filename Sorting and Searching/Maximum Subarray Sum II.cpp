#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x...) cerr << "[" << #x << "]: " << x << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;

ld const PI = 4*atan((ld)1);

int const N = 2e5 + 7;

ll ar[N];
ll sum[N];
ll segtree[3*N];

void cst(int node, int lt, int rt)
{
	if (lt > rt)
		return;
	if (lt == rt)
	{
		segtree[node] = sum[lt];
		return;
	}

	int mid = (lt + rt) / 2;
	cst(2*node, lt, mid);
	cst(2*node+1, mid+1, rt);
	segtree[node] = min(segtree[2*node], segtree[2*node + 1]);
}

ll rmq(int node, int lt, int rt, int p, int q)
{
	if (lt > rt || q < lt || rt < p)
		return 1e18;

	if (p <= lt && rt <= q)
		return segtree[node];

	int mid = (lt + rt) / 2;
	return min(rmq(2*node, lt, mid, p, q), rmq(2*node+1, mid+1, rt, p, q));
}

int main()
{
	fastio;

	int n, a, b;

	ll res = -1e18;

	cin >> n >> a >> b;
	for (int i = 1; i <= n; ++i)
		cin >> ar[i];

	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i-1] + ar[i];
	cst(1, 0, n);

	for (int i = a; i <= n; ++i)
		res = max(res, sum[i] - rmq(1, 0, n, max(0, i-b), i-a));

	cout << res << '\n';
	return 0;
}
