#include <iostream>
using namespace std;

#define ll long long

template<int MOD = 1'000'000'007>
struct Mint
{
    int val;

    Mint() : val(0) {}
    Mint(ll _val) : val((int)(_val % MOD)) { if (val < 0) val += MOD; }

    Mint& operator+= (const Mint &rhs) { val += rhs.val; if (val >= MOD) val -= MOD; return *this; }
    Mint& operator-= (const Mint &rhs) { val -= rhs.val; if (val < 0) val += MOD; return *this; }
    Mint& operator*= (const Mint &rhs) { val = (int)((ll) val * rhs.val % MOD); return *this; }

    friend Mint fpow(Mint x, ll y)
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

const int MAX = 1e6 + 69;

Mint<> fact[MAX], inv[MAX];
inline Mint<> choose(int n, int k)
{
    if (0 <= k && k <= n)
        return fact[n] * inv[k] * inv[n-k];
    return 0;
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    fact[0] = 1;
    for (int i = 1; i < MAX; ++i)
        fact[i] = i * fact[i-1];

    inv[MAX-1] = inverse(fact[MAX-1]);
    for (int i = MAX-2; i >= 0; --i)
        inv[i] = (i+1) * inv[i+1];

    int n;
    string s;
	cin >> n >> s;
    
    int open = 0, close = 0;
    for (char c : s)
    {
        if (c == '(') open++;
        else close++;

        if (open < close)
        {
            cout << 0 << '\n';
            return 0;
        }
    }

    if ((n & 1) || open > n/2)
    {
        cout << 0 << '\n';
        return 0;
    }

    cout << choose(n - open - close, n/2 - open) - choose(n - open - close, n/2 - open - 1) << '\n';
	return 0;
}