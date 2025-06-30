#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> v = {1};
	for (int i = 2; i <= N; ++i)
	{
		int l = 0, r = i-1;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			cout << "? " << v[mid] << " " << i << endl;

			string s; cin >> s;
			if (s == "YES") l = mid + 1;
			else r = mid;
		}
		v.insert(v.begin() + l, i);
	}

	vector<int> Z(N+1);
	for (int i = 1; i <= N; ++i)
		Z[v[i-1]] = i;

	cout << "!";
	for (int i = 1; i <= N; ++i)
		cout << " " << Z[i];
	cout << endl;

	return 0;
}