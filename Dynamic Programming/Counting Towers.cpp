#include <bits/stdc++.h>
using namespace std;

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using pl = pair<ll, ll>;

const ll mod = 1e9 + 7;
const int MAX = 1e6 + 69;

template<int MOD = 1'000'000'007>
struct Mint
{
	int val;

	Mint(ll _val = 0) : val((int)(_val % MOD)) { if (val < 0) val += MOD; }

	Mint& operator+= (const Mint &rhs) { val += rhs.val; if (val >= MOD) val -= MOD; return *this; }
	Mint& operator-= (const Mint &rhs) { val -= rhs.val; if (val < 0) val += MOD; return *this; }
	Mint& operator*= (const Mint &rhs) { val = (int) ((ll)val * rhs.val % MOD); return *this; }
	
	friend Mint fpow(Mint x, ll y)
	{
		Mint res = 1;
		for (; y > 0; y >>= 1, x *= x)
			res *= (y & 1 ? x : 1);
		return res;
	}
	friend Mint inverse(Mint x) { return fpow(x, MOD - 2); }
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

int main()
{
	fastio;

	Mint<> W1[MAX] = {}, W2[MAX] = {}; //width 1, 2
	Mint<> pfx[MAX]; //prefix sum of W1[i] * W1[i]
	W1[0] = W1[1] = 1;
	for (int i = 2; i < MAX; ++i)
		W1[i] = W1[i-1] * 2;

	pfx[0] = 1;
	for (int i = 1; i < MAX; ++i)
		pfx[i] = 4 * pfx[i-1] - 2;

	W2[0] = W2[1] = 1;
	Mint<> sum = 1;
 	for (int i = 2; i < MAX; ++i)
	{
		// W2[i] = 4 * W2[i-1] - 2 * \sum_[0, i-2] + W2[i-1]
		W2[i] = (5 * W2[i-1] - 2 * sum);
		sum += W2[i-1];

		// for (int j = 1; j <= i; ++j)
		// {
		// 	W2[i] += W2[i-j] * pfx[j-1];	
		// }
	}

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		Mint<> res = W1[n] * W1[n];
		for (int i = 0; i < n; ++i)
			res += W1[i] * W1[i] * W2[n-i];

		cout << res << '\n';
	}

	return 0;
}
