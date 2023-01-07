#include <iostream>
#include <vector>
#include <array>
#include <cstring>
#include <algorithm>
using namespace std;

#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define f1 first
#define s2 second

constexpr int MAX = 1e5 + 69;

int len;
char s[MAX];
int suffix_array[MAX];

vector<array<int, 3>> fq[MAX];
inline void counting_sort(vector<array<int, 3>> &v)
{
	int sz = (int)v.size();
 
	for (int j = 1; j >= 0; --j)
	{
		int mx = 0;
		for (int i = 0; i < sz; ++i)
		{
			fq[v[i][j]].pb(v[i]);
			mx = max(mx, v[i][j]);
		}
		v.clear();
 
		for (int i = 1; i <= mx; ++i)
		{
			for (auto x : fq[i])
				v.pb(x);
			fq[i].clear();
		}
	}
}

void build_suffix_array()
{
	vector<int> ranks(len);
	{
		ranks[len-1] = 1;

		int C[26] = {};
		for (int i = 0; i < len-1; ++i)
			C[s[i] - 'a'] = 1;
		for (int i = 1; i < 26; ++i)
			C[i] += C[i-1];
		for (int i = 0; i < len-1; ++i)
			ranks[i] = 1 + C[s[i] - 'a'];
	}

	vector<array<int, 3>> v(len);
	for (int jump = 1; jump < len; jump <<= 1)
	{
		for (int i = 0; i < len; ++i)
			v[i] = {ranks[i], i + jump < len ? ranks[i + jump] : 0, i};
		counting_sort(v);

		for (int i = 0, ctr = 1; i < len; ++i)
		{
			if (i) ctr += mp(v[i][0], v[i][1]) != mp(v[i-1][0], v[i-1][1]);
			ranks[v[i][2]] = ctr;
		}
	}

	vector<ii> tmp;
	for (int i = 0; i < len; ++i)
		tmp.pb({ranks[i], i});
	sort(tmp.begin(), tmp.end());

	for (int i = 0; i < len; ++i)
		suffix_array[i] = tmp[i].s2;
}

inline int solve(const string &k)
{
	int p = 1, q = len - 1;
	for (int i = 0; i < (int)k.size(); ++i)
	{
		{
			int idp = suffix_array[p], idq = suffix_array[q];
			if (s[idp + i] > k[i] || s[idq + i] < k[i])
				return 0;
		}

		{ // lower bound
			int l = p, r = q;
			while (l < r)
			{
				int mid = (l + r) >> 1;
				int id = suffix_array[mid];

				if (s[id + i] < k[i]) l = mid + 1;
				else r = mid;
			}
			p = l;
		}
		{ // upper bound
			int l = p, r = q;
			while (l < r)
			{
				int mid = (l + r + 1) >> 1;
				int id = suffix_array[mid];

				if (s[id + i] > k[i]) r = mid - 1;
				else l = mid;
			}
			q = l;
		}
	}

	return q - p + 1;
}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> s;

	len = (int)strlen(s);
	s[len++] = '$';
	build_suffix_array();

	int q;
	cin >> q;

	while (q--)
	{
		string k;
		cin >> k;

		cout << solve(k) << '\n';
	}

	return 0;
}