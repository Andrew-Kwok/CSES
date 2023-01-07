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

struct guest
{
	int l, r, idx;
};

guest ar[N];
int res[N];
set<ii> st;
int main()
{
	fastio;

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> ar[i].l >> ar[i].r, ar[i].idx = i;
	sort(ar, ar+n, [](guest const &x, guest const &y){
		return x.r < y.r || x.r == y.r && x.l < y.l;
	});

	int ctr = 1;
	st.insert({0, 1}); //Last time usage of room, room number
	for (int i = 0; i < n; ++i)
	{
		if ((*st.begin()).f1 >= ar[i].l) //No vacant room
		{
			st.insert({ar[i].r, ++ctr});
			res[ar[i].idx] = ctr;
		}
		else if ((*prev(st.end())).f1 < ar[i].l)
		{
			auto largest = prev(st.end());
			if ((*largest).f1 < ar[i].l)
			{
				ii new_data = {ar[i].r, (*largest).s2};
				res[ar[i].idx] = (*largest).s2;

				st.erase(largest);
				st.insert(new_data);
			}
		}
		else
		{
			auto it = st.lower_bound({ar[i].l, 0});
			
			it = prev(it);

			ii new_data = {ar[i].r, (*it).s2};
			res[ar[i].idx] = (*it).s2;

			st.erase(it);
			st.insert(new_data);
		}
	}

	cout << ctr << '\n';
	for (int i = 0; i < n; ++i)
	{
		if (i) cout << " ";
		cout << res[i];
	}
	cout << '\n';

	return 0;
}
