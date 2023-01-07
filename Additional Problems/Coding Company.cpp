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

const int MAXN = 107;
const int MAXX = 5069;

int N, X, ar[MAXN];
Mint<> dp[MAXN][MAXN][MAXX];

void solve()
{	
	cin >> N >> X;
	for (int i = 1; i <= N; ++i)
		cin >> ar[i];
	sort(ar+1, ar+N+1);

	ar[0] = ar[1];
	dp[0][0][0] = 1;
	for (int i = 1; i <= N+1; ++i)
	{
		for (int j = i-1; j >= 0; --j) // number of active teams
		{
			for (int k = X; k >= 0; --k) 
			{
				int nk = k + j * (ar[i] - ar[i-1]);

				// j ways to insert `i` in one of the team
				// 1 way to insert `i` in a new team and directly mark that team as completed
				dp[i][j][nk] += (j+1) * dp[i-1][j][k];
				
				// start `i` as a new team
				if (j+1 < N) dp[i][j+1][nk] += dp[i-1][j][k];
				
				// insert `i` in one of the team and mark that team as completed
				// i.e. reduce the number of active team by 1
				if (j) dp[i][j-1][nk] += j * dp[i-1][j][k];
			}
		}
	}

	Mint<> res = 0;
	for (int k = 0; k <= X; ++k)
		res += dp[N][0][k];
	cout << res << '\n';
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
