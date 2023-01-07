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
int const N = 6e5 + 7;
 
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
 
struct info
{
	char c;
	int a, b;
};
 
int n, q;
 
int const MAXLEN = 2e5 + 7;
int ar[MAXLEN];
info query[MAXLEN];
 
inline void compress()
{
	vector<int> v;
	for (int i = 1; i <= n; ++i)
		v.pb(ar[i]);
	for (int i = 1; i <= q; ++i)
	{
		v.pb(query[i].b);
		if (query[i].c == '?') v.pb(query[i].a);
	}
 	sort(v.begin(), v.end());
 
	for (int i = 1; i <= n; ++i)
		ar[i] = lower_bound(v.begin(), v.end(), ar[i]) - v.begin() + 1;
	for (int i = 1; i <= q; ++i)
	{
		query[i].b = lower_bound(v.begin(), v.end(), query[i].b) - v.begin() + 1;
		if (query[i].c == '?') query[i].a = lower_bound(v.begin(), v.end(), query[i].a) - v.begin() + 1;
	}
}
 
int main()
{
	fastio;
 
	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> ar[i];
	for (int i = 1; i <= q; ++i)
		cin >> query[i].c >> query[i].a >> query[i].b;
 
	compress();

	for (int i = 1; i <= n; ++i)
		add(ar[i], 1);
	for (int i = 1; i <= q; ++i)
	{
		if (query[i].c == '!')
		{
			add(ar[query[i].a], -1);
			add(query[i].b, 1);
			ar[query[i].a] = query[i].b;
		}
		else cout << sum(query[i].b) - sum(query[i].a - 1) << '\n';	
	}
 
	return 0;
}