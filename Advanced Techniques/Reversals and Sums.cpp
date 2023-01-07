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

mt19937 RNG(69);

struct Item
{
	int prior, ctr, value;
	ll sum = 0;
	bool rev;

	Item *l, *r;
	Item() {}
	Item(int val) : prior(RNG()), ctr(1), value(val), rev(false), l(nullptr), r(nullptr) {}
};

inline int ctr(Item* it)
{
	return it ? it -> ctr : 0;
}

inline void update_ctr(Item* it)
{
	if (it)
		it -> ctr = ctr(it -> l) + ctr(it -> r) + 1;
}

inline ll sum(Item* it)
{
	return it ? it -> sum : 0;
}

inline void update_sum(Item* it)
{
	if (it)
		it -> sum = sum(it -> l) + sum(it -> r) + it -> value;
}

inline void propagate(Item* it)
{
	if (it && it -> rev)
	{
		swap(it -> l, it -> r);
		if (it -> l) it -> l -> rev ^= true;
		if (it -> r) it -> r -> rev ^= true;
		it -> rev = false;
	}
}

inline void merge(Item* &t, Item* l, Item* r)
{
	propagate(l); propagate(r);
	if (!l || !r)
		t = l ? l : r;
	else if (l -> prior > r -> prior)
		merge(l -> r, l -> r, r), t = l;
	else merge(r -> l, l, r -> l), t = r;
	update_ctr(t);
	update_sum(t);
}

// split t into l and r
void split(Item* t, Item* &l, Item* &r, int key, int pos = 0)
{
	propagate(t);
	if (!t)
		return void (l = r = nullptr);
	int cur_pos = pos + ctr(t -> l);
	if (key <= cur_pos)
		split(t -> l, l, t -> l, key, pos), r = t;
	else split(t -> r, t -> r, r, key, pos + ctr(t -> l) + 1), l = t;		
	update_ctr(t);
	update_sum(t);
}

void solve()
{
	int n, m; cin >> n >> m;

	Item* treap = nullptr;
	for (int i = 1; i <= n; ++i)
	{
		int x; cin >> x;
		merge(treap, treap, new Item(x));
	}

	while (m--)
	{
		int ty, l, r; cin >> ty >> l >> r;

		if (ty == 1)
		{
			Item *A, *B, *C;
			split(treap, A, B, l-1);
			split(B, B, C, r-l+1);
			B -> rev = true;
			merge(treap, A, B);
			merge(treap, treap, C);
		}
		else
		{
			Item *A, *B, *C;
			split(treap, A, B, l-1);
			split(B, B, C, r-l+1);
			cout << B -> sum << '\n';
			merge(treap, A, B);
			merge(treap, treap, C);
		}
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
