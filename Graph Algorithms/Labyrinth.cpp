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
char s[N][N];
int par[N][N];
bool vst[N][N];

bool valid(int r, int c)
{
	return 0 <= r && r < n && 0 <= c && c < m;
}

int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
string code = "UDLR";
void bfs(int r, int c)
{
	string res = "";

	par[r][c] = -1;

	queue<ii> q;
	vst[r][c] = true;
	q.push({r, c});
	while (!q.empty())
	{
		r = q.front().f1;
		c = q.front().s2;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nr = r + moves[i][0];
			int nc = c + moves[i][1];

			if (valid(nr, nc) && s[nr][nc] != '#' && !vst[nr][nc])
			{
				vst[nr][nc] = true;
				par[nr][nc] = i;
				q.push({nr, nc});

				if (s[nr][nc] == 'B')
				{
					for (; par[nr][nc] != -1;)
					{
						int idx = par[nr][nc];
						res.pb(code[idx]);

						nr -= moves[idx][0];
						nc -= moves[idx][1];
					}

					i = 10;
					while (!q.empty())
						q.pop();
				}
			}
		}
	}

	if (res.empty())
	{
		cout << "NO\n";
		return;
	}
	cout << "YES\n";

	reverse(res.begin(), res.end());
	cout << res.size() << '\n';
	cout << res << '\n';
}

int main()
{
	fastio;

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> s[i];

	int r, c;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
	{
		if (s[i][j] == 'A')
			r = i, c = j;
	}

	bfs(r, c);

	return 0;
}
