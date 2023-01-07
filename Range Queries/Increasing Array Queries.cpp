#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

#define ll long long
#define pb push_back
#define ii pair<int, int>
#define f1 first
#define s2 second

const int MAX = 2e5 + 69;
const int inf = 1e9 + 69;

int n;
int ar[MAX];
ll pfx[MAX];
ll st[4 * MAX], lazy[4 * MAX];

inline void propagate(int node, int l, int r)
{
	if (lazy[node])
	{
		st[node] = (r - l + 1) * lazy[node];
		if (l < r)
			lazy[node << 1] = lazy[node << 1 | 1] = lazy[node];
		lazy[node] = 0;
	}
}

inline void modify(int p, int q, ll val, int node = 1, int l = 1, int r = n)
{
	propagate(node, l, r);
	if (l > q || r < p)
		return;
	if (p <= l && r <= q)
	{
		st[node] = (r - l + 1) * val;
		if (l < r)
			lazy[node << 1] = lazy[node << 1 | 1] = val;
		return;
	}

	int mid = (l + r) >> 1;
	modify(p, q, val, node << 1, l, mid);
	modify(p, q, val, node << 1 | 1, mid+1, r);
	st[node] = st[node << 1] + st[node << 1 | 1];
}

inline ll sum(int p, int q, int node = 1, int l = 1, int r = n)
{
	propagate(node, l, r);
	if (l > q || r < p)
		return 0;
	if (p <= l && r <= q)
		return st[node];

	int mid = (l + r) >> 1;
	return sum(p, q, node << 1, l, mid) + sum(p, q, node << 1 | 1, mid+1, r);
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int q;
	cin >> n >> q;

	for (int i = 1; i <= n; ++i)
	{
		cin >> ar[i];
		pfx[i] = ar[i] + pfx[i-1];
	}

	vector<array<int, 3>> query(q);
	for (int i = 0; i < q; ++i)
	{
		cin >> query[i][0] >> query[i][1];
		query[i][2] = i;
	}
	
	sort(query.begin(), query.end(), [](const auto &x, const auto &y){
		return x[0] > y[0];
	});

	vector<ll> res(q);
	vector<ii> sk;
	sk.pb({inf, n+1});
	
	int cur_l = n+1;
	for (auto [l, r, id] : query)
	{
		while (cur_l > l)
		{
			cur_l--;
			while (sk.back().f1 < ar[cur_l])
				sk.pop_back();
			modify(cur_l, sk.back().s2 - 1, ar[cur_l]);
			sk.pb({ar[cur_l], cur_l});
		}

		res[id] = sum(l, r) - (pfx[r] - pfx[l-1]);
	}

	for (int i = 0; i < q; ++i)
		cout << res[i] << '\n';

	return 0;
}