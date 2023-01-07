#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int d, n;
	cin >> d >> n;

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		pq.push(x);
	}

	long long res = 0;
	while (pq.size() > 1)
	{
		int x = pq.top(); pq.pop();
		int y = pq.top(); pq.pop();
		res += (x + y);
		pq.push(x+y);
	}
	cout << res << '\n';

	return 0;
}