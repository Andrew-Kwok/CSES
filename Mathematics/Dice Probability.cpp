#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x...) cerr << "[" << #x << "]: " << x << "\n";

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using pl = pair<ll, ll>;

ld const PI = 4*atan((ld)1);

int main()
{
	fastio;

	int n, a, b;
	cin >> n >> a >> b;

	vector<vector<double>> v(n+1, vector<double> (6*n + 1));
	v[0][0] = 1;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= 6; ++j)
		{
			for (int k = 6*n; k >= j; --k)
				v[i][k] += v[i-1][k-j] / 6;
		}
	}

	double prob = 0;
	for (int i = a; i <= b; ++i)
		prob += v[n][i];

	cout << fixed << setprecision(6) << prob << '\n';

	return 0;
}
