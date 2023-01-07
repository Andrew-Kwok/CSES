#include <iostream>
#include <vector>
using namespace std;

#define pb push_back
#define f1 first
#define s2 second

using ll = long long;
using ii = pair<int, int>;

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

Mint<> fq[1024][1024] = {};
vector<pair<int, Mint<>>> trans[1024];
Mint<> ans[2][1024] = {};

int main()
{
	int n, m;
	cin >> n >> m;

	int lim = 1;
	for (int i = 0; i < n; ++i)
		lim *= 3;

	for (int prv = 0; prv < (1 << n); ++prv)
	{
		for (int mask = 0; mask < lim; ++mask)
		{
			int nxt = 0;
			bool valid = true;
			for (int i = 0, cur = mask; i < n && valid; ++i, cur /= 3)
			{
				int x = cur % 3;
				if ((~prv >> i & 1) && x != 1)
				{	
					valid = false;
					continue;
				}

				if (x == 0) //put nothing
					continue;
				else if (x == 1) //put 1x2
				{
					if (prv >> i & 1)
						valid = false;
					else nxt |= (1 << i);
				}
				else //put 2x1
				{
					if (i == 0 || nxt >> (i-1) & 1)
						valid = false;
					else nxt |= (1 << i), nxt |= (1 << (i-1));
				}
			}

			fq[prv][nxt] += valid;
		}
	}

	for (int i = 0; i < (1 << n); ++i)
		for (int j = 0; j < (1 << n); ++j)
			if (fq[i][j] != 0)
				trans[i].pb({j, fq[i][j]});			

	ans[0][(1 << n) - 1] = 1;
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 0; j < (1 << n); ++j)
			ans[i&1][j] = 0;
		for (int j = 0; j < (1 << n); ++j)
		{
			for (auto [p, q] : trans[j])
			{
				ans[i&1][p] += q * ans[~i & 1][j];
			}
		}
	}
	cout << ans[m&1][(1 << n) - 1] << '\n';

	return 0;
}