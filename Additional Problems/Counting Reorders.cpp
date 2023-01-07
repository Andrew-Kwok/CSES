#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second
#define size(x) (int)x.size()

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x) cerr << "[" << #x << "]: " << x << "\n";

#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using pl = pair<ll, ll>;

const ld PI = 4*atan((ld)1);
const int mod = 1e9 + 7;

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

const int MAX = 5069;

int N;
int fq[26] = {};
Mint<> fact[MAX], inv[MAX];
Mint<> dp[2][MAX];

inline Mint<> choose(int n, int k)
{
    if (n < k)
        return 0;
    return fact[n] * inv[k] * inv[n-k];
}

void solve()
{
    fact[0] = 1;
    for (int i = 1; i < MAX; ++i)
        fact[i] = i * fact[i-1];
    inv[MAX-1] = inverse(fact[MAX-1]);
    for (int i = MAX-2; i >= 0; --i)
        inv[i] = (i+1) * inv[i+1];

    string s; cin >> s;
    N = size(s);
	for (int i = 0; i < N; ++i)
		fq[s[i] - 'a']++;

    vector<int> v;
    for (int i = 0; i < 26; ++i) if (fq[i])
        v.pb(fq[i]);
    sort(v.begin(), v.end());

    dp[0][0] = 1;
    for (int i = 0, pfx = 0; i < size(v); ++i)
    {
        for (int j = 0; j <= pfx; ++j) // current different intervals
        {
            for (int k = 1; k <= min(j+1 + (j != 0), v[i]); ++k) // new different intervals
            {
                dp[~i&1][j+k] += dp[i&1][j] * choose(j+1 + (j != 0), k) * choose(v[i] - 1, k-1);
            }
        }
        pfx += v[i];
    }

    for (int i = 0; i <= N; ++i)
        cout << dp[size(v) & 1][i] << " \n"[i == N];

    cout << dp[size(v) & 1][N] << '\n';
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
