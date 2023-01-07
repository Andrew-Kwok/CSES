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
const int MAX = 2e5 + 7;

int bit[MAX];
inline void add(int x, int val)
{
	for (int i = x; i < MAX; i += (i & -i))
		bit[i] += val;
}

inline int sum(int x)
{
	int res = 0;
	for (int i = x; i; i -= (i & -i))
		res += bit[i];
	return res;
}

int main()
{
	fastio;

	int n, k = 1; 
	cin >> n;
	//cin >> n >> k;

	for (int i = 1; i <= n; ++i)
		add(i, 1);

	int pos = 0;	
	for (int i = 0; i < n; ++i)
	{
		pos = (pos + k) % (n - i);
		
		int l = 1, r = n;
		while (l < r)
		{
			int mid = (l + r) / 2;
			if (sum(mid) < pos + 1) l = mid + 1;
			else r = mid;
		}
		cout << l << " ";
		add(l, -1);
	}
	cout << '\n';

	return 0;
}
