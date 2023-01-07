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

void solve()
{
	int n;
	cin >> n;

	ll res = 0;
	priority_queue<int> pq;
	for (int i = 0, x; i < n; ++i)
	{
		cin >> x;
		pq.push(x);
		res += pq.top() - x;
		pq.pop(); pq.push(x);
	}
	cout << res << '\n';
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
