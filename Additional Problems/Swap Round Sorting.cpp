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
const int MAX = 2e5 + 69;

int N;
int ar[MAX];

void solve()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> ar[i];

	int mx = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (ar[i] == i) mx = max(mx, 0);
		else if (ar[ar[i]] == i) mx = max(mx, 1);
		else mx = max(mx, 2);
	}

	if (mx == 0) cout << mx << '\n';
	else if (mx == 1)
	{
		cout << 1 << '\n';

		vector<ii> res;
		for (int i = 1; i <= N; ++i)
		{
			if (ar[i] != i)
			{
				res.pb({i, ar[i]});
				swap(ar[i], ar[ar[i]]);
			}
		}

		cout << res.size() << '\n';
		for (auto [x, y] : res)
			cout << x << " " << y << '\n';
	}
	else
	{
		cout << 2 << '\n';

		bitset<MAX> vst;
		vector<int> sk;
		vector<ii> res;
		for (int i = 1; i <= N; ++i) if (!vst[i])
		{
			sk = { i };
			while (ar[sk.back()] != i) sk.pb(ar[sk.back()]);
			for (int x : sk)
				vst[x] = true;

			for (int j = 0, sz = (int)sk.size(); 2*j < sz; ++j)
			{
				res.pb({sk[j], sk[sz - j - 1]});
				swap(ar[sk[j]], ar[sk[sz - j - 1]]);
			}
		}

		cout << res.size() << '\n';
		for (auto [x, y] : res)
			cout << x << " " << y << '\n';

		res.clear();
		for (int i = 1; i <= N; ++i)
		{
			if (ar[i] != i)
			{
				res.pb({i, ar[i]});
				swap(ar[i], ar[ar[i]]);
			}
		}

		cout << res.size() << '\n';
		for (auto [x, y] : res)
			cout << x << " " << y << '\n';
	}
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
