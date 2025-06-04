#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node {
	ll sum = 0, mx = 0, pfx = 0, sfx = 0;
	Node() : Node(0) {}
	Node(int x) : sum(x) {
		mx = pfx = sfx = max(0, x);
	}

	friend Node merge(const Node& l, const Node& r) 
	{
		Node Z;
		Z.sum = l.sum + r.sum;
		Z.pfx = max(l.pfx, l.sum + r.pfx);
		Z.sfx = max(r.sfx, r.sum + l.sfx);
		Z.mx = max(max(l.mx, r.mx), l.sfx + r.pfx);
		return Z;
	}
};



int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	int N, Q;
	cin >> N >> Q;

	vector<Node> st(2*N);
	for (int i = 0; i < N; ++i) {
		int x; cin >> x;
		st[i+N] = Node(x);
	}

	for (int i = N-1; i >= 0; --i)
		st[i] = merge(st[i << 1], st[i << 1 | 1]);
	const auto query = [&](int l, int r) -> ll
	{
		Node Zl, Zr;
		for (l += N, r += N; l < r; l >>= 1, r >>= 1)
		{
			if (l & 1) Zl = merge(Zl, st[l++]);
			if (r & 1) Zr = merge(st[--r], Zr);
		}
		return merge(Zl, Zr).mx;
	};

	while (Q--)
	{
		int l, r; cin >> l >> r;
		cout << query(l-1, r) << '\n';
	}


	return 0;
}