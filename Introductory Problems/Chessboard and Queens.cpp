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

int res = 0;
char board[8][8];

bool used[8][8];
bool possible(int r, int c)
{
	for (int i = 1; i <= 8; ++i)
	{
		if (r-i >= 0 && used[r-i][c])
			return false;
		if (r-i >= 0 && c-i >= 0 && used[r-i][c-i])
			return false;
		if (r-i >= 0 && c+i < 8 && used[r-i][c+i])
			return false;
	}
	return true;
}

void rc(int r, int c)
{
	if (r == 8)
	{
		res++;
		return;
	}

	if (c == 8)
		return;

	if (board[r][c] == '.' && possible(r, c))
	{
		used[r][c] = true;
		rc(r+1, 0);
		used[r][c] = false;
	}

	rc(r, c+1);
}

int main()
{
	fastio;

	for (int i = 0; i < 8; ++i)
		cin >> board[i];

	rc(0, 0);
	cout << res << '\n';

	return 0;
}
