#include <iostream>
#include <vector>
#include <set>
#include <cstring>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

#define pb push_back

constexpr int prime = 991;
// constexpr int64_t modhash = (1ll << 61) - 1;
constexpr int mod = 1e9 + 7;
constexpr int modhash = 1e9 + 9;

template<int MOD = 1000000007>
struct Mint
{
    int val;

    Mint() : val(0) {}
    Mint(int64_t _val) : val((int)(_val % MOD)) { if (val < 0) val += MOD; }

    Mint& operator+= (const Mint &rhs) { val += rhs.val; if (val >= MOD) val -= MOD; return *this; }
    Mint& operator-= (const Mint &rhs) { val -= rhs.val; if (val < 0) val += MOD; return *this; }
    Mint& operator*= (const Mint &rhs) { val = (int)(1ll * val * rhs.val % MOD); return *this; }

    friend Mint fpow(Mint x, int64_t y)
    {
        Mint res = 1;
        for (; y > 0; y >>= 1, x *= x)
        {
            if (y & 1)
                res *= x;
        }
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

constexpr int MAX = 5069;

Mint<modhash> pwr[MAX], inv[MAX], pfx[MAX];
int k, len;
char s[MAX], p[MAX];

int ind[MAX];
Mint<mod> ans[MAX];
vector<int> adj[MAX];

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	pwr[0] = 1;
	for (int i = 1; i < MAX; ++i)
		pwr[i] = prime * pwr[i-1];
	inv[MAX-1] = inverse(pwr[MAX-1]);
	for (int i = MAX-2; i >= 0; --i)
		inv[i] = inv[i+1] * prime;

	cin >> s;
		
	len = (int)strlen(s);
	pfx[0] = s[0];
	for (int i = 1; i < len; ++i)
		pfx[i] = pfx[i-1] + s[i] * pwr[i];

	const auto get = [&](int l, int r) -> Mint<modhash>
	{
		return pfx[r] - (l ? pfx[l-1] : 0);
	};

	set<int> st[MAX];
	for (cin >> k; k--;)
	{
		cin >> p;
	
		int sz = (int)strlen(p);
		Mint<modhash> h = 0;
		for (int i = 0; i < sz; ++i)
			h += p[i] * pwr[i];
		st[sz].insert(h.val);
	}


	for (int i = 1; i <= len; ++i)
	{
		for (int j = 0; j+i <= len; ++j)
		{
			if (st[i].count((get(j, j+i-1) * inv[j]).val))
				adj[j].pb(i+j);
		}
	}

	ans[0] = 1;
	for (int i = 0; i < len; ++i)
	{
		for (int to : adj[i])
			ans[to] += ans[i];
	}
	cout << ans[len] << '\n';
	return 0;
}