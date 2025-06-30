#include <bits/stdc++.h>
using namespace std;

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
const int ModA = 998244353;
const int ModC = 1e9 + 7;
using MintA    = Mint<ModA>;
using MintC    = Mint<ModC>;

const int MAX = 1 << 10;

int N;
int in[MAX], out[MAX];
MintC fact[MAX], inv[MAX];

MintC choose(int n, int k)
{
	return fact[n] * inv[k] * inv[n-k];
}

int main()
{
	fact[0] = 1;
	for (int i = 1; i < MAX; ++i)
	{
		fact[i] = i * fact[i-1];
	}
	inv[MAX-1] = 1 / fact[MAX-1];
	for (int i = MAX-2; i >= 0; --i)
	{
		inv[i] = (i+1) * inv[i+1];
	}

	ios :: sync_with_stdio(0);
	cin.tie(0);

	memset(in, -1, sizeof(in));
	memset(out, -1, sizeof(out));

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string s; cin >> s;
		for (int j = 0; j < N; ++j)
		{
			if (s[j] == 'A')
			{
				out[i] = j+N;
				in[j+N] = i;
			}
			else if (s[j] == 'B')
			{
				out[j+N] = i;
				in[i] = j+N;
			}
		}
	}

	int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
	int cp = 0, cq = 0;

	for (int i = 0; i < N; ++i)
	{
		if (out[i] == -1 && in[i] == -1) c1++;
		if (out[i] != -1 && in[i] == -1 && out[out[i]] == -1) c3++;
		if (out[i] == -1) cp++;
	}

	for (int i = N; i < 2*N; ++i)
	{
		if (out[i] == -1 && in[i] == -1) c4++;
		if (out[i] != -1 && in[i] == -1 && out[out[i]] == -1) c2++;
		if (out[i] == -1) cq++;
	}

	MintC Z = 0;
	for (int i = 0; i <= min(c1, c4); ++i)
	{
		for (int j = 0; j <= c2; ++j)
		{
			for (int k = 0; k <= c3; ++k)
			{
				Z += choose(c1, i) * choose(c2, j) * choose(c3, k) * choose(c4, i) * fact[i] * fact[cp-i-j] * fact[cq-i-k] * ((i+j+k) % 2 ? -1 : 1);
			}
		}
	}

	cout << Z << '\n';
	return 0;
}