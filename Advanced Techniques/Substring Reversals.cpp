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
	int prior, ctr;
	char value;
	bool rev;
 
	Item *l, *r;
	Item() {}
	Item(char val) : prior(RNG()), ctr(1), value(val), rev(false), l(nullptr), r(nullptr) {}
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
		split(t -> l, l, t -> l, key, pos), r = t;
	else split(t -> r, t -> r, r, key, pos + ctr(t -> l) + 1), l = t;		
	update_ctr(t);
}
 
void output(Item* t)
{
	propagate(t);
	if (!t)
		return;
	output(t -> l);
	cout << t -> value;
	output(t -> r);
}
 
void solve()
{
	int n, m; cin >> n >> m;
	string s; cin >> s;
 
	Item* treap = nullptr;
	for (char c : s)
		merge(treap, treap, new Item(c));
 
	while (m--)
	{
		int p, q; cin >> p >> q;
		Item *A, *B, *C;
		split(treap, A, B, p-1);
		split(B, B, C, q-p+1);
		B -> rev = true;
		merge(treap, A, B);
		merge(treap, treap, C);
	}
	output(treap);
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
