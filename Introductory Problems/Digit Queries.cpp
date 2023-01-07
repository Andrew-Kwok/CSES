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

void solve()
{
	ll k;
	cin >> k;

	ll digit = 1;
	ll nums = 9;
	ll sum = 0;

	while (k > digit * nums)
	{
		k -= digit * nums;
		
		sum += nums;
		digit++;
		nums *= 10;
	}

	cerr << k << '\n';

	ll x = sum + (k + digit - 1) / digit;
	
	string s = to_string(x);
	cout << s[(k-1) % digit] << '\n';
}

int main()
{
	fastio;

	int q;
	cin >> q;

	while (q--)
		solve();

	return 0;
}
