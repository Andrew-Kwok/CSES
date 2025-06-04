#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAX = 1 << 18;

int ds[MAX];
inline int frep(int x) { return ds[x] < 0? x : ds[x] = frep(ds[x]); }
inline void join(int x, int y)
{
	x = frep(x); y = frep(y);
	if (x == y)
		return;
	ds[x] += ds[y];
	ds[y] = x;
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	memset(ds, -1, sizeof(ds));

	int N;
	cin >> N;

	vector<array<int, 3>> edge(N-1);
	for (auto &[w, u, v] : edge)
		cin >> u >> v >> w;
	sort(edge.rbegin(), edge.rend());

	ll Z = 0;
	for (auto &[w, u, v] : edge)
	{
		Z += 1ll * w * ds[frep(u)] * ds[frep(v)];
		join(u, v);
	}

	cout << Z << '\n';
	return 0;
}