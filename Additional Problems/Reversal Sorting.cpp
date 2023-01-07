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

mt19937 RNG(69);

struct Item
{
	bool rev;
	int prior, ctr, value;
	Item *par, *l, *r;

	Item() {}
	Item(int val) : rev(false), prior(RNG()), ctr(1), value(val), par(nullptr), l(nullptr), r(nullptr) {}
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
	
	if (t -> l) t -> l -> par = t;
	if (t -> r) t -> r -> par = t;
	update_ctr(t);
}

// split t into l and r
void split(Item* t, Item* &l, Item* &r, int key, int pos = 0)
{
	propagate(t);
	if (!t)
		return void (l = r = nullptr);
	int cur_pos = pos + ctr(t -> l);
	if (key <= cur_pos)
	{
		split(t -> l, l, t -> l, key, pos), r = t;
		if (r -> l) r -> l -> par = r;
		if (r -> r) r -> r -> par = r;
	}
	else 
	{
		split(t -> r, t -> r, r, key, pos + ctr(t -> l) + 1), l = t;		
		if (l -> l) l -> l -> par = l;
		if (l -> r) l -> r -> par = l;
	}
	update_ctr(t);
}

Item *it[MAX];
int order_of(int x)
{
	vector<Item*> v;
	for (Item* t = it[x]; t; t = t -> par)
		v.pb(t);
	reverse(v.begin(), v.end());

	for (Item* t : v)
	{
		propagate(t);
		update_ctr(t);
	}
	
	int res = ctr(it[x] -> l);
	for (Item* t = it[x]; t; t = t -> par)
	{
		if (t -> par && t == t -> par -> r)
			res += ctr(t -> par -> l) + 1;
	}
	return res;
}

void solve()
{
	int n; cin >> n;

	Item* treap = nullptr;
	for (int i = 1; i <= n; ++i)
	{
		int x; cin >> x;

		it[x] = new Item(x);
		merge(treap, treap, it[x]);
	}


	vector<ii> res;
	for (int i = n; i >= 1; --i)
	{
		int id = order_of(i) + 1;

		if (i == id) continue;
		else
		{
			res.pb({id, i});

			Item *A, *B, *C;
			split(treap, A, B, id-1);
			split(B, B, C, i-id+1);
			B -> rev = true;
			merge(treap, A, B);
			merge(treap, treap, C);

			// remove the last element
			// split(treap, treap, A, i-1);
		}
	}

	cout << res.size() << '\n';
	for (auto &[l, r] : res)
		cout << l << " " << r << '\n';
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
