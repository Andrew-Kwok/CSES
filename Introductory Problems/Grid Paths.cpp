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

bool visited[7][7];

int res = 0;
int idx;
char path[100];

bool valid(int r, int c)
{
	return 0 <= r && r < 7 && 0 <= c && c < 7;
}

int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void solve(int r, int c)
{
	if (r == 6 && c == 0)
	{
		if (idx == 48)
    		res++;
		return;
	}

    if (0 < c && c < 6 && !visited[r][c-1] && !visited[r][c+1] && ((r == 0 && visited[r+1][c]) || (r == 6 && visited[r-1][c])))
        return;
    
    if (0 < r && r < 6 && !visited[r-1][c] && !visited[r+1][c] && ((c == 0 && visited[r][c+1]) || (c == 6 && visited[r][c-1])))
        return;

    if (0 < r && r < 6 && 0 < c && c < 6 && visited[r-1][c] && visited[r+1][c] && !visited[r][c-1] && !visited[r][c+1])
        return;

    if (0 < r && r < 6 && 0 < c && c < 6 && visited[r][c-1] && visited[r][c+1] && !visited[r-1][c] && !visited[r+1][c])
        return;

    
	if (path[idx] == '?')
	{
		for (auto x : moves)
		{
			int nr = r + x[0];
			int nc = c + x[1];

			if (valid(nr, nc) && !visited[nr][nc])
			{
				visited[nr][nc] = true;
				idx++;

                solve(nr, nc);
				
                visited[nr][nc] = false;
                idx--;
            }
		}
	}
	else
	{
        switch(path[idx])
        {
            case 'U':
                if (r != 0 && !visited[r-1][c])
                {
                    visited[r-1][c] = true;
                    idx++;

                    solve(r-1, c);

                    visited[r-1][c] = false;
                    idx--;
                }
                break;

            case 'D':
                if (r != 6 && !visited[r+1][c])
                {
                    visited[r+1][c] = true;
                    idx++;

                    solve(r+1, c);

                    visited[r+1][c] = false;
                    idx--;
                }
                break;

            case 'L':
                if (c != 0 && !visited[r][c-1])
                {
                    visited[r][c-1] = true;
                    idx++;

                    solve(r, c-1);

                    visited[r][c-1] = false;
                    idx--;
                }
                break;

            case 'R':
                if (c != 6 && !visited[r][c+1])
                {
                    visited[r][c+1] = true;
                    idx++;

                    solve(r, c+1);

                    visited[r][c+1] = false;
                    idx--;
                }
                break;
        }
	}
}

int main()
{
	fastio;

	cin >> path;

	visited[0][0] = true;
	solve(0, 0);
    cout << res << '\n';

	return 0;
}
