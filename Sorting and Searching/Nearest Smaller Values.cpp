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

ii ar[N];
int res[N];
int main()
{
	fastio;

	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
		cin >> ar[i].f1, ar[i].s2 = i;
	sort(ar+1, ar+n+1);

	set<int> st; st.insert(0);
	vector<int> pending;
	for (int i = 1; i <= n; ++i)
	{
		if (ar[i].f1 != ar[i-1].f1)
		{
			for (int x : pending)
				st.insert(x);
			pending.clear();
		}

		if (*prev(st.end()) < ar[i].s2) res[ar[i].s2] = *prev(st.end());
		else res[ar[i].s2] = *prev(st.lower_bound(ar[i].s2));

		pending.pb(ar[i].s2);
	}

	for (int i = 1; i <= n; ++i)
	{
		if (i > 1) cout << " ";
		cout << res[i];
	}
	cout << '\n';	

	return 0;
}
