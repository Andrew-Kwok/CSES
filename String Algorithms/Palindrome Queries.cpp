#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int64_t prime = 991;
constexpr int64_t mod = (1ll << 61) - 1;

template<int64_t MOD = mod>
struct Mint
{
	int64_t val;

	Mint() : val(0) {}
	Mint(int64_t _val) : val(_val % MOD) { if (val < 0) val += MOD; }

	Mint& operator+= (const Mint &rhs) { val += rhs.val; if (val >= MOD) val -= MOD; return *this; }
	Mint& operator-= (const Mint &rhs) { val -= rhs.val; if (val < 0) val += MOD; return *this; }
	Mint& operator*= (const Mint &rhs) {
		uint64_t l1 = (uint32_t) val, h1 = val >> 32, l2 = (uint32_t) rhs.val, h2 = rhs.val >> 32;
		uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
		val = (l & MOD) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
		val = (val & MOD) + (val >> 61);
		val = (val & MOD) + (val >> 61);
		val--; return *this;
	}

	friend Mint fpow(Mint x, uint64_t y)
	{
		Mint res = 1;
		for (; y > 0; x *= x, y >>= 1)
			if (y & 1)
				res *= x;
		return res;
	}
	friend Mint inverse(Mint x) { return fpow(x, MOD-2); }
	Mint& operator/= (const Mint &rhs) { return *this *= inverse(rhs); }

	friend Mint operator+ (Mint a, const Mint &b) { return a += b; }
	friend Mint operator- (Mint a, const Mint &b) { return a -= b; }
	friend Mint operator- (Mint a) { return 0 - a; }
	friend Mint operator* (Mint a, const Mint &b) { return a *= b; }
	friend Mint operator/ (Mint a, const Mint &b) { return a /= b; }
	friend ostream& operator<< (ostream &os, const Mint &a) { return os << a.val; }
	friend bool operator== (const Mint &a, const Mint &b) { return a.val == b.val; }
	friend bool operator!= (const Mint &a, const Mint &b) { return a.val != b.val; }
};

const int MAX = 2e5 + 69;

Mint<> pwr[MAX], inv[MAX];

struct Segtree
{
	int n;
	vector<Mint<>> st;

	Segtree(string &s) : n((int)s.size())
	{
		st.resize(2*n);
		for (int i = 0; i < n; ++i)
			st[i + n] = s[i] * pwr[i];

		for (int i = n-1; i > 0; --i)
			st[i] = st[i << 1] + st[i << 1 | 1];
	}

	void modify(int p, char c)
	{
		st[p + n] = c * pwr[p];
		for (p += n; p > 1; p >>= 1)
			st[p >> 1] = st[p] + st[p ^ 1];
	}

	Mint<> query(int l, int r)
	{
		Mint<> res = 0, tmp = inv[l]; 
		for (l += n, r += n+1; l < r; l >>= 1, r >>= 1)
		{
			if (l & 1) res += st[l++];
			if (r & 1) res += st[--r];
		}
		return res * tmp;
	}
};

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	pwr[0] = 1;
	for (int i = 1; i < MAX; ++i)
		pwr[i] = pwr[i-1] * prime;

	inv[MAX-1] = inverse(pwr[MAX-1]);
	for (int i = MAX-2; i >= 0; --i)
		inv[i] = prime * inv[i+1];

	int n, q;
	cin >> n >> q;

	string s;
	cin >> s;

	Segtree st(s);
	reverse(s.begin(), s.end());
	Segtree st_rev(s);

	while (q--)
	{
		int ty; cin >> ty;
		if (ty == 1)
		{
			int p; char c;
			cin >> p >> c; p--;
			st.modify(p, c);
			st_rev.modify(n-p-1, c);
		}
		else
		{
			int a, b;
			cin >> a >> b; a--; b--;

			string ans[2] = {"NO", "YES"};
			cout << ans[st.query(a, b) == st_rev.query(n-b-1, n-a-1)] << '\n';
		}
	}

	return 0;
}