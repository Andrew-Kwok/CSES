#include <iostream>
using namespace std;

#define ll long long

struct Node
{
	ll val;
	Node *lt, *rt;

	Node() : val(0), lt(nullptr), rt(nullptr) {}
	Node(ll _val) : val(_val), lt(nullptr), rt(nullptr) {}
	Node(ll _val, Node *_lt, Node *_rt) : val(_val), lt(_lt), rt(_rt) {}
	Node(Node* _node) : val(_node -> val), lt(_node -> lt), rt(_node -> rt) {}
};

const int MAX = 2e5 + 69;

int n, sz = 1;
int ar[MAX];
Node* root[MAX];

inline void build(Node* node, int l = 1, int r = n)
{
	if (l == r)
	{
		node -> val = ar[l];
		return;
	}

	int mid = (l + r) >> 1;
	node -> lt = new Node(); build(node -> lt, l, mid);
	node -> rt = new Node(); build(node -> rt, mid+1, r);
	node -> val = node -> lt -> val + node -> rt -> val;
}

inline void update(int p, int val, Node *node, int l = 1, int r = n)
{
	if (l == r)
	{
		node -> val = val;
		return;
	}

	int mid = (l + r) >> 1;
	if (p <= mid)
	{
		node -> lt = new Node(node -> lt);
		update(p, val, node -> lt, l, mid);
	}
	else
	{
		node -> rt = new Node(node -> rt);
		update(p, val, node -> rt, mid+1, r);
	}
	node -> val = node -> lt -> val + node -> rt -> val;
}

inline ll sum(int p, int q, Node *node, int l = 1, int r = n)
{
	if (l > q || r < p)
		return 0;
	if (p <= l && r <= q)
		return node -> val;

	int mid = (l + r) >> 1;
	return sum(p, q, node -> lt, l, mid) + sum(p, q, node -> rt, mid+1, r);
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> ar[i];

	root[1] = new Node();
	build(root[1]);

	while (q--)
	{
		int ty, k;
		cin >> ty >> k;

		if (ty == 1)
		{
			int p, val;
			cin >> p >> val;
			update(p, val, root[k]);
		}
		else if (ty == 2)
		{
			int a, b;
			cin >> a >> b;
			cout << sum(a, b, root[k]) << '\n';
		}
		else
		{
			root[++sz] = new Node(root[k]);
		}
	}

	return 0;
}