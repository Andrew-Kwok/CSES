#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define f1 first
#define s2 second

#define fastio ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x...) cerr << "[" << #x << "]: " << x << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;

ld const PI = 4*atan((ld)1);

int const N = 2e5 + 7;
struct range
{
	int l, r;
	ll reward;
};

int n;
int len = 0;
range ar[N];
ll dp[2*N] = {};

void compress()
{
	map<int, int> memo;
	for (int i = 0; i < n; ++i)
		memo[ar[i].l] = memo[ar[i].r] = 1;

	for (auto &x : memo)
		x.s2 = ++len;

	for (int i = 0; i < n; ++i)
		ar[i].l = memo[ar[i].l], ar[i].r = memo[ar[i].r];
}

int main()
{
	fastio;

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> ar[i].l >> ar[i].r >> ar[i].reward;

	compress();
	sort(ar, ar+n, [](range const &x, range const &y){
		return x.r < y.r;
	});

	int idx = 0;
	for (int i = 1; i <= len; ++i)
	{
		dp[i] = dp[i-1];
		while (idx < n && ar[idx].r == i)
		{
			dp[i] = max(dp[i], ar[idx].reward + dp[ar[idx].l - 1]);
			idx++;
		}
	}
	cout << dp[len] << '\n';

	return 0;
}
