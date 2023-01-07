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
const int MAX = 1e5 + 69;
const ll inf = 1e18 + 69;
 
template<int KEY1, int KEY2>
struct Hash
{
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

    Mint<KEY1> val1;
    Mint<KEY2> val2;

    Hash() : val1(0), val2(0) {}
    Hash(int64_t _val) : val1(_val), val2(_val) {}

    Hash& operator+= (const Hash &rhs) { val1 += rhs.val1; val2 += rhs.val2; return *this; }
    Hash& operator-= (const Hash &rhs) { val1 -= rhs.val1; val2 -= rhs.val2; return *this; }
    Hash& operator*= (const Hash &rhs) { val1 *= rhs.val1; val2 *= rhs.val2; return *this; }
    Hash& operator/= (const Hash &rhs) { val1 /= rhs.val1; val2 /= rhs.val2; return *this; }

    friend Hash operator+ (Hash a, const Hash &b) { return a += b; }
    friend Hash operator- (Hash a, const Hash &b) { return a -= b; }
    friend Hash operator- (Hash a) { return 0 - a; }
    friend Hash operator* (Hash a, const Hash &b) { return a *= b; }
    friend Hash operator/ (Hash a, const Hash &b) { return a /= b; }
    friend ostream& operator<< (ostream &os, const Hash &a) { return os << a.val1 << " " << a.val2; }
    friend bool operator== (const Hash &a, const Hash &b) { return a.val1 == b.val1 && a.val2 == b.val2; }
    friend bool operator!= (const Hash &a, const Hash &b) { return a.val1 != b.val1 || a.val2 != b.val2; }
};

const int KEY1 = 420691273;
const int KEY2 = 1e9 + 7;
 
int N, M;
vector<ii> adj[2][MAX];
 
ll dist[2][MAX];
Hash<KEY1, KEY2> ways[2][MAX];
 
void dijkstra(int i, int s)
{
	fill(dist[i], dist[i] + MAX, inf);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
 
	dist[i][s] = 0; ways[i][s] = 1;	
	pq.push({0, s}); 
	while (!pq.empty())
	{
		auto [cost, node] = pq.top(); pq.pop();
		if (cost > dist[i][node])
			continue;
 
		for (auto &[to, w] : adj[i][node])
		{
			if (dist[i][to] > cost + w)
			{
				dist[i][to] = cost + w;
				ways[i][to] = ways[i][node];
				pq.push({dist[i][to], to});
			}
			else if (dist[i][to] == cost + w)
				ways[i][to] += ways[i][node];

		}
	}
}
 
void solve()
{
	cin >> N >> M;
	while (M--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[0][u].pb({v, w});
		adj[1][v].pb({u, w});
	}
 
	dijkstra(0, 1);
	dijkstra(1, N);
 
	vector<int> res;
	for (int i = 1; i <= N; ++i)
	{
		if (ways[0][i] * ways[1][i] == ways[0][N] && dist[0][i] + dist[1][i] == dist[0][N])
			res.pb(i);
	}
	
	cout << res.size() << '\n';
	for (int x : res)
		cout << x << " ";
	cout << '\n';
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