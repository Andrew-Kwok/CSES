#include <bits/stdc++.h>
using namespace std;

#define f1 first
#define s2 second;

using ii = pair<int, int>;

const int MAX = 1 << 10;
const int dx[] = {2, 1, 2, 1, -2, -1, -2, -1};
const int dy[] = {1, 2, -1, -2, 1, 2, -1, -2};

int dist[MAX][MAX];

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	memset(dist, -1, sizeof(dist));

	int N;
	cin >> N;

	queue<ii> q;
	dist[0][0] = 0; q.push({0, 0});

	const auto valid = [&](int r, int c) -> bool
	{
		return 0 <= r && r < N && 0 <= c && c < N;
	};

	while (!q.empty())
	{
		auto [r, c] = q.front(); q.pop();
		for (int i = 0; i < 8; ++i)
		{
			int nr = r + dx[i], nc = c + dy[i];
			if (valid(nr, nc) && dist[nr][nc] == -1)
			{
				dist[nr][nc] = 1 + dist[r][c];
				q.push({nr, nc});
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			cout << dist[i][j] << " \n"[j == N-1];
	}


	return 0;
}