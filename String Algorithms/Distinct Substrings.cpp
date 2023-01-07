#include <iostream>
#include <vector>
#include <array>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define f1 first
#define s2 second

constexpr int MAX = 1e5 + 69;
constexpr int LG = 17;

int LOG[MAX];
struct sparse_table
{
	int n;
	int st[MAX][LG];
	function<int(int, int)> comp;
	sparse_table() {}
	sparse_table(int _n, int ar[], function<int(int, int)> _comp) : n(_n), comp(_comp)
	{
		for (int i = 0; i < n; ++i)
			st[i][0] = ar[i];
		for (int j = 1; j < LG; ++j)
			for (int i = 0; i + (1 << j) - 1 <= n; ++i)
				st[i][j] = comp(st[i][j-1], st[i + (1 << (j-1))][j-1]);
	}

	inline int query(int l, int r)
	{
		int j = LOG[r - l + 1];
		return comp(st[l][j], st[r - (1 << j) + 1][j]);
	}

} sparse;

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

int lcp[MAX] = {};
void kasai()
{
	int invSuff[MAX];
	for (int i = 0; i < len; ++i)
		invSuff[suffix_array[i]] = i;

	for (int i = 0, k = 0; i < len; ++i)
	{
		if (invSuff[i] == len-1)
		{
			k = 0;
			continue;
		}

		int j = suffix_array[invSuff[i] + 1];

		while (i+k < len && j+k < len && s[i+k] == s[j+k])
			k++;

		lcp[invSuff[i]] = k;
		if (k > 0)
			k--;
	}

}

int main()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	LOG[1] = 0;
	for (int i = 2; i < MAX; ++i)
		LOG[i] = 1 + LOG[i/2];

	cin >> s;

	len = (int)strlen(s);
	s[len++] = '$';
	build_suffix_array();
	kasai();

	ll res = len - suffix_array[0];
	for (int i = 1; i < len; ++i)
		res += (len - suffix_array[i]) - lcp[i-1];

	cout << res - len << '\n';
	return 0;
}