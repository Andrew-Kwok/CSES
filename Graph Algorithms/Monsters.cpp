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
int const inf = 1e9 + 7;

int n, m;
char grid[N][N];
int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int r, int c)
{
	return 0 <= r && r < n && 0 <= c && c < m;
}

bool border(int r, int c)
{
	return r == 0 || r == n-1 || c == 0 || c == m-1;
}

int monster[N][N];
int dst[N][N];

void monster_bfs()
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			monster[i][j] = inf;

	queue<ii> q;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (grid[i][j] == 'M')
	{
		monster[i][j] = 0;
		q.push({i, j});
	}

	while (!q.empty())
	{
		int r = q.front().f1;
		int c = q.front().s2;
		q.pop();

		for (auto x : moves)
		{
			int nr = r + x[0];
			int nc = c + x[1];

			if (valid(nr, nc) && grid[nr][nc] != '#' && monster[nr][nc] > monster[r][c] + 1)
			{
				monster[nr][nc] = monster[r][c] + 1;
				q.push({nr, nc});
			}
		}
	}
}

string s = "DURL";
string result = "";
void dst_bfs()
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			dst[i][j] = inf;

	queue<ii> q;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (grid[i][j] == 'A')
	{
		if (border(i, j))
		{
			result = "0";
			return;
		}

		dst[i][j] = 0;
		q.push({i, j});
	}

	while (!q.empty())
	{
		int r = q.front().f1;
		int c = q.front().s2;
		q.pop();

		for (auto x : moves)
		{
			int nr = r + x[0];
			int nc = c + x[1];

			if (valid(nr, nc) && grid[nr][nc] != '#' && dst[nr][nc] > dst[r][c] + 1 && monster[nr][nc] > dst[r][c] + 1) 
			{
				dst[nr][nc] = dst[r][c] + 1;

				if (border(nr, nc))
				{
					int r = nr;
					int c = nc;
					while (dst[r][c] != 0)
					{
						for (int i = 0; i < 4; ++i)
						{
							int nr = r + moves[i][0];
							int nc = c + moves[i][1];
							if (valid(nr, nc) && grid[nr][nc] != '#' && dst[nr][nc]+1 == dst[r][c])
							{
								result.push_back(s[i]);
								r = nr;
								c = nc;
								break;
							}
						}
					}

					return;
				}

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
		cin >> grid[i];

	monster_bfs();
	dst_bfs();

	if (result.empty())
	{
		cout << "NO\n";
		return 0;
	}

	reverse(result.begin(), result.end());
	cout << "YES\n";

	if (result == "0")
	{
		cout << 0 << '\n';
		return 0;
	}
	cout << result.size() << '\n';
	cout << result << '\n';

	return 0;
}
