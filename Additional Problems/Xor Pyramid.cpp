#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAX = 2e5 + 69;

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int &x : v)
		cin >> x;

	int k = n-1;
	for (int i = 20; i >= 0; --i)
	{
		if (k >> i & 1)
		{
			vector<int> nv;
			for (int j = 0; j + (1 << i) < (int)v.size(); ++j)
				nv.pb(v[j] ^ v[j + (1 << i)]);
			v = nv;
		}
	}
	cout << v[0] << '\n';


	return 0;
}