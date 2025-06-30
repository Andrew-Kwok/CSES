#include <bits/stdc++.h>
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

const int MAX = 1 << 18;

Mint<> pwr[MAX], inv[MAX];

int N;
char s[MAX];
Mint<> h[MAX], h_inv[MAX];

bool palindrome(int l, int r)
{
	return (h[r] - h[l]) * inv[l] == (h[N-l-1] - h[N-r-1]) * inv[N-r-1];
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	pwr[0] = 1;
	for (int i = 1; i < MAX; ++i)
		pwr[i] = pwr[i-1] * prime;

	inv[MAX-1] = inverse(pwr[MAX-1]);
	for (int i = MAX-2; i >= 0; --i)
		inv[i] = prime * inv[i+1];

	cin >> s;
	N = strlen(s);

	for (int i = 0; i < N; ++i)
	{
		h[i+1] = h[i] + s[i] * pwr[i];
		h_inv[i+1] = h_inv[i] + s[N-i-1] * pwr[i];
	}

	return 0;
}