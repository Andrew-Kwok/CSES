#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	int l = 1, r = 1e9;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		cout << "? " << mid << endl;

		string s; cin >> s;
		if (s == "YES") l = mid + 1;
		else r = mid;
	}	
	cout << "! " << l << endl;

	return 0;
}