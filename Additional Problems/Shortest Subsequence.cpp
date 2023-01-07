#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x...) cerr << "[" << #x << "]: " << x << "\n";

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using pl = pair<ll, ll>;

ld const PI = 4*atan((ld)1);
const int inf = 1e9 + 7;

int main()
{
	fastio;

	string s;
	cin >> s;

	vector<int> v[4];
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == 'A') v[0].pb(i);
		if (s[i] == 'C') v[1].pb(i);
		if (s[i] == 'G') v[2].pb(i);
		if (s[i] == 'T') v[3].pb(i);
	}

	for (int i = 0; i < 4; ++i)
		v[i].pb(s.size());

	vector<vector<int>> dp(4, vector<int>(s.size() + 1, inf));
	vector<vector<ii>> par(4, vector<ii>(s.size() + 1));
	priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq;
	pq.push({0, {-1, -1}});

	while (!pq.empty())
	{
		int cost = pq.top().f1;
		int ch = pq.top().s2.f1;
		int idx = pq.top().s2.s2;
		pq.pop();

		if (idx == s.size())
			continue;

		for (int i = 0; i < 4; ++i)
		{
			int nxt = *lower_bound(v[i].begin(), v[i].end(), idx + 1);
			if (dp[i][nxt] > 1 + cost)
			{
				dp[i][nxt] = 1 + cost;
				par[i][nxt] = {ch, idx};
				pq.push({1 + cost, {i, nxt}});
			}
		}
	}

	ii node = {0, s.size()};
	for (int i = 1; i < 4; ++i)
		if (dp[node.f1][node.s2] > dp[i][s.size()])
			node.f1 = i;

	string res = "";
	for (; node != mp(-1, -1); node = par[node.f1][node.s2])
	{
		if (node.f1 == 0) res += 'A';
		if (node.f1 == 1) res += 'C';
		if (node.f1 == 2) res += 'G';
		if (node.f1 == 3) res += 'T';
	}
	reverse(res.begin(), res.end());

	cout << res << '\n';
	return 0;
}
