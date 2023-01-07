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
const int MAX = 2e5 + 69;

int N;
int ar[MAX];
ll flow[MAX]; // number of food given by left child

inline ll func(ll X)
{
	ll res = 0;
	for (int i = 0; i < N; ++i)
		res += abs(flow[i] - X);
	return res;
}

void solve()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> ar[i];
	for (int i = 0, x; i < N; ++i)
		cin >> x, ar[i] -= x;

	for (int i = 1; i < N; ++i)
		flow[i] = flow[i-1] + ar[i-1];
	
	vector<ll> v;
	for (int i = 0; i < N; ++i)
		v.pb(flow[i]);
	sort(v.begin(), v.end());

	if (N & 1) cout << func(v[N/2]) << '\n';
	else cout << min(func((v[N/2] + v[N/2-1]) / 2), func((v[N/2] + v[N/2-1] + 1) / 2)) << '\n';
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
