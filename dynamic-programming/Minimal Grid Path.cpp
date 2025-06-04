#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

#define pb push_back
#define f1 first
#define s2 second

const int MAX = 1 << 12;

int N;
char s[MAX][MAX];

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> s[i];

	string Z = string(1, s[0][0]);
	vector<ii> cur = {{0,0}};

	const auto valid = [&](int r, int c) -> bool
	{
		return 0 <= r && r < N && 0 <= c && c < N;
	};

	for (int i = 0; i < 2*N-2; ++i)
	{
		char best = 'a';
		
		vector<ii> nxt;
		for (auto [r, c] : cur)
		{
			for (auto [nr, nc] : {make_pair(r+1, c), make_pair(r, c+1)})
			{
				if (!valid(nr, nc))
					continue;

				if (best > s[nr][nc]) {
					best = s[nr][nc];
					nxt = {{nr, nc}};
				} else if (best == s[nr][nc]) {
					nxt.pb({nr, nc});
				}
			}
		}

		Z += (best);

		sort(nxt.begin(), nxt.end());
		nxt.resize(unique(nxt.begin(), nxt.end()) - nxt.begin());
		cur = nxt;
	}

	cout << Z << '\n';


	return 0;
}