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
const int MAX = 2e5 + 69;

int len, alpha;
char s[MAX];
int pfx[MAX][26];

void solve()
{
	cin >> (s+1);
	len = (int)strlen(s+1);

	string tmp = s+1;
	sort(tmp.begin(), tmp.end());
	tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());

	alpha = (int)tmp.size();
	map<vector<int>, int> ctr;
	ctr[vector<int>(alpha * (alpha-1) / 2, 0)]++;
	for (int i = 1; i <= len; ++i)
	{
		pfx[i][lower_bound(tmp.begin(), tmp.end(), s[i]) - tmp.begin()] += 1;
		for (int j = 0; j < alpha; ++j)
			pfx[i][j] += pfx[i-1][j];

		vector<int> vec;
		for (int j = 0; j < alpha; ++j)
			for (int k = j+1; k < alpha; ++k)
				vec.pb(pfx[i][j] - pfx[i][k]);

		ctr[vec]++;
	}


	ll ans = 0;
	for (const auto &[dif, val] : ctr)
		ans += 1ll * val * (val - 1) / 2;
	cout << ans << '\n';
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
