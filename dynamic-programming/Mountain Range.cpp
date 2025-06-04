#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

#define pb push_back
#define f1 first
#define s2 second

const int MAX = 1 << 18;

int N, H[MAX], dp[MAX];

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> H[i];

	vector<ii> v; v.reserve(N);
	for (int i = 0; i < N; ++i)
		v.pb({H[i], i});
	sort(v.rbegin(), v.rend());

	set<int> pos;
	for (int i = 0, j = 0; i < N; ++i)
	{
		while (j < N && v[i].f1 < v[j].f1)
			pos.insert(v[j++].s2);

		auto it = pos.lower_bound(v[i].s2);

		int mx = 0;
		if (it != pos.end()) {
			mx = max(mx, dp[*it]);
		}

		if (it != pos.begin()) {
			mx = max(mx, dp[*prev(it)]);
		}

		dp[v[i].s2] = 1 + mx;
	}

	cout << *max_element(dp, dp + N) << '\n';
	return 0;
}