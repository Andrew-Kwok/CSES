#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
#define ll long long
#define pb push_back
#define ii pair<int, int>
#define f1 first
#define s2 second
 
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
 
const int MAX = 20;
 
int n, m;
vector<int> adj[MAX];
bool vst[MAX][1 << MAX];
Mint<> ways[MAX][1 << MAX];
 
Mint<> dfs(int node, int mask)
{
	if (__builtin_popcount(mask) == n)
		return 1;
	if (node == n-1)
		return 0;
 
	if (vst[node][mask])
		return ways[node][mask];
	vst[node][mask] = true;
 
	for (int to : adj[node])
		if (~mask >> to & 1)
			ways[node][mask] += dfs(to, mask | (1 << to));
	return ways[node][mask];
}
 
int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int u, v; cin >> u >> v;
		u--; v--;
 
		adj[u].pb(v);
	}
 
	cout << dfs(0, 1) << '\n';
	return 0;
}
