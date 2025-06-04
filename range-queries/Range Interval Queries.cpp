#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f1 first
#define s2 second

using ii = pair<int, int>;


const int MAX = 1 << 18;

int bit[MAX];
inline void add(int x, int val)
{
	for (x++; x < MAX; x += (x & -x))
		bit[x] += val;
}

inline int sum(int x)
{
	int Z = 0;
	for (x++; x > 0; x -= (x & -x))
		Z += bit[x];
	return Z;
}

int N, Q, X[MAX], Z[MAX];

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> Q;
	for (int i = 1; i <= N; ++i)
		cin >> X[i];

	vector<int> zv;
	for (int i = 1; i <= N; ++i)
		zv.pb(X[i]);

	vector<array<int, 4>> query;
	for (int i = 1; i <= Q; ++i)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d; --c;
		
		zv.pb(c); zv.pb(d);
		query.pb({a, b, c, -i});
		query.pb({a, b, d, i});
	}
	sort(zv.begin(), zv.end());
	zv.resize(unique(zv.begin(), zv.end()) - zv.begin());

	const auto zip = [&](int x) -> int
	{
		return (int)(lower_bound(zv.begin(), zv.end(), x) - zv.begin());
	};

	for (int i = 1; i <= N; ++i)
		X[i] = zip(X[i]);
	for (auto &[a, b, c, i] : query) {
		c = zip(c);
	}

	sort(query.begin(), query.end(), [](auto x, auto y){
		return x[2] < y[2];
	});

	vector<ii> v;
	for (int i = 1; i <= N; ++i)
	{
		v.pb({X[i], i});
	}
	sort(v.begin(), v.end());


	int j = 0;
	for (auto &[a, b, c, i] : query)
	{
		while (j < N && v[j].f1 <= c)
			add(v[j++].s2, 1);

		if (i > 0) Z[i] += sum(b) - sum(a-1);
		else Z[-i] -= sum(b) - sum(a-1);
	}

	for (int i = 1; i <= Q; ++i)
		cout << Z[i] << '\n';

	return 0;
}