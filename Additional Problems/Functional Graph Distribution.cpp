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
const int MAX = 5069;

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

// https://oeis.org/A060281
Mint<> fact[MAX], inv[MAX], pwr[MAX];
ll S[MAX][MAX];

inline Mint<> choose(int n, int k)
{
    return fact[n] * inv[n-k] * inv[k];
}

inline Mint<> fpow(int x, int y)
{
    return fpow(Mint<>(x), y);
}

inline Mint<> sterling(int n, int k)
{
	return abs(S[n][k]);
}

void solve()
{
	fact[0] = 1;
	for (int i = 1; i < MAX; ++i)
		fact[i] = i * fact[i-1];
	inv[MAX-1] = inverse(fact[MAX-1]);
	for (int i = MAX-2; i >= 0; --i)
		inv[i] = (i+1) * inv[i+1]; 

	S[1][1] = 1;
	for (int i = 2; i < MAX; ++i)
		for (int j = 1; j <= i; ++j)
			S[i][j] = (S[i-1][j-1] - (i-1) * S[i-1][j]) % mod;

	int n; cin >> n;
	pwr[0] = 1;
	for (int i = 1; i < MAX; ++i)
		pwr[i] = n * pwr[i-1];

	for (int k = 1; k <= n; ++k)
	{
		Mint<> res = 0;
		for (int j = 0; j < n; ++j)
		{
			res += choose(n-1, j) * pwr[n-j-1] * sterling(j+1, k);
		}
		cout << res << '\n';
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
