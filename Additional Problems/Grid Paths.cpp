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
const int MAX = 1e6 + 69;

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

Mint<> fact[2 * MAX], inv[2 * MAX];
inline Mint<> choose(int n, int k)
{
	return fact[n] * inv[n-k] * inv[k];
}

void solve()
{
	fact[0] = 1;
	for (int i = 1; i < 2*MAX; ++i)
		fact[i] = i * fact[i-1];
	inv[2*MAX - 1] = inverse(fact[2*MAX - 1]);
	for (int i = 2*MAX-2; i >= 0; --i)
		inv[i] = (i+1) * inv[i+1];

	int n, m;
	cin >> n >> m;

	vector<ii> v(m);
	for (auto &[x, y] : v)
		cin >> x >> y;
	sort(v.begin(), v.end());
	
	v.pb({n, n}); m++;

	Mint<> dp[1069];
	for (int i = 0; i < m; ++i)
	{
		dp[i] = choose(v[i].f1 + v[i].s2 - 2, v[i].f1 - 1);
		for (int j = 0; j < i; ++j)
		{
			if (v[j].f1 <= v[i].f1 && v[j].s2 <= v[i].s2)
				dp[i] -= dp[j] * choose(v[i].f1 - v[j].f1 + v[i].s2 - v[j].s2, v[i].f1 - v[j].f1);
		}
	}
	cout << dp[m-1] << '\n';
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
