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

map<vector<int>, bool> memo;
bool rc(vector<int> v)
{
	if (v.empty())
		return false;

	sort(v.begin(), v.end());
	if (memo.count(v))
		return memo[v];

	int n = (int)v.size();
	for (int mask = 1; mask < (1 << n); ++mask)
	{
		vector<int> nxt;
		for (int i = 0; i < n; ++i)
		{
			if (mask >> i & 1)
			{
				if (v[i] > 1)
					nxt.pb(v[i]-1);
			}
			else nxt.pb(v[i]);
		}

		if (!rc(nxt))
			return memo[v] = true;
	}
	return memo[v] = false;
}

void solve()
{
	int n;
	cin >> n;


	bool win = false;
	while (n--)
	{
		int x; cin >> x;
		if (x & 1)
			win = true;
	}

	cout << (win ? "first\n" : "second\n");
}

int main()
{
	fastio;

	int TC = 1;
	cin >> TC;

	while (TC--)
		solve();

	return 0;
}
