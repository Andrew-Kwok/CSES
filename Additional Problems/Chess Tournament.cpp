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
const int MAX = 1e5 + 69;

void solve()
{
	int n;
	cin >> n;

	priority_queue<ii> pq;
	for (int i = 1; i <= n; ++i)
	{
		int x; cin >> x;
		if (x) pq.push({x, i});
	}

	vector<ii> res;
	while (!pq.empty())
	{
		auto [deg, node] = pq.top(); pq.pop();
		if (deg > (int)pq.size())
		{
			cout << "IMPOSSIBLE\n";
			return;
		}

		vector<ii> tmp;
		for (int i = 0; i < deg; ++i)
		{
			auto [p, q] = pq.top(); pq.pop();

			res.pb({node, q});
			tmp.pb({p-1, q});
		}
		for (auto &[p, q] : tmp) if (p)
			pq.push({p, q});
	}

	cout << res.size() << '\n';
	for (auto &[u, v] : res)
		cout << u << " " << v << '\n';
}

int main()
{
	fastio;

	int TC = 1;
	//cin >> TC;

	while (TC--)
		solve();

	return 0;
}
