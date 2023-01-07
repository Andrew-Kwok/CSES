#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define ll long long

inline vector<vector<ll>> merge(vector<vector<ll>> &x, vector<vector<ll>> &y)
{
	int n = (int)x.size();
	vector<vector<ll>> res(n, vector<ll>(n, -1));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				if (x[i][j] != -1 && y[j][k] != -1)
				{
					if (res[i][k] == -1)
						res[i][k] = x[i][j] + y[j][k];
					else res[i][k] = min(res[i][k], x[i][j] + y[j][k]);
				}
			}
		}
	}
	return res;
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<ll>> C[30];
	C[0].resize(n, vector<ll>(n, -1));
	for (int i = 0; i < m; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;

		if (C[0][u-1][v-1] == -1)
			C[0][u-1][v-1] = w;
		else C[0][u-1][v-1] = min(C[0][u-1][v-1], (ll)w);
	}

	for (int i = 1; i < 30; ++i)
		C[i] = merge(C[i-1], C[i-1]);


	vector<vector<ll>> res;
	for (int i = 0; i < 30; ++i)
	{
		if (k >> i & 1)
		{
			if (res.empty()) res = C[i];
			else res = merge(res, C[i]);
		}
	}
	cout << res[0][n-1] << '\n';

	return 0;
}