#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define pl pair<ll, ll>
#define f1 first
#define s2 second

int const N = 2e5 + 7;

int n, k;
ll ar[N];
pl bit[N]; //first: quantity, second: sum
inline void add(int x, int val)
{
	int dif = (val > 0 ? 1 : -1);
	while (x < N)
		bit[x].f1 += dif, bit[x].s2 += val, x += (x & -x); 
}

inline pl sum(int x)
{
	pl res = {0, 0};
	while (x)
		res.f1 += bit[x].f1, res.s2 += bit[x].s2, x -= (x & -x);
	return res;
}

int r_compress[N];
void compress()
{
	vector<int> v;
	for (int i = 0; i < n; ++i)
		v.pb(ar[i]);
	sort(v.begin(), v.end());

	vector<int> nv;
	for (int x : v)
	{
		if (nv.empty() || nv.back() != x)
			nv.pb(x);
	}

	for (int i = 0; i < n; ++i)
	{
		int tmp = 1 + lower_bound(nv.begin(), nv.end(), ar[i]) - nv.begin();
		r_compress[tmp] = ar[i]; 
		ar[i] = tmp;
	}
}

ll getCost()
{
	int x = (k+1) / 2;
	int lt = 1, rt = 2e5;

	while (lt < rt)
	{
		int mid = (lt + rt) / 2;
		if (sum(mid).f1 < x) lt = mid + 1;
		else rt = mid;
	}

	ll median = r_compress[lt];
	ll cost = 0;

	pl half = sum(lt);
	pl all = sum(2e5);
	cost += half.f1 * median - half.s2;
	cost += (all.s2 - half.s2) - (all.f1 - half.f1) * median;

	return cost;
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> ar[i];
	compress();

	for (int i = 0; i < k; ++i)
		add(ar[i], r_compress[ar[i]]);

	cout << getCost();
	for (int i = k; i < n; ++i)
	{
		add(ar[i-k], -r_compress[ar[i-k]]);
		add(ar[i], r_compress[ar[i]]);

		cout << " " << getCost();
	}
	cout << '\n';

	return 0;
}