#include <iostream>
#include <vector>
using namespace std;

#define pb push_back

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int mod = (1 << n) - 1;

	string res = "";
	vector<bool> used(1 << n, false);
	const auto rc = [&](const auto &self, int cur) -> void
	{
		used[cur] = true;
		res.pb((char)('0' + (cur&1)));
		if (res.size() == used.size())
		{
			cout << string(n-1, '0') << res << '\n';
			exit(0);
		}
		if (!used[cur << 1 & mod])
			self(self, cur << 1 & mod);
		if (!used[(cur << 1 | 1) & mod])
			self(self, (cur << 1 | 1) & mod);

		used[cur] = false;
		res.pop_back();
		return;
	};

	rc(rc, 0);
	rc(rc, 1);
	return 0;
}