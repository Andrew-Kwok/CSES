#include <bits/stdc++.h>
using namespace std;

#define pb push_back

using ii = pair<int, int>;

const int MAX = 1 << 18;

int N;
int ar[MAX], sfx[MAX], ds[MAX], Z[MAX];
set<int> cc[MAX];

inline int frep(int x) { return ds[x] == x ? x : ds[x] = frep(ds[x]); }
inline void join(int x, int y)
{
	x = frep(x); y = frep(y);
	if (x == y)
		return;
	if (cc[x].size() < cc[y].size())
		swap(x, y);
	for (int v : cc[y])
		cc[x].insert(v);
	ds[y] = x;
}

int clr[MAX];
vector<int> adj[MAX];
inline void dfs(int node)
{
	for (int to : adj[node])
	{
		if (clr[to] == -1)
		{
			clr[to] = 1 - clr[node];
			dfs(to);
		}
	}
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> ar[i];

	sfx[N] = ar[N];
	for (int i = N-1; i >= 1; --i)
		sfx[i] = min(ar[i], sfx[i+1]);

	set<int> st;
	iota(ds, ds+MAX, 0);
	for (int i = 1; i <= N; ++i)
		cc[i].insert(i);

	for (int i = 1; i+1 <= N; ++i)
	{
		while (!st.empty() && *st.begin() <= sfx[i+1])
		{
			int h = frep(*st.begin());
			assert(cc[h].count(*st.begin()));

			st.erase(st.begin());
			auto it = cc[h].upper_bound(sfx[i+1]);
			if (it != cc[h].end())
				st.insert(*it);
		}

		if (st.empty() || *st.begin() > ar[i])
		{
			if (ar[i] > sfx[i+1])
				st.insert(ar[i]);
		}
		else
		{
			while (!st.empty() && *st.begin() < ar[i])
			{
				adj[*st.begin()].pb(ar[i]);
				adj[ar[i]].pb(*st.begin());

				join(*st.begin(), ar[i]);
				st.erase(st.begin());
			}

			int h = frep(ar[i]);
			auto it = cc[h].upper_bound(sfx[i+1]);
			if (it != cc[h].end())
				st.insert(*it);
		}
	}

	memset(clr, -1, sizeof(clr));
	for (int i = 1; i <= N; ++i) if (clr[i] == -1)
	{
		clr[i] = 0;
		dfs(i);
	}

	int cur = 1;
	vector<int> sk[2];
	for (int i = 1; i <= N; ++i)
	{
		Z[i] = clr[ar[i]];
		sk[Z[i]].pb(ar[i]);

		while ((!sk[0].empty() && cur == sk[0].back()) || (!sk[1].empty() && cur == sk[1].back()))
		{
			if (!sk[0].empty() && cur == sk[0].back()) sk[0].pop_back();
			else sk[1].pop_back();
			cur++;
		}
	}

	if (cur <= N)
	{
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	// cout << "POSSIBLE\n";
	for (int i = 1; i <= N; ++i)
	{
		cout << Z[i]+1 << " \n"[i == N];
	}

	return 0;
}