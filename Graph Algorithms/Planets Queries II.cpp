#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf = 1e9 + 69;
const int MAX = 2e5 + 69;
const int LG = 18;

int n;
int to[MAX], ind[MAX] = {}, depth[MAX];
int up[MAX][LG];
bool vst[MAX] = {};

int ds[MAX], pos[MAX];
inline int frep(int x) { return ds[x] < 0 ? x : ds[x] = frep(ds[x]); }
inline void join(int x, int y)
{
	x = frep(x); y = frep(y);
	if (x == y)
		return;
	ds[x] += ds[y];
	ds[y] = x;
}

void precompute()
{
	queue<int> q;
	for (int i = 1; i <= n; ++i)
	{
		if (ind[i] == 0)
		{
			q.push(i);
			depth[i] = 0;
		}
	}

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		vst[node] = true;
		depth[to[node]] = max(depth[to[node]], depth[node] + 1);

		ind[to[node]]--;
		if (ind[to[node]] == 0)
			q.push(to[node]);
	}

	for (int i = 1; i <= n; ++i)
	{
		if (vst[i])
			up[i][0] = to[i];
		else up[i][0] = i, join(i, to[i]), depth[i] = inf;
	}


	for (int j = 1; j < LG; ++j)
		for (int i = 1; i <= n; ++i)
			up[i][j] = up[up[i][j-1]][j-1];


	for (int i = 1; i <= n; ++i)
	{
		if (!vst[i])
		{
			for (int cur = i, ctr = 0; !vst[cur]; vst[cur] = true, cur = to[cur])
				pos[cur] = ctr++;
		}
	}
}

int get(int node, int x)
{
	for (int i = LG-1; i >= 0; --i)
	{
		if (x >> i & 1)
			node = up[node][i];
	}
	return node;
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(ds, -1, sizeof(ds));
	memset(pos, -1, sizeof(pos));
	memset(depth, -1, sizeof(depth));

	int q;
	cin >> n >> q;

	for (int i = 1; i <= n; ++i)
		cin >> to[i], ind[to[i]]++;

	precompute();
	while (q--)
	{
		int u, v;
		cin >> u >> v;

		int l = 0, r = n;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			int dest = get(u, mid);

			if (depth[dest] >= depth[v]) r = mid;
			else l = mid + 1;
		}
		int dest = get(u, l);

		if (frep(dest) != frep(v))
		{
			cout << -1 << '\n';
		}
		else if (dest == v)
		{
			cout << l << '\n';
		}
		else
		{
			int sz = -ds[frep(v)];
			cout << l + (pos[v] - pos[dest] + sz) % sz << '\n';
		}
	}

	return 0;
}