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
const int MAX = 3e5 + 69;
const int BLOCK = 369;


int bit[MAX / BLOCK + 5][MAX];
inline void add(int j, int x, int val)
{
	for (; x < MAX; x += (x & -x))
		bit[j][x] += val;
}

inline int sum(int j, int x)
{
	int res = 0;
	for (; x > 0; x -= (x & -x))
		res += bit[j][x];
	return res;
}

void solve()
{
	int N;
	cin >> N;

	vector<array<int, 3>> hor, ver;
	for (int i = 0; i < N; ++i)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);

		if (x1 == x2) ver.pb({x1, y1, y2});
		else hor.pb({y1, x1, x2});
	}

	{
		vector<int> comp;
		for (auto &[x, y1, y2] : ver)
			comp.pb(x);
		for (auto &[y, x1, x2] : hor)
			comp.pb(x1), comp.pb(x2);
		
		sort(comp.begin(), comp.end());
		comp.resize(unique(comp.begin(), comp.end()) - comp.begin());

		for (auto &[x, y1, y2] : ver)
			x = 1 + (int)(lower_bound(comp.begin(), comp.end(), x) - comp.begin());
		for (auto &[y, x1, x2] : hor)
		{
			x1 = 1 + (int)(lower_bound(comp.begin(), comp.end(), x1) - comp.begin());
			x2 = 1 + (int)(lower_bound(comp.begin(), comp.end(), x2) - comp.begin());
		}
	}

	{
		vector<int> comp;
		for (auto &[x, y1, y2] : ver)
			comp.pb(y1), comp.pb(y2);
		for (auto &[y, x1, x2] : hor)
			comp.pb(y);
		
		sort(comp.begin(), comp.end());
		comp.resize(unique(comp.begin(), comp.end()) - comp.begin());

		for (auto &[x, y1, y2] : ver)
		{
			y1 = 1 + (int)(lower_bound(comp.begin(), comp.end(), y1) - comp.begin());
			y2 = 1 + (int)(lower_bound(comp.begin(), comp.end(), y2) - comp.begin());
		}
		for (auto &[y, x1, x2] : hor)
			y = 1 + (int)(lower_bound(comp.begin(), comp.end(), y) - comp.begin());
	}

	sort(ver.begin(), ver.end());
	
	int len = (int)ver.size();
	for (int j = 0; j*BLOCK < len; ++j)
	{
		for (int i = j*BLOCK; i < (j+1) * BLOCK && i < len; ++i)
		{
			add(j, ver[i][1], 1);
			add(j, ver[i][2] + 1, -1);
		}
	}

	ll res = 0;
	for (auto &[y, x1, x2] : hor)
	{
		for (int j = 0; j*BLOCK < len; ++j)
		{
			if (ver[j * BLOCK][0] > x2 || ver[min(len, (j+1) * BLOCK) - 1][0] < x1)
				continue;
			else if (x1 <= ver[j * BLOCK][0] && ver[min(len, (j+1) * BLOCK) - 1][0] <= x2)
				res += sum(j, y);
			else
			{
				for (int i = j*BLOCK; i < (j+1) * BLOCK && i < len; ++i)
					res += x1 <= ver[i][0] && ver[i][0] <= x2 && ver[i][1] <= y && y <= ver[i][2];
			}
		}
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
