#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll INF = 1e12;

struct Line {
    ll m, c;
    Line(ll _m = -INF, ll _c = -INF) : m(_m), c(_c) {}

    ll operator()(ll x) {
    	if (m <= -INF || c <= -INF)
    		return -INF;
        return m * x + c;
    }
};

struct Node {
    Line line;
    Node *lc = nullptr;
    Node *rc = nullptr;
};

inline void lct_insert_knowingly(Line seg, Node *&node, int l = 0, int r = 1e6) {
    if (node == nullptr)
        node = new Node();

    if (node->line(l) < seg(l))
        swap(node->line, seg);

    if (node->line(r) >= seg(r))
        return;

    if (l == r)
        return;

    int mid = (l + r) >> 1;

    if (node->line(mid) > seg(mid)) {
        lct_insert_knowingly(seg, node->rc, mid + 1, r);
    } else {
        swap(node->line, seg);
        lct_insert_knowingly(seg, node->lc, l, mid);
    }
}

inline void lct_insert(Line seg, int p, int q, Node *&node, int l = 0, int r = 1e6) {
    if (node == nullptr)
        node = new Node();

    if (l > q || r < p)
        return;

    if (p <= l && r <= q)
        return lct_insert_knowingly(seg, node, l, r);

    int mid = (l + r) >> 1;
    lct_insert(seg, p, q, node->lc, l, mid);
    lct_insert(seg, p, q, node->rc, mid + 1, r);
}

ll lct_query(int x, Node *&node, int l = 0, int r = 1e6) {
    if (node == nullptr)
        return -INF;

    if (l == r)
        return node->line(x);

    int mid = (l + r) >> 1;

    if (x <= mid)
        return max(node->line(x), lct_query(x, node->lc, l, mid));

    return max(node->line(x), lct_query(x, node->rc, mid + 1, r));
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	Node* root = nullptr;

	int Q;
	for (cin >> Q; Q--;)
	{
		int ty; cin >> ty;
		if (ty == 1)
		{
			int a, b, l, r; 
			cin >> a >> b >> l >> r;
			lct_insert(Line(a, b), l, r, root);
		}
		else
		{
			int x; cin >> x;
			ll Z = lct_query(x, root);
			if (Z <= -INF) cout << "NO\n";
			else cout << Z << '\n';
		}
	}

	return 0;
}