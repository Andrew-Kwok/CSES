#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> Z(N, 0);
	for (int j = 0; j < 10; ++j)
	{
		string ask(N, '0');
		for (int i = 1; i <= N; ++i) if (i >> j & 1)
			ask[i-1] = '1';

		cout << "? " << ask << endl;
		
		string s; cin >> s;
		for (int i = 0; i < N; ++i) if (s[i] == '1')
			Z[i] ^= (1 << j);
	}

	cout << "!";
	for (int i = 0; i < N; ++i)
		cout << " " << Z[i];
	cout << endl;

	return 0;
}