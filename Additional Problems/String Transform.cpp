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

void solve()
{
	string s; cin >> s;
	int n = (int)s.size();

	vector<int> v, idx[26];
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == '#') v.pb(i);
		else idx[s[i] - 'a'].pb(i);
	}

	for (int i = 0; i < 26; ++i)
		for (int x : idx[i])
			v.pb(x);

	string res = "";
	for (int cur = v[v[0]]; s[cur] != '#'; cur = v[cur])
		res += s[cur];
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
