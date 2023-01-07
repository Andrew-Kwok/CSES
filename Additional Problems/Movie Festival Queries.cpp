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
const int MAX = 1e6 + 69;
 
int up[MAX][20];  
 
void solve()
{
	for (int i = 0; i < MAX; ++i)
		up[i][0] = MAX - 1;
 
	int N, Q;
	cin >> N >> Q;
 
	vector<ii> v(N);
	for (auto &[r, l] : v)
		cin >> l >> r;
	sort(v.begin(), v.end());
 
	int pos = 0;
	for (auto &[r, l] : v)
	{
		while (pos <= l)
			up[pos++][0] = r;
	}
 
	for (int j = 1; j < 20; ++j)
		for (int i = 0; i < MAX; ++i)
			up[i][j] = up[up[i][j-1]][j-1];
 
	while (Q--)
	{
		int a, b;
		cin >> a >> b;
 
		int res = 0;
		for (int i = 19; i >= 0; --i)
		{
			if (up[a][i] <= b)
				a = up[a][i], res += (1 << i);
		}
		cout << res << '\n';
	}
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
