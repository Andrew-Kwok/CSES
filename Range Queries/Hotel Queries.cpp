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
int const N = 2e5 + 7;

int n;
int h[2*N];
void build()
{
	for (int i = n-1; i > 0; --i)
		h[i] = max(h[i << 1], h[i << 1 | 1]);
}

void modify(int p, int val)
{
	for (h[p += n] += val; p > 1; p >>= 1)
		h[p >> 1] = max(h[p], h[p ^ 1]);
}

int query(int l, int r) //[l, r) base 0
{
	int res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1) res = max(res, h[l++]);
		if (r & 1) res = max(res, h[--r]);
	}
	return res;
}

int main()
{
	fastio;

	int q;
	cin >> n >> q;
	for (int i = 0; i < n; ++i)
		cin >> h[i + n];

	build();
	for (int i = 0; i < q; ++i)
	{
		if (i) cout << " ";

		int r; cin >> r;
		if (query(0, n) < r) cout << 0;
		else
		{
			int lt = 0, rt = n-1;
			while (lt < rt)
			{
				int mid = (lt + rt) / 2;
				if (query(0, mid+1) < r) lt = mid+1;
				else rt = mid;
			}

			modify(lt, -r);
			cout << lt+1;
		}
	}
	cout << '\n';

	return 0;
}
