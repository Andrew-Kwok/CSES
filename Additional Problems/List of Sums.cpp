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

int N;
multiset<int> mst;

vector<int> res;
inline void rc(int i)
{
	if (i == N)
	{
		for (int x : res)
			cout << x << " ";
		cout << '\n';
		exit(0);
	}

	int val = *mst.begin() - res[0];
	if (val >= res.back())
	{
		bool ok = true;
		for (int x : res)
		{
			if (mst.count(x + val))
				mst.erase(mst.lower_bound(x + val));
			else ok = false;
		}

		if (ok) res.pb(val), rc(i+1);
		else return;
	}
	return;
}

void solve()
{
	cin >> N;

	vector<int> v(N * (N-1) / 2);
	for (int &x : v)
		cin >> x;
	sort(v.begin(), v.end());

	for (int i = 2; i < N * (N-1) / 2; ++i)
	{
		mst = multiset<int>(v.begin(), v.end());
		res = { (v[0] + v[1] - v[i]) / 2 };
		rc(1);
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
