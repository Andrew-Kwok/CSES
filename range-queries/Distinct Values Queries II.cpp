#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAX = 1 << 18;

int st[2 * MAX];
inline void modify(int p, int val)
{
	for (st[p += MAX] = val; p > 1; p >>= 1)
		st[p >> 1] = min(st[p], st[p^1]);
}

inline int query(int l, int r)
{
	int Z = MAX;
	for (l += MAX, r += MAX+1; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1) Z = min(Z, st[l++]);
		if (r & 1) Z = min(Z, st[--r]);
	}
	return Z;
}

int N, Q, X[MAX];
set<int> pts[2*MAX];
multiset<int> mst[MAX];

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	memset(st, 0x3f, sizeof(st));


	vector<int> zv;

	cin >> N >> Q;
	for (int i = 0; i < N; ++i)
		cin >> X[i], zv.pb(X[i]);

	vector<array<int, 3>> qry(Q);
	for (auto &[t, a, b] : qry)
	{
		cin >> t >> a >> b;

		--a; 
		if (t == 1) zv.pb(b);
		else --b;
	}

	sort(zv.begin(), zv.end());
	zv.resize(unique(zv.begin(), zv.end()) - zv.begin());

	const auto zip = [&](int x) -> int
	{
		return (int)(lower_bound(zv.begin(), zv.end(), x) - zv.begin());
	};

	for (int i = 0; i < N; ++i)
		X[i] = zip(X[i]);
	for (auto &[t, a, b] : qry) if (t == 1)
		b = zip(b);
	
	// cerr << "X: ";
	// for (int i = 0; i < N; ++i)
	// 	cerr << X[i] << ", ";
	// cerr << '\n';

	for (int i = 0; i < N; ++i)
		pts[X[i]].insert(i);
	for (int p = 0; p < 2*MAX; ++p) if (pts[p].size() >= 2)
	{
		for (auto it = pts[p].begin(), itn = next(it); itn != pts[p].end(); ++it, ++itn)
			mst[*it].insert(*itn);
	}

	for (int i = 0; i < N; ++i) if (!mst[i].empty())
	{
		modify(i, *mst[i].begin());
	}

	for (auto &[t, a, b] : qry)
	{
		// for (int p = 0; p < 2*MAX; ++p) if (!pts[p].empty())
		// {
		// 	cerr << zv[p] << " -> ";
		// 	for (int x : pts[p])
		// 		cerr << x << ", ";
		// 	cerr << '\n';
		// }

		// for (int i = 0; i < N; ++i) if (!mst[i].empty())
		// {
		// 	cerr << i << " has " << *mst[i].begin() << '\n'; 
		// }

		if (t == 1)
		{
			// remove pts[X[a]] = b
			{
				auto it = pts[X[a]].lower_bound(a);
				if (it != pts[X[a]].begin())
				{
					mst[*prev(it)].erase(mst[*prev(it)].lower_bound(*it));
					
					if (!mst[*prev(it)].empty())
						modify(*prev(it), *mst[*prev(it)].begin());
					else modify(*prev(it), MAX);
				}
				if (next(it) != pts[X[a]].end())
				{
					mst[*it].erase(mst[*it].lower_bound(*next(it)));
					if (!mst[*it].empty())
						modify(*it, *mst[*it].begin());
					else modify(*it, MAX);
				}

				pts[X[a]].erase(a);
			}

			// set X[a] = b
			X[a] = b;
			{
				auto it = pts[b].lower_bound(a);
				if (it != pts[b].begin() && it != pts[b].end())
					mst[*prev(it)].erase(*it);

				if (it != pts[b].begin())
				{
					mst[*prev(it)].insert(a);
					modify(*prev(it), *mst[*prev(it)].begin());
				}

				if (it != pts[b].end())
				{
					mst[a].insert(*it);
					modify(a, *mst[a].begin());
				}

				pts[X[a]].insert(a);
			}
		}
		else
		{
			// cerr << a << " " << b << " -> " << query(a, b) << '\n';
			if (query(a, b) > b) cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;
}