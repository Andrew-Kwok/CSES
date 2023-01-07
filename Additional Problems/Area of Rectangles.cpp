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
const int MAX = 1e5 + 69;
const int SZ = 8e6;
 
ll st[SZ], delta[SZ];
inline void add(int p, int q, int val, int node = 1, int l = -1e6, int r = 1e6)
{
	if (l > q || r < p)
		return;
	if (p <= l && r <= q)
	{
		delta[node] += val;
		if (delta[node]) st[node] = r-l+1;
		else if (r-l > 0) st[node] = st[node << 1] + st[node << 1 | 1];
		else st[node] = 0;
		return;
	}
 
	int mid = (l + r) >> 1;
	add(p, q, val, node << 1, l, mid);
	add(p, q, val, node << 1 | 1, mid+1, r);
 
	if (delta[node]) st[node] = r-l+1;
	else st[node] = st[node << 1] + st[node << 1 | 1]; 
}
 
void solve()
{
	int N;
	cin >> N;
 
	vector<int> comp;
	vector<array<int, 4>> v(N);
	for (auto &[x1, x2, y1, y2] : v)
	{
		cin >> x1 >> y1 >> x2 >> y2; x2--, y2--;
		comp.pb(x1); comp.pb(x2+1);
	}
	sort(v.begin(), v.end());
	sort(comp.begin(), comp.end());
	comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
 
	priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
 
	int id = 0;
	ll res = 0;
	for (int i = 0; i+1 < (int)comp.size(); ++i)
	{
		while (id < N && v[id][0] <= comp[i])
		{
			add(v[id][2], v[id][3], 1);
			pq.push({v[id][1], v[id][2], v[id][3]});
			id++;
		}
		while (!pq.empty() && pq.top()[0] < comp[i])
		{
			add(pq.top()[1], pq.top()[2], -1);
			pq.pop();
		}
		res += 1ll * (comp[i+1] - comp[i]) * st[1];
	}
	cout << res << '\n';
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
