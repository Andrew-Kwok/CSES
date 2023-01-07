#include <iostream>
#include <array>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define pb push_back

const int MAX = 4e5 + 69;

int bit[MAX];
inline void add(int x, int val)
{
	for (int i = x+1; i < MAX; i += (i & -i))
		bit[i] += val;
}

inline int sum(int x)
{
	int res = 0;
	for (int i = x+1; i > 0; i -= (i & -i))
		res += bit[i];
	return res;
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<array<int, 3>> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i][0] >> v[i][1], v[i][2] = i;

	{
		vector<int> comp;
		for (const auto &[l, r, id] : v)
			comp.pb(l), comp.pb(r);
		sort(comp.begin(), comp.end());
		comp.resize(unique(comp.begin(), comp.end()) - comp.begin());

		for (auto &[l, r, id] : v)
		{
			l = (int)(lower_bound(comp.begin(), comp.end(), l) - comp.begin());
			r = (int)(lower_bound(comp.begin(), comp.end(), r) - comp.begin());
		}
	}

	vector<int> in(n, 0);  // how many range range x contain 
	vector<int> out(n, 0); // how many other range contains range x

	{
		memset(bit, 0, sizeof(bit));
		sort(v.begin(), v.end(), [](const auto &x, const auto &y){
			return x[1] < y[1] || (x[1] == y[1] && x[0] > y[0]);
		});

		for (const auto &[l, r, id] : v)
		{
			in[id] = sum(r) - sum(l-1);
			add(l, 1);
		}
	}

	{
		memset(bit, 0, sizeof(bit));
		sort(v.begin(), v.end(), [](const auto &x, const auto &y){
			return x[0] < y[0] || (x[0] == y[0] && x[1] > y[1]);
		});

		int sz = 0;
		for (const auto &[l, r, id] : v)
		{
			out[id] = sz++ - sum(r-1);
			add(r, 1);
		}
	}

	for (int x : in)
		cout << x << " ";
	cout << '\n';
	for (int x : out)
		cout << x << " ";
	cout << '\n';

	return 0;
}