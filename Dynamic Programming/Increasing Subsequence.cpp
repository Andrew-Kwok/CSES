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

int n;
int ar[N];
int segtree[3*N] = {};

void update(int node, int l, int r, int x, int val)
{
	if (l > r || r < x || l > x)
		return;
	if (l == r && l == x)
	{
		segtree[node] = val;
		return;
	}

	int mid = (l + r) / 2;
	update(2*node, l, mid, x, val);
	update(2*node+1, mid+1, r, x, val);
	segtree[node] = max(segtree[2*node], segtree[2*node + 1]);
}

int rmq(int node, int l, int r, int p, int q)
{
	if (l > r || r < p || l > q)
		return 0;

	if (p <= l && r <= q)
		return segtree[node];

	int mid = (l + r) / 2;
	return max(rmq(2*node, l, mid, p, q), rmq(2*node+1, mid+1, r, p, q));
}

void compress()
{
	map<int, int> memo;
	for (int i = 0; i < n; ++i)
		memo[ar[i]] = 1;

	int ctr = 1;
	for (auto &x : memo)
		x.s2 = ctr++;

	for (int i = 0; i < n; ++i)
		ar[i] = memo[ar[i]];
}

int main()
{
	fastio;

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> ar[i];
	compress();

	for (int i = 0; i < n; ++i)
	{
		int val = 1 + rmq(1, 1, n, 1, ar[i]-1);
		update(1, 1, n, ar[i], val);
	}
	cout << rmq(1, 1, n, 1, n) << '\n';

	return 0;
}
