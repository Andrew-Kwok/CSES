#include <bits/stdc++.h>
using namespace std;

#define pb push_back

void solve()
{
	int N, A, B;
	cin >> N >> A >> B;

	int draw = N - A - B;
	vector<int> va, vb;

	if (A+B > N || (A+B > 0 && (A == 0 || B == 0))) {
		goto no;
	}

	for (int i = 1; i <= draw; ++i)
		va.pb(N-i+1), vb.pb(N-i+1);

	for (int i = 1; i <= A; ++i)
		va.pb(i+B), vb.pb(i);
	for (int i = 1; i <= B; ++i)
		va.pb(i), vb.pb(i+A);

	cout << "YES\n";
	for (int x : va)
		cout << x << " ";
	cout << '\n';
	for (int x : vb)
		cout << x << " ";
	cout << '\n';

	return;

no:
	cout << "NO\n";
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	int tc; cin >> tc;
	while (tc--)
	{
		solve();
	}

	return 0;
}