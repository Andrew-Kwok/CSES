#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ii pair<int, int>
#define f1 first
#define s2 second

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

int n, q;
int ar[N];
pair<ii, int> query[N];
int res[N];

int pos[N];
void compress()
{
	vector<int> v;
	for (int i = 1; i <= n; ++i)
		v.pb(ar[i]);
	sort(v.begin(), v.end());

	for (int i = 1; i <= n; ++i)
		ar[i] = 1 + lower_bound(v.begin(), v.end(), ar[i]) - v.begin();
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	fill(pos, pos + N, -1);

	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
		cin >> ar[i];
	compress();

	for (int i = 0; i < q; ++i)
		cin >> query[i].f1.f1 >> query[i].f1.s2, query[i].s2 = i;

	sort(query, query + q, [](pair<ii, int> const &x, pair<ii, int> const &y){
		return x.f1.s2 < y.f1.s2 || (x.f1.s2 == y.f1.s2 && x.f1.f1 < y.f1.f1);
	});

	for (int i = 0, j = 1; i < q; ++i)
	{
		for (; j <= query[i].f1.s2; ++j)
		{
			if (pos[ar[j]] != -1)
			{
				add(pos[ar[j]], 1);
			}
			pos[ar[j]] = j;
		}

		res[query[i].s2] = (query[i].f1.s2 - query[i].f1.f1 + 1) - (sum(query[i].f1.s2) - sum(query[i].f1.f1 - 1)); 
	}

	for (int i = 0; i < q; ++i)
		cout << res[i] << '\n';

	return 0;
}