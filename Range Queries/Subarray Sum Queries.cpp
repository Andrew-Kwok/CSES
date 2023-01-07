#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x...) cerr << "[" << #x << "]: " << x << "\n";

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using pl = pair<ll, ll>;

ld const PI = 4*atan((ld)1);
int const MAX = 2e5 + 7;

ll ar[MAX];

ll st[4*MAX]; //maximum subarray
ll sum[4*MAX]; //subarray sum
ll pfx[4*MAX]; //maximum prefix
ll sfx[4*MAX]; //maximum suffix

void build(int node, int l, int r)
{
	if (l == r)
	{
		sum[node] = ar[l];
		pfx[node] = sfx[node] = max(0LL, ar[l]);
		return;
	}


	int mid = (l + r) / 2;
	build(node << 1, l, mid);
	build(node << 1 | 1, mid+1, r);

	sum[node] = sum[node << 1] + sum[node << 1 | 1];
	pfx[node] = max(pfx[node << 1], sum[node << 1] + pfx[node << 1 | 1]);
	sfx[node] = max(sfx[node << 1 | 1], sum[node << 1 | 1] + sfx[node << 1]);

	st[node] = max(st[node << 1], st[node << 1 | 1]);
	st[node] = max(st[node], pfx[node]);
	st[node] = max(st[node], sfx[node]);
	st[node] = max(st[node], sfx[node << 1] + pfx[node << 1 | 1]);
}

void modify(int node, int l, int r, int p, ll val)
{
	if (r < p || l > p)
		return;

	if (l == r && l == p)
	{
		ar[l] = val;
		sum[node] = val;
		pfx[node] = sfx[node] = max(0LL, val);
		return;
	}

	int mid = (l + r) / 2;
	modify(node << 1, l, mid, p, val);
	modify(node << 1 | 1, mid+1, r, p, val);

	sum[node] = sum[node << 1] + sum[node << 1 | 1];
	pfx[node] = max(pfx[node << 1], sum[node << 1] + pfx[node << 1 | 1]);
	sfx[node] = max(sfx[node << 1 | 1], sum[node << 1 | 1] + sfx[node << 1]);

	st[node] = max(st[node << 1], st[node << 1 | 1]);
	st[node] = max(st[node], pfx[node]);
	st[node] = max(st[node], sfx[node]);
	st[node] = max(st[node], sfx[node << 1] + pfx[node << 1 | 1]);
}

int main()
{
	fastio;

	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; ++i)
		cin >> ar[i];

	build(1, 1, n);
	while (q--)
	{
		int p, v;
		cin >> p >> v;

		modify(1, 1, n, p, v);
		cout << st[1] << '\n';
	}

	return 0;
}
