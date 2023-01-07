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
const int MAX = 107;
const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };

int n, m;
bool dp[MAX][MAX];
char res[MAX][MAX] = {};

void connect(int x1, int y1, int x2, int y2, int x3, int y3)
{
	if (res[x1][y1] || res[x2][y2] || res[x3][y3])
		return;

	set<char> st;
	for (int i = 0; i < 4; ++i)
	{
		int nx = x1 + dx[i], ny = y1 + dy[i];
		if (res[nx][ny])
			st.insert(res[nx][ny]);
	}
	for (int i = 0; i < 4; ++i)
	{
		int nx = x2 + dx[i], ny = y2 + dy[i];
		if (res[nx][ny])
			st.insert(res[nx][ny]);
	}
	for (int i = 0; i < 4; ++i)
	{
		int nx = x3 + dx[i], ny = y3 + dy[i];
		if (res[nx][ny])
			st.insert(res[nx][ny]);
	}

	char cur = 'A';
	while (st.count(cur))
		cur++;

	res[x1][y1] = res[x2][y2] = res[x3][y3] = cur;
}

void place(int r1, int c1, int r2, int c2)
{
	if ((r2 - r1 + 1) % 2 == 0 && (c2 - c1 + 1) % 3 == 0)
	{
		// ABB
		// AAB
		for (int i = r1; i <= r2; i += 2)
		{
			for (int j = c1; j <= c2; j += 3)
			{
				connect(i, j, i+1, j, i, j+1);
				connect(i+1, j+1, i, j+2, i+1, j+2);
			}
		}
	}
	else
	{
		// AA
		// AB
		// AA
		for (int i = r1; i <= r2; i += 3)
		{
			for (int j = c1; j <= c2; j += 2)
			{
				connect(i, j, i+1, j, i, j+1);
				connect(i+1, j+1, i+2, j, i+2, j+1);
			}
		}
	}
}

const string nine[] = {
	"AABBCAABB",
	"ACCBCCABA",
	"BBCAABBAA",
	"BABACBABB",
	"AABBCCAAB"
};

void place9(int r1, int c1, int r2, int c2)
{
	if ((r2 - r1 + 1) % 5 == 0)
	{
		for (int i = r1; i <= r2; i += 5)
		{
			for (int j = c1; j <= c2; j += 9)
			{
				for (int r = 0; r < 5; ++r)
				{
					for (int c = 0; c < 9; ++c)
					{
						vector<ii> v;
						v.pb({i+r, j+c});

						for (int k = 0; k < 4; ++k)
						{
							int nr = r + dx[k];
							int nc = c + dy[k];
							if (0 <= nr && nr < 5 && 0 <= nc && nc < 9 && nine[r][c] == nine[nr][nc])
								v.pb({i+nr, j+nc});
						}

						if (v.size() == 3)
							connect(v[0].f1, v[0].s2, v[1].f1, v[1].s2, v[2].f1, v[2].s2);
					}
				}
			}
		}
	}
	else
	{
		for (int i = r1; i <= r2; i += 9)
		{
			for (int j = c1; j <= c2; j += 5)
			{
				for (int r = 0; r < 9; ++r)
				{
					for (int c = 0; c < 5; ++c)
					{
						vector<ii> v;
						v.pb({i+r, j+c});

						for (int k = 0; k < 4; ++k)
						{
							int nr = r + dx[k];
							int nc = c + dy[k];
							if (0 <= nr && nr < 9 && 0 <= nc && nc < 5 && nine[c][r] == nine[nc][nr])
								v.pb({i+nr, j+nc});
						}

						if (v.size() == 3)
							connect(v[0].f1, v[0].s2, v[1].f1, v[1].s2, v[2].f1, v[2].s2);
					}
				}
			}
		}
	}
}

void solve()
{
	for (int i = 0; i < MAX; ++i)
		dp[i][0] = dp[0][i] = true;

	for (int i = 1; i < MAX; ++i)
	{		
		for (int j = 1; j < MAX; ++j)
		{
			if (j % 3 == 0 && i >= 2)
				dp[i][j] |= dp[i-2][j];
			if (j % 2 == 0 && i >= 3)
				dp[i][j] |= dp[i-3][j];
			if (i % 3 == 0 && j >= 2)
				dp[i][j] |= dp[i][j-2];
			if (i % 2 == 0 && j >= 3)
				dp[i][j] |= dp[i][j-3];
			if (i % 9 == 0 && j >= 5)
				dp[i][j] |= dp[i][j-5];
			if (i >= 5 && j % 9 == 0)
				dp[i][j] |= dp[i-5][j];
		}
	}

	cin >> n >> m;
	if (!dp[n][m])
	{
		cout << "NO\n";
		return;
	}

	memset(res, 0, sizeof(res));
	for (int i = n, j = m; i > 0 && j > 0;)
	{
		if (j % 3 == 0 && i >= 2 && dp[i-2][j])
		{
			place(i-1, 1, i, j);
			i -= 2;
		}
		else if (j % 2 == 0 && i >= 3 && dp[i-3][j])
		{
			place(i-2, 1, i, j);
			i -= 3;
		}
		else if (i % 3 == 0 && j >= 2 && dp[i][j-2])
		{
			place(1, j-1, i, j);
			j -= 2;
		}
		else if (i % 2 == 0 && j >= 3 && dp[i][j-3])
		{
			place(1, j-2, i, j);
			j -= 3;
		}
		else if (i >= 9 && j >= 5 && dp[i-9][j-5])
		{
			place9(1, j-4, i, j);
			j -= 5;
		}
		else if (i >= 5 && j >= 9 && dp[i-5][j-9])
		{
			place9(i-4, 1, i, j);
			i -= 5;
		}

		// if (ctr == 4)
		// 	break;
	}

	// bool vst[MAX][MAX] = {};
	// for (int i = 1; i <= n; ++i)
	// {
	// 	for (int j = 1; j <= m; ++j) if (!vst[i][j])
	// 	{
	// 		int ctr = 1;
	// 		queue<ii> q;
	// 		vst[i][j] = true;
	// 		q.push({i, j});

	// 		while (!q.empty())
	// 		{
	// 			auto [r, c] = q.front(); q.pop();
	// 			for (int k = 0; k < 4; ++k)
	// 			{
	// 				int nr = r + dx[k];
	// 				int nc = c + dy[k];

	// 				if (1 <= nr && nr <= n && 1 <= nc && nc <= m && !vst[nr][nc] && res[r][c] == res[nr][nc])
	// 				{
	// 					vst[nr][nc] = true;
	// 					ctr++;
	// 					q.push({nr, nc});
	// 				}
	// 			}
	// 		}

	// 		// cerr << n << " " << m << " " << ctr << '\n';
	// 		// assert(ctr == 3);
	// 	}
	// }

	cout << "YES\n";
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (!('A' <= res[i][j] && res[i][j] <= 'Z'))
			{
				cerr << n << " and " << m << '\n';
				assert(0);
			}
			cout << res[i][j];
		}
		cout << '\n';
	}
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
