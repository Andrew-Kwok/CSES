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
const int inf = 1e9 + 69;

int ds[MAX];

inline int frep(int x) { return ds[x] < 0 ? x : ds[x] = frep(ds[x]); }
inline void join(int x, int y)
{
	x = frep(x); y = frep(y);
	if (x == y)
		return;
	ds[x] += ds[y];
	ds[y] = x;
}

bitset<MAX> res[2];
void solve()
{
	memset(ds, -1, sizeof(ds));

	int n, m;
	cin >> n >> m;

	while (m--)
	{
		int u, v; cin >> u >> v;
		join(u, v);
	}

	vector<int> sz;
	for (int i = 1; i <= n; ++i) if (ds[i] < 0)
		sz.pb(-ds[i]);
	sort(sz.begin(), sz.end());

	vector<ii> v;
	for (int x : sz)
	{
		if (!v.empty() && v.back().f1 == x)
			v.back().s2++;
		else v.pb({x, 1});
	}

	res[1][0] = true;
	for (int i = 0; i < (int)v.size(); ++i)
	{
		auto [x, fq] = v[i];
		vector<int> prv(x, -inf);
		
		for (int j = 0; j <= n; ++j)
		{
			if (res[~i & 1][j]) prv[j % x] = j;
			if (j - prv[j % x] <= fq * x)
				res[i&1][j] = true;	
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << res[~(int)v.size() & 1][i];
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
