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
	memset(res, 0, sizeof(res));
	
	cin >> n >> m;
	if (n == 1 || m == 1)
	{
		cout << "NO\n";
		return;
	}

	if (n % 3 && m % 3)
	{
		cout << "NO\n";
		return;
	}

	bool swp = false;
	if (n % 3)
	{
		swp = true;
		swap(n, m);
	}

	bool ans = true;
	const auto func = [&](const auto &self, int r1, int c1, int r2, int c2) -> void
	{
		int r = r2 - r1 + 1, c = c2 - c1 + 1;
		if (c % 2 == 0)
		{
			place(r1, c1, r2, c2);
		}
		else if (r % 2 == 0)
		{
			place(r1, c1, r2, c1 + 2);
			if (c2 > c1 + 2)
				place(r1, c1 + 3, r2, c2);
		}
		else if (n >= 9 && m >= 5)
		{
			place9(1, 1, 9, 5);
			if (n > 9)
			{
				self(self, 10, 1, n, 5);
			}
			if (m > 5)
			{
				self(self, 1, 6, 9, m);
			}
			if (n > 9 && m > 5)
			{
				self(self, 10, 6, n, m);
			}
		}
		else
		{
			ans = false;
		}
	};
	func(func, 1, 1, n, m);

	cout << (ans ? "YES\n" : "NO\n");
	if (!ans)
		return;

	if (swp)
	{
		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
				cout << res[j][i];
			cout << '\n';
		}
	}
	else
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
				cout << res[i][j];
			cout << '\n';
		}
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