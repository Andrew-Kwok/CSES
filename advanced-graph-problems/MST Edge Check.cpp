#include <bits/stdc++.h>
using namespace std;

const int MAX = 1 << 17;

int ds[MAX];
inline int frep(int x) { return ds[x] == x ? x : ds[x] = frep(ds[x]); }
inline void join(int x, int y) { ds[frep(x)] = frep(y); }

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	iota(ds, ds + MAX, 0);

	int N, M;
	cin >> N >> M;

	map<int, vector<array<int, 3>>> edge;
	for (int i = 0; i < M; ++i)
	{
		int u, v, w; cin >> u >> v >> w;
		edge[w].push_back({u, v, i});
	}

	vector<bool> Z(M, false);
	for (auto &[w, e] : edge)
	{
		for (auto &[u, v, i] : e) if (frep(u) != frep(v))
			Z[i] = true;

		for (auto &[u, v, i] : e)
			join(u, v);
	}

	for (int i = 0; i < M; ++i)
	{
		if (Z[i]) cout << "YES\n";
		else cout << "NO\n";
	}



	return 0;
}