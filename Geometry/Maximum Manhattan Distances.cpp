#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int a = INT_MAX, b = INT_MIN, c = INT_MAX, d = INT_MIN;
	for (int i = 0; i < N; ++i)
	{
		int x, y; cin >> x >> y;
		a = min(a, x+y);
		b = max(b, x+y);
		c = min(c, x-y);
		d = max(d, x-y);
	
		cout << max((ll)b-a, (ll)d-c) << '\n';
	}


	return 0;
}