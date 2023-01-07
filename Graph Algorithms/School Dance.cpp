#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define pb push_back

const int MAX = 569;

int n, m, k;
vector<int> adj[2 * MAX];

int match[2 * MAX];
bool vst[2 * MAX];

inline bool bpm(int node)
{
	for (int to : adj[node])
	{
		if (vst[to])
			continue;
		vst[to] = true;

		if (match[to] == -1 || bpm(match[to]))
		{
			match[to] = node;
			return true;
		}
	}
	return false;
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i)
	{
		int a, b; cin >> a >> b;
		b += MAX;

		adj[a].pb(b); adj[b].pb(a);
	}

	int res = 0;	
	memset(match, -1, sizeof(match));
	for (int i = 1; i <= n; ++i)
	{
		memset(vst, false, sizeof(vst));
		res += bpm(i);
	}

	cout << res << '\n';
	for (int i = 1; i <= m; ++i)
		if (match[i + MAX] != -1)
			cout << match[i + MAX] << " " << i << '\n';

	return 0;
}