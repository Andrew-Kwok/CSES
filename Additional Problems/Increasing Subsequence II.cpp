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
ll const mod = 1e9 + 7;
int const MAX = 2e5 + 7;

inline ll add(ll x, ll y)
{
	return (x + y) % mod;
}

inline ll sub(ll x, ll y)
{
	return (x - y + mod) % mod;
}

int bit[MAX];
void bit_add(int x, int val)
{
	for (int i = x; i < MAX; i += (i & -i))
		bit[i] = add(bit[i], val);
}

int bit_sum(int x)
{
	int res = 0;
	for (int i = x; i > 0; i -= (i & -i))
		res = add(res, bit[i]);
	return res;
}

void compress(vector<int> &v)
{
	vector<int> nv = v;
	sort(nv.begin(), nv.end());

	for (int &x : v)
		x = 1 + lower_bound(nv.begin(), nv.end(), x) - nv.begin();
}

int main()
{
	fastio;

	int n;
	cin >> n;

	vector<int> v(n);
	for (int &x : v)
		cin >> x;
	compress(v);

	for (int x : v)
	{
		bit_add(x, bit_sum(x-1));
		bit_add(x, 1);
	}

	cout << bit_sum(MAX-1) << '\n';
	return 0;
}
