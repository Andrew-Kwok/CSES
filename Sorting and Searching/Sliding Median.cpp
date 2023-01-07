#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int const N = 2e5 + 7;

int n, k;
int ar[N];
int bit[N];
inline void add(int x, int val)
{
	while (x < N)
		bit[x] += val, x += (x & -x); 
}

inline int sum(int x)
{
	int res = 0;
	while (x)
		res += bit[x], x -= (x & -x);
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

int getMedian()
{
	int x = (k+1) / 2;
	int lt = 1, rt = 2e5;

	while (lt < rt)
	{
		int mid = (lt + rt) / 2;
		if (sum(mid) < x) lt = mid + 1;
		else rt = mid;
	}
	return r_compress[lt];
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
		add(ar[i], 1);

	cout << getMedian();
	for (int i = k; i < n; ++i)
	{
		add(ar[i-k], -1);
		add(ar[i], 1);

		cout << " " << getMedian();
	}
	cout << '\n';

	return 0;
}