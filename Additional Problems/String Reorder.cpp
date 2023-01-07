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

int n, fq[26] = {};
char s[MAX];

void solve()
{
	cin >> s;
	n = (int)strlen(s);

	for (int i = 0; i < n; ++i)
		fq[s[i] - 'A']++;

	string res = "";
	for (int i = 0; i < n; ++i)
	{
		int forced = -1;
		for (int j = 0; j < 26; ++j)
		{
			if (!res.empty() && res.back() == 'A' + j)
				continue;
			else if (fq[j] * 2 - 1 > n - i)
				forced = -2;
			else if (fq[j] * 2 - 1 == n - i)
				forced = j;
		}

		if (forced == -2)
		{
			cout << -1 << '\n';
			break;
		}

		if (forced == -1)
		{
			for (int j = 0; j < 26; ++j)
			{
				if (fq[j])
				{
					if (!res.empty() && res.back() == 'A' + j)
						continue;
					res += (char)('A' + j);
					fq[j]--;
					break;
				}
			}
		}
		else res += (char)('A' + forced), fq[forced]--;
	}
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
