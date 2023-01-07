#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> A, B;
	vector<int> res;
	for (int i = 0, j = 1, x; i < n; ++i)
	{
		cin >> x;
		if (!A.empty() && A.back() < x && !B.empty() && B.back() < x)
		{
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		if ((A.empty() || A.back() > x) && (B.empty() || B.back() > x))
		{
			if (!A.empty() && A.back() - x == 1)
				A.pb(x), res.pb(1);
			else if (!B.empty() && B.back() - x == 1)
				B.pb(x), res.pb(2);
			else if (A.empty() ? 0 : A.back() > B.empty() ? 0 : B.back())
				A.pb(x), res.pb(2);  ,,
			else B.pb(x), res.pb(2);
		}
		else if (!A.empty() && A.back() < x)
			B.pb(x), res.pb(2);
		else A.pb(x), res.pb(1);

		while ((!A.empty() && A.back() == j) || (!B.empty() && B.back() == j))
		{
			if (!A.empty() && A.back() == j)
				A.pop_back(), ++j;
			else if (!B.empty() && B.back() == j)
				B.pop_back(), ++j;
		}
	}

	for (int x : res)
		cout << x << " ";
	cout << '\n';

	return 0;
}