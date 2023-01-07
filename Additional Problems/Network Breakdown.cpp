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

int ds[MAX];
static int cc;

inline int frep(int x) { return x == ds[x] ? x : ds[x] = frep(ds[x]); }
inline void join(int x, int y)
{
	x = frep(x); y = frep(y);
	if (x == y)
		return;
	cc--; ds[y] = x;
}

void solve()
{
	iota(ds, ds+MAX, 0);

	int n, m, k;
	cin >> n >> m >> k;

	set<ii> st;
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		if (a > b)
			swap(a, b);
		st.insert({a, b});
	}

	vector<ii> sk(k);
	for (auto &[a, b] : sk)
	{
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		st.erase({a, b});
	}

	cc = n;
	for (auto [a, b] : st)
		join(a, b);

	vector<int> ans;
	for (; !sk.empty(); sk.pop_back())
	{
		ans.pb(cc);
		join(sk.back().f1, sk.back().s2);
	}

	for (; !ans.empty(); ans.pop_back())
		cout << ans.back() << " ";
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
