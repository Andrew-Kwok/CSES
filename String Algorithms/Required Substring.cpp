#include <iostream>
using namespace std;

template<int MOD>
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

constexpr int MAXN = 1069;
constexpr int MAXM = 169;
constexpr int mod = 1e9 + 7;

int n;
string s;

Mint<mod> dp[MAXN][MAXM]; // dp[i][j]: no of string of length i with no substring s, and has suffix of length j which is prefix of s
int len[MAXM][26]; // new suffix length after adding new character

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> s;

	int m = (int)s.size();
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			string cur = s.substr(0, i);
			cur += (char)(j + 'A');

			len[i][j] = 0;
			for (int k = (int)cur.size(); k > 0; --k)
			{
				if (s.substr(0, k) == cur.substr((int)cur.size() - k, k))
				{
					len[i][j] = k;
					break;
				}
			}
		}
	}

	dp[0][0] = 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			for (int k = 0; k < 26; ++k)
				dp[i+1][len[j][k]] += dp[i][j];

	Mint<mod> ans = fpow(Mint<mod>(26), n);
	for (int i = 0; i < m; ++i)
		ans -= dp[n][i];
	cout << ans << '\n';

	return 0;
}