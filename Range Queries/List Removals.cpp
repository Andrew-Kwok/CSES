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

int ar[N];
int main()
{
	fastio;

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> ar[i];

	for (int i = 1; i <= n; ++i)
	{
		int p; cin >> p;

		int lt = 1, rt = n;
		while (lt < rt)
		{
			int mid = (lt + rt) / 2;
			if (mid - sum(mid) >= p) rt = mid;
			else lt = mid + 1;
		}

		if (i > 1) cout << " ";
		cout << ar[lt];

		add(lt, 1);
	}
	cout << '\n';


	return 0;
}
