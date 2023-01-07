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

int len;
char s[MAX];

bool vst[MAX][MAX];
Mint<> dp[MAX][MAX];

Mint<> fact[MAX], inv[MAX];
inline Mint<> choose(int n, int k)
{
	return fact[n] * inv[n-k] * inv[k];
}

Mint<> rc(int l, int r)
{
	if (l == r)
		return 0;
	if (l > r)
		return 1;

	if (vst[l][r])
		return dp[l][r];
	vst[l][r] = true;

	dp[l][r] = 0;
	for (int i = l; i < r; ++i)
	{
		if (s[i] == s[r])
		{
			if ((i-l) % 2 == 0)
			{
				dp[l][r] += choose((r-l+1)/2, (i-l)/2) * rc(l, i-1) * rc(i+1, r-1);
			}
		}
	}
	return dp[l][r];
}

void solve()
{
	fact[0] = 1;
	for (int i = 1; i < MAX; ++i)
		fact[i] = i * fact[i-1];
	inv[MAX-1] = inverse(fact[MAX-1]);
	for (int i = MAX-2; i >= 0; --i)
		inv[i] = (i+1) * inv[i+1];

	cin >> s;
	len = (int)strlen(s);

	if (len & 1) cout << 0 << '\n';
	else cout << rc(0, len-1) << '\n';
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
