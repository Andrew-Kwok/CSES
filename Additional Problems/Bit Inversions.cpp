#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 2e5 + 7;

struct Segtree
{
	struct Node
	{
		int pfx, sfx, len, mx;
		Node() : pfx(0), sfx(0), len(0), mx(0) {}
		Node(int PFX, int SFX, int LEN, int MX) : pfx(PFX), sfx(SFX), len(LEN), mx(MX) {}
	};

	int n;
	bool ar[MAX];
	Node st[4 * MAX];

	Segtree(int N, char S[]) : n(N)
	{
		for (int i = 0; i < N; ++i)
			ar[i+1] = (S[i] - '0');
		build(1, 1, N);
	}

	inline Node combine(Node lt, Node rt)
	{
		Node res;
		res.len = lt.len + rt.len;
		res.mx = max(lt.mx, rt.mx);
		if (lt.pfx == lt.len && rt.pfx == rt.len)
			res.pfx = res.sfx = lt.len + rt.len;
		else if (lt.pfx == lt.len)
			res.pfx = lt.len + rt.pfx, res.sfx = rt.sfx;
		else if (rt.pfx == rt.len)
			res.pfx = lt.pfx, res.sfx = lt.sfx + rt.len;
		else res.pfx = lt.pfx, res.sfx = rt.sfx, res.mx = max(res.mx, lt.sfx + rt.pfx);

		res.mx = max(res.mx, max(res.pfx, res.sfx));
		return res;
	}

	inline void build(int node, int l, int r)
	{
		if (l == r)
		{
			st[node] = Node(ar[l], ar[l], 1, ar[l]);
			return;
		}

		int mid = (l + r) >> 1;
		build(node << 1, l, mid);
		build(node << 1 | 1, mid+1, r);
		st[node] = combine(st[node << 1], st[node << 1 | 1]);
	}

	inline void update(int node, int l, int r, int p)
	{
		if (l > p || r < p)
			return;
		if (l == r)
		{
			st[node] = Node(ar[l], ar[l], 1, ar[l]);
			return;
		}
		int mid = (l + r) >> 1;
		update(node << 1, l, mid, p);
		update(node << 1 | 1, mid+1, r, p);
		st[node] = combine(st[node << 1], st[node << 1 | 1]);
	}

	inline void inverse(int p)
	{
		ar[p] ^= 1;
		update(1, 1, n, p);
	}

	inline int get()
	{
		return st[1].mx;
	}

};

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	char s[MAX];
	
	cin >> s;
	cin >> q;

	n = (int)strlen(s);
	Segtree st0(n, s);

	for (int i = 0; i < n; ++i)
		s[i] = (s[i] == '1' ? '0' : '1');
	Segtree st1(n, s);

	while (q--)
	{
		int p; cin >> p;
		st0.inverse(p); st1.inverse(p);
		cout << max(st0.get(), st1.get()) << '\n';
	}

	return 0;
}