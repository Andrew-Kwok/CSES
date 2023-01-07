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
const int mod = 1e9 + 7;
const int MAX = 569;

template<int MOD = mod>
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

// https://oeis.org/A201862
// https://mathoverflow.net/questions/54677/how-to-place-k-bishops-on-an-nxn-chessboard
// http://problem64.beda.cz/silo/kotesovec_non_attacking_chess_pieces_2013_6ed.pdf [page 234 - 241]

Mint<> fact[2 * MAX], inv[2 * MAX];

inline Mint<> choose(int n, int k)
{
    return fact[n] * inv[n-k] * inv[k];
}

inline Mint<> fpow(int x, int y)
{
    return fpow(Mint<>(x), y);
}

void solve()
{
	fact[0] = 1;
	for (int i = 1; i < 2 * MAX; ++i)
		fact[i] = i * fact[i-1];
	inv[2*MAX-1] = inverse(fact[2*MAX-1]);
	for (int i = 2*MAX-2; i >= 0; --i)
		inv[i] = (i+1) * inv[i+1]; 

	int n, k;
	cin >> n >> k;

    if (k >= 2*n) cout << 0 << '\n';
    else if (n == 1) cout << 1 << '\n';
    else
    {
        Mint<> res = 0;
        for (int i = max(0, k-n); i <= min(k, n); ++i)
        {
            Mint<> p = 0, q = 0;
            for (int m = 1; m <= n-i; ++m)
                p += fpow(-1, m) * choose(n-i, m) * fpow(m, n/2) * fpow(m+1, (n+1)/2);
            for (int m = 1; m <= n+i-k; ++m)
                q += fpow(-1, m) * choose(n-k+i, m) * fpow(m, (n+1)/2) * fpow(m+1, n/2);
            res += choose(2*n-k, n-k+i) * p * q;
        }
        cout << fpow(-1, k) / fact[2*n-k] * res << '\n';
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
