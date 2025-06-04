#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<string> v(N);
	for (string &x : v)
		cin >> x;

	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < M; ++j)
		{
			vector<char> c = {'A', 'B'};
			if ((i+j) & 1) c = {'C', 'D'};

			for (auto ch : c) if (ch != v[i][j])
			{
				cout << ch;
				break;
			}
		}
		cout << '\n';
	}

	return 0;
}