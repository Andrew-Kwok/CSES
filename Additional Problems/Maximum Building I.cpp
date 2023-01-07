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
int const MAX = 1e3 + 7;

int h[MAX][MAX];
char s[MAX];
int main()
{
	fastio;

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		cin >> s;
		for (int j = 1; j <= m; ++j)
		{
			if (s[j-1] == '.') h[i][j] = h[i-1][j] + 1;
			else h[i][j] = 0;
		}
	}

	int res = 0;
	for (int i = 1; i <= n; ++i)
	{
		vector<ii> st;
		for (int j = 1; j <= m; ++j)
		{
			int pos = j;
			while (!st.empty() && st.back().f1 >= h[i][j])
			{
				res = max(res, (st.back().f1) * (j - st.back().s2));
				pos = st.back().s2;
				st.pop_back();
			}
			st.pb({h[i][j], pos});
		}

		while (!st.empty())
		{
			res = max(res, (st.back().f1) * (m+1 - st.back().s2));
			st.pop_back();
		}
	}
	cout << res << '\n';	

	return 0;
}
