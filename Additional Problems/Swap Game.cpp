#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define f1 first
#define s2 second

const int N = 9;
const int inf = 1e9 + 69;
const int a[] = { 0, 1, 2, 3, 4, 5, 0, 3, 6, 1, 4, 7 };
const int b[] = { 3, 4, 5, 6, 7, 8, 1, 4, 7, 2, 5, 8 };

int pwr[10];
const auto move(int mask, int i, int j)
{
	int x = mask % pwr[i+1] / pwr[i];
	int y = mask % pwr[j+1] / pwr[j];
	return mask - x * pwr[i] - y * pwr[j] + x * pwr[j] + y * pwr[i];
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	pwr[0] = 1;
	for (int i = 1; i < 10; ++i)
		pwr[i] = 9 * pwr[i-1];

	int cur = 0, fin = 0;
	for (int i = 0, x; i < 9; ++i)
	{
		cin >> x;
		cur += (x-1) * pwr[i];
		fin += i * pwr[i];
	}

	queue<ii> q;
	vector<bool> vst(pwr[9], 0);

	vst[cur] = true;
	q.push({cur, 0});

	while (!q.empty())
	{
		auto [node, dist] = q.front(); q.pop();
		if (node == fin)
		{
			cout << dist << '\n';
			break;
		}

		for (int i = 0; i < 12; ++i)
		{
			int to = move(node, a[i], b[i]);
			if (!vst[to])
			{
				vst[to] = true;
				q.push({to, dist + 1});
			}
		}
	}

	return 0;
}