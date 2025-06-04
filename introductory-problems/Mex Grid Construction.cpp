#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int Z[N][N] = {};
	for (int d = 0; d <= 2*N-2; ++d)
	{
		for (int r = 0; r < N; ++r) 
		{
			int c = d-r;
			if (0 <= c && c < N)
			{
				set<int> st;
				for (int i = r-1; i >= 0; --i)
					st.insert(Z[i][c]);
				for (int i = c-1; i >= 0; --i)
					st.insert(Z[r][i]);

				for (int i = 0; i < 2*N; ++i) if (!st.count(i)) {
					Z[r][c] = i;
					break;
				}
			}
		}
	}

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cout << Z[i][j] << " \n"[j == N-1];


	return 0;
}