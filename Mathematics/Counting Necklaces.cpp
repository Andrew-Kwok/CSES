#include <bits/stdc++.h>
using namespace std;

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

int n, m;
int phi[MAX];
Mint<> pwr[MAX];

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	iota(phi, phi + MAX, 0);
	for (int i = 2; i < MAX; ++i)
		if (phi[i] == i)
			for (int j = i; j < MAX; j += i)
				phi[j] = phi[j] / i * (i - 1);


	cin >> n >> m;

	pwr[0] = 1;
	for (int i = 1; i < MAX; ++i)
		pwr[i] = pwr[i-1] * m;

	Mint<> res = 0;
	// for (int i = 1; i <= n; ++i)
	// 	res += pwr[__gcd(i, n)];
	for (int d = 1; d <= n; ++d)
	{
		if (n % d == 0)
		{
			res += phi[d] * pwr[n/d];
		}
	}
	cout << res / n << '\n';

	return 0;
}