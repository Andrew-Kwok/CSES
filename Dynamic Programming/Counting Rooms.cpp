#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x...) cerr << "[" << #x << "]: " << x << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;

ld const PI = 4*atan((ld)1);

int const N = 1e3 + 7;

int n, m;
bool vst[N][N];
char s[N][N];

bool valid(int r, int c)
{
	return 0 <= r && r < n && 0 <= c && c < m;
}

int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void bfs(int r, int c)
{
	queue<ii> q;
	q.push({r, c});
	while (!q.empty())
	{
		r = q.front().f1;
		c = q.front().s2;
		q.pop();

		for (auto mov : moves)
		{
			int nr = r + mov[0];
			int nc = c + mov[1];

			if (valid(nr, nc) && s[nr][nc] == '.' && !vst[nr][nc])
			{
				vst[nr][nc] = true;
				q.push({nr, nc});
			}
		}
	}
}

int main()
{
	fastio;

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> s[i];

	int res = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
	{
		if (s[i][j] == '.' && !vst[i][j])
		{
			res++;
			bfs(i, j);
		}
	}

	cout << res << '\n';

	return 0;
}
