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

vector<ii> res;
void solve_toh(int n, int from, int to)
{
	if (n == 0)
		return;

	int new_to;
	for (int i = 1; i <= 3; ++i)
	{
		if (from != i && to != i)
			new_to = i;
	}

	solve_toh(n-1, from, new_to);
	res.pb({from, to});
	solve_toh(n-1, new_to, to);
}

int main()
{
	fastio;

	int n;
	cin >> n;

	solve_toh(n, 1, 3);

	cout << res.size() << '\n';
	for (ii x : res)
		cout << x.f1 << " " << x.s2 << '\n';

	return 0;
}
